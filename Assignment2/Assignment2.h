#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

// Task 1 - Combinatorics
int fact(int n);
int perm(int n, int r);
int comb(int n, int r);

// Task 2 - Vector Algebra
float magnitude(float vec[], int n);
float dot(float vec1[], float vec2[], int n);
float angle(float vec1[], float vec2[], int n);
void normalize(float vec[], int n);
void cross(float result[3], float vec1[3], float vec2[3]);

// Task 3 - Geometry
bool intersect(float l1[2][2], float l2[2][2]);
float area_overlap(float rect1[4], float rect2[4]);
float polygon_area(float arrX[], float arrY[], int n);

// Task 4 - Sorting
void bubbleSort(int arr[], int n);

// Task 5 - Statistics
float mean(float arr[], int n);
float stdev(float arr[], int n);
float pctile(float arr[], int n, float p);
float error(float arrX[], float arrY[], int n, float m, float c);
void lsq_fit(float arrX[], float arrY[], int n, float &m, float &c);

// Task 6 - Matrix Arithmetic 1
void matrixTranspose(float mat[], int n);
void matrixMulSquare(float res[], float mat1[], float mat2[], int n);
void transform(float mat[], float vec[], int n);
void matrixMul(float res[], float mat1[], float mat2[], int m, int n, int p);

// Task 7 - Simple Games
void IGame(bool arr[], int turnR[], int turnC[], int n, int nTurns);
void KGame(bool arr[], int turnR[], int turnC[], int n, int nTurns);

// Task 8 - Matrix Arithmetic 2 (Hacker's Edition)
float matrixDet(float mat[], int n);
void matrixInv(float mat[], int n);

// Task 9 - Searching (Hacker's Edition)
int unique(int arr[], int n);

#endif
