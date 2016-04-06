#include "Assignment2.h"

//////////////////////////////////TRANSPOSE OF A VECTOR/////////////////////////////////////////////////

void matrixTranspose(float mat[], int n)	//To find an index for ith row and jth column we use
{											//index=n*(i-1)+j-1. Where n is the number of elements
	int index, index1;						//in a row. Simply swap values.
	float temp;

	for(int i=1; i<=n; i++)
	{
		for(int j=n; j>i; j--)
		{
			index = n*(i-1)+j-1;
			index1 = n*(j-1)+i-1;
			temp = mat[index];
			mat[index] = mat[index1];
			mat[index1] = temp;
		}
	}
}

///////////////////////////////////MULTIPLICATION OF TWO SQUARE MATRICES////////////////////////////////

void matrixMulSquare(float res[], float mat1[], float mat2[], int n)	//Calling the matrix multiplication function.
{
	matrixMul(res, mat1, mat2, n, n, n);
}

///////////////////////////////////TRANSFORMATION OF A VECTOR///////////////////////////////////////////

void transform(float mat[], float vec[], int n)		//Making a new dynamic array. Then calling the
{													//matrix multiplication function with the new
	float* resultArray = new float[n];				//dynamic array as the result. Then just making
	matrixMul(resultArray, mat, vec, n, n, 1);		//"vec" values equal to the dynamic array values.

	for(int i=0; i<n; i++)
	{
		vec[i]=resultArray[i];
	}
	delete resultArray;
}

/////////////////////////////////MULITPLICATION OF TWO MATRICES/////////////////////////////////////////////

void matrixMul(float res[], float mat1[], float mat2[], int m, int n, int p)	//Doing matrix multiplication
{																				//and storing in a result array.
	int indexRes=0, index1=0, index2=0;											//i relates to the rows in res[] and mat1[].
	for(int i=1; i<=m; i++)														//j relates to the columns in res[] and mat2[].
	{																			//k relates to the columns in mat1
		for(int j=1; j<=p; j++)													//and the rows in mat2.
		{
			indexRes = p*(i-1) + j - 1;

			for(int k=1; k<=n; k++)
			{
				index1 = n*(i-1) + k - 1;
				index2 = p*(k-1) + j - 1;

				res[indexRes] = res[indexRes] + (mat1[index1]*mat2[index2]);
			}
		}
	}
}
