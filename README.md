# CS-200
Course Assignments (Introduction to Programming - C/C++)

## Assignment 1
Implemented the Nokia Snakes game in C/C++ using the nucrses library.

**Usage:**  
```
> g++ -o snake snake.cpp -lcurses
> ./snake
```

## Assignment 2
Implemented a Mathematics library, including functions such as Combinatorics, Vector Arithmetic, Geometry, Statistics, and 
Matrix Arithmetic. All functions in Assignment2.h have been implemented (except Task 8 - matrixDet() and matrixInv()). Testing 
has been done in main.cpp.

**Usage:**  
add all files to your working directory and the following line near the top of file that requires library 
```
#include "Assignment2.h
```

## Assignment 3
Implemented a C-String library, including comparison, copy, find substring, concatenation, tokenizer, string sorting.

**Usage:**  
add all files to your working directory and the following line near the top of file that requires library 
```
#include "Assignment3.h
```

## Assignment 4
Composed of 2 tasks.  
Task 1) Recover lost files from a file that was accidentally formatted.  
Task 2) Recover a file by smartly reading from 8 bitmap files.

**Usage:**  
Task 1
```
> g++ -o Task1 Task1.cpp
> ./Task1
```
Task 2
```
> g++ -o Task2 Task2.cpp
> ./Task2
```

## Assignment 5
An assignment that was more of a programming competition.

## Assignment 6
I implemented an event schedular program where a user can add events to his calendar. Error checking and 
validations have been added so you do not have simultaneous events, invalid input, etc.

**Usage:**  
add all the following files to your folder and then run the following commands  
```
> make -f Assignment6.make
> ./Assignment6
```
