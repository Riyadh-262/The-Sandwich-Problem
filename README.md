# 🥪 Junior–Senior Sandwich Problem (C, pthreads, semaphores)

This project is a simulation of a classic synchronization problem implemented in **C** using  
**POSIX threads (pthreads)** and **semaphores**.  

The scenario involves:

- **One Senior**, who has unlimited ingredients  
- **Three Juniors**, each with **one fixed ingredient**  
- The Senior places **two ingredients**, and the junior with the missing ingredient makes the sandwich  
- This continues until **10 sandwiches** are prepared  

The purpose of this project is to demonstrate:
- Thread synchronization  
- Semaphore-based coordination  
- Avoiding race conditions  
- Producer–consumer–style problem solving  

---

## 🚀 Features

- ✔️ Uses **pthreads** for multithreading  
- ✔️ Uses **semaphores** for synchronization  
- ✔️ Avoids race conditions using controlled access  
- ✔️ Simulates real-life distributed work using threads  
- ✔️ Random ingredient placement by senior  
- ✔️ Ends after 10 sandwiches are made  

---

## 🧠 Problem Explanation

Each Junior has **one ingredient**:

| Thread     | Owns        |
|------------|-------------|
| Junior 1   | Bread       |
| Junior 2   | Sausage     |
| Junior 3   | Cheese      |

The Senior places **two ingredients** each round:

- If Senior places **Sausage + Cheese** → Junior 1 completes the sandwich  
- If Senior places **Bread + Cheese** → Junior 2 completes the sandwich  
- If Senior places **Bread + Sausage** → Junior 3 completes the sandwich  

A semaphore (`sen`) ensures the senior acts only when allowed,  
and sem1/sem2/sem3 awaken the correct junior.

---

## 📁 File Structure


## 🧵 Thread Overview

- `senior` → decides which two ingredients to place  
- `junior1` → awakened when Senior places sausage + cheese  
- `junior2` → awakened when Senior places bread + cheese  
- `junior3` → awakened when Senior places bread + sausage  

Each junior:
- Awaits its own semaphore (`sem1`, `sem2`, `sem3`)
- Makes the sandwich  
- Eats  
- Prints total sandwiches made  
- Signals senior to continue  

---

## 🔧 How to Compile & Run

### **Compile**

```bash
gcc sandwich.c -o sandwich -lpthread

Hi, I am Senior
I have unlimited supply of breads, sausages and cheeses

Hi, I am Junior1
I have Bread

Senior: I placing sausage and cheese
junior1: I have Bread
sandwich is Ready to eat
Junior1 is Eating sandwich.
Total Sandwich eaten: 1

