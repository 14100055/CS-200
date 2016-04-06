#include <iostream>
#include "Assignment2.h"

using namespace std;

int main()
{

////CHECKING TASK 1//////////////////////////////////////////////////////

	//int n, factorial, permutation, combination;
	//cout<<endl<<"Enter a number to factorialize: ";
	//cin>>n;

	//factorial=fact(n);
	//cout<<endl<<n<<"! = "<<factorial<<endl;

	//permutation = perm(20, 7);
	//cout<<permutation<<endl;

	//combination = comb(20, 7);
	//cout<<combination<<endl;

////CHECKING TASK 2//////////////////////////////////////////////////////

	//const int size=3;
	//float mag;
	//float dotProduct;
	//float theta;

	//float floatArray1[size]={1, 2, 3};
	//float floatArray2[size]={2, 3, 1};
	//float result[3]={0};

	//mag=magnitude(floatArray1, size);
	//cout<<mag<<endl;

	//dotProduct=dot(floatArray1, floatArray2, size);
	//cout<<dotProduct<<endl;

	//theta=angle(floatArray1, floatArray2, size);
	//cout<<theta<<endl;

	//normalize(floatArray1, size);
	//for(int i=0; i<size; i++)
	//{
	//	cout<<floatArray1[i]<<" ";
	//}

	//cross(result, floatArray1, floatArray2);
	//for(int i=0; i<3; i++)
	//{
	//	cout<<result[i]<<" ";
	//}

////CHECKING TASK 3///////////////////////////////////////////////////

	//float line1[2][2]={{0, 0}, {1, 1}};
	//float line2[2][2]={{2, 2}, {2, 3}};
	//int area_exist;

	//float array1[4]={0, 0, 2, 2};
	//float array2[4]={1, 1, 3, 4};

	//bool intersection = intersect(line1, line2);

	//area_exist=area_overlap(array1, array2);

	//cout<<area_exist<<endl;

	//cout<<intersection<<endl;

////CHECKING TASK 4///////////////////////////////////////////////////

//	const int size1=10;

//	int sorting[size1]={7, 9, 2, 10, 6, 4, 5, 1, 8, 3};

//	bubbleSort(sorting, size1);

//	for(int i=0; i<size1; i++)
//	{
//		cout<<sorting[i]<<" ";
//	}
//	cout<<endl;

////CHECKING TASK 5//////////////////////////////////////////////////

	//const int size2=13;
	//const int size3=5;

	//float average, standard, percentile, difference;
	//float array5[size2]={1.1, 1.7, 1.2, 0.2, 2.1, 2.0, 2.5, 2.0, 3.2, 3.5, 3.6, 3.0, 4.0};
	//float array5_X[size3]={1, 2, 3, 4, 5};
	//float array5_Y[size3]={3, 4, 5, 6, 7};
	//float gradient=0;
	//float y_intercept=0;

	//for(int i=0; i<size3; i++)
	//{
	//	cout<<array5_Y[i]<<" ";
	//}
	//cout<<endl;

	//average=mean(array5, size2);
	//cout<<average<<endl;

	//standard = stdev(array5, size2);
	//cout<<standard<<endl;

	//percentile=pctile(array5, size2, 0.3);
	//cout<<percentile<<endl;

	//difference = error(array5_X, array5_Y, size3, 1, 0);
	//cout<<difference<<endl;

	//lsq_fit(array5_X, array5_Y, size3, gradient, y_intercept);

	//for(int i=0; i<size3; i++)
	//{
	//	cout<<array5_X[i]<<" ";
	//}
	//cout<<endl;

	//for(int i=0; i<size3; i++)
	//{
	//	cout<<array5_Y[i]<<" ";
	//}
	//cout<<endl;
	//cout<<"Gradient = "<<gradient<<endl;
	//cout<<"Y-intercept = "<<y_intercept<<endl;

////CHECKING TASK 6////////////////////////////////////////////////////

	//const int n=3;
	//const int size4 = 9;
	//const int size5 = 2;
	//const int size6 = 3;
	//const int size7 = 4;

	//float mat[size7*size7]={1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
	//float vec[size7]={1, 1, 1, 1};

	//float matrix1[size4]={0, 1, 2, 3, 4, 5, 6, 7, 8};

	//float mat1[size5*size6] = {-1, 3, -4, 2, 4, 5};
	//float mat2[size6*size7] = {-2, -1, 3, -3, 0, 1, 2, 4, 5, 6, 7, 8};

	//matrixTranspose(matrix1, n);

	//float res[size5*size7] = {0};

	//matrixMul(res, mat1, mat2, size5, size6, size7);

	//for(int i=0; i<(size5*size7); i++)
	//{
	//	cout<<res[i]<<" ";
	//}
	//cout<<endl;

	//transform(mat, vec, size7);

	//for(int i=0; i<size7; i++)
	//{
	//	cout<<vec[i]<<" ";
	//}
	//cout<<endl;

////TASK 7/////////////////////////////////////////////////////////////////////////

	const int n=5;
	const int turns=2;

	bool board[n*n]={0};
	int turnR[turns]={1,2};
	int turnC[turns]={1,2};

	KGame(board, turnR, turnC, n, turns);

	for(int i=0; i<(n*n); i++)
	{
		if(i%n==0)
			cout<<endl;

		cout<<board[i]<<" ";
	}
	cout<<endl;

////TASK 9/////////////////////////////////////////////////////////////////////////

	/*const int size9=3;
	int uniqueNumber;

	int arrayUnique[(2*size9)-1]={9, 8, 9, 8, 4};

	uniqueNumber=unique(arrayUnique, size9);

	cout<<"The unique number is: "<<uniqueNumber<<endl;*/

	return 0;

}
