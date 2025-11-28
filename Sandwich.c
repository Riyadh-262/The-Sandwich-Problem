#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>


sem_t sem1;
sem_t sem2;
sem_t sem3;
sem_t sen;

int count=0;

void intSemaphore()
{
    sem_init(&sem1,0,0);
    sem_init(&sem2,0,0);
    sem_init(&sem3,0,0);
    sem_init(&sen,0,1);
}
void *junior1(void *arg)
{
    printf("Hi, I am Junior1\n");
    printf("I have Bread\n\n");
    while(count!=10)
    {
        sem_wait(&sem1);
        printf("junior1: I have Bread\n");
        sleep(1);
        printf("sandwich is Ready to eat\n");
        sleep(1);
        printf("Junior1 is Eating sandwich.\n");
        printf("\nTotal Sandwich eaten: %d  \n",count);
        sem_post(&sen);
    }
}
void *junior2(void *arg)
{
    printf("HI,I am Junior2\n");
    printf("I have Sausage\n\n");
    while(count!=10)
    {
        sem_wait(&sem2);
        printf("Junior2:I have Sausage\n");
        sleep(1);
        printf("Sandwich is Ready to eat\n");
        sleep(1);
        printf("Junior2 is Eating sandwich.\n");
        printf("\nTotal Sandwich eaten :%d\n",count);
        sem_post(&sen);
    }
}
void *junior3(void*arg)
{
    printf("Hi,I am Junior3\n");
    printf("I have Cheese\n\n");
    while(count!=10)
    {
        sem_wait(&sem3);
        printf("Junior3:I have cheese\n");
        sleep(1);
        printf("Sandwich is Ready to eat\n");
        sleep(1);
        printf("Junior3 is Eating sandwich.\n");
        printf("\nTotal Sandwich eaten : %d\n",count);
        sem_post(&sen);
    }
}
void *senior(void *arg)
{
    printf("Hi, I am senior\n");
    printf("I have unlimited supply of breads,sausages and cheeses\n\n");
    while(count!=10)
    {
        sem_wait(&sen);
        sleep(1);

        int flag =(rand()%(3-1+1))+1;
        if(flag==1)
        {
            printf("\nSenior: I am placing sausage and cheese\n");
            sem_post(&sem1);
        }
        else if(flag==2)
        {
            printf("\nSenior: I placing Bread and Cheese\n");
            sem_post(&sem2);
        }
        else if(flag==3)
        {
            printf("\nsenior: I placing Bread and Sausage\n");
            sem_post(&sem3);
        }
        count++;
    }
}
int main()
{
    intSemaphore();
    pthread_t s1,j1,j2,j3;
    pthread_create(&s1,NULL,senior,NULL);
    pthread_create(&j1,NULL,junior1,NULL);
    pthread_create(&j2,NULL,junior2,NULL);
    pthread_create(&j3,NULL,junior3,NULL);
    pthread_join(s1,NULL);
    pthread_join(j1,NULL);
    pthread_join(j2,NULL);
    pthread_join(j3,NULL);

    return 0;
}
