#include "Assignment2.h"
#include <cmath>

//////////////////////////////////CALCULATING MEAN////////////////////////////////////////////////////

float mean(float arr[], int n)		//summing all values and
{									//dividing by n to get mean
	float sum=0, average;

	for(int i=0; i<n; i++)
	{
		sum += arr[i];
	}
	average=sum/n;

	return average;
}

/////////////////////////////////CALCULATING STANDARD DEVIATION//////////////////////////////////////

float stdev(float arr[], int n)					//finding mean, then taking the square of
{												//the difference of each value with mean.
	float sum=0, power, variance, standard;		//Sum all these and get variance by dividing
	float M=mean(arr, n);						//the sum by n. Take square root to get
												//standard deviation.
	for(int i=0; i<n; i++)
	{
		power = pow(( arr[i]-M ), 2);
		sum += power;
	}
	variance = sum/n;
	standard = sqrt(quotient);

	return standard;
}

////////////////////////////////CALCULATING PERCENTILE///////////////////////////////////////////////

float pctile(float arr[], int n, float p)		//get p*n. Get the integer
{												//form. Now we can do linear
	float temp;									//interpolation.
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	float pN=n*p;
	int pN_rounded = pN;
	float difference = pN - pN_rounded;
	float percentile = arr[pN_rounded-1] + difference*(arr[pN_rounded] - arr[pN_rounded-1]);

	return percentile;
}

/////////////////////////////////FINDING TOTAL ERROR//////////////////////////////////////////////////

float error(float arrX[], float arrY[], int n, float m, float c)	//we have to find total error.
{																	//So find vertical difference
	float difference, square=0, division, root;						//b/w y-value of line and actual
																	//y-value given. Take square of these
	for(int i=0; i<n; i++)											//differences and then sum them.
	{
		difference = ( (m*arrX[i])+ c ) - arrY[i];
		square += pow(difference, 2);
	}

	return square;
}

/////////////////////////////////LSQ FIT///////////////////////////////////////////////////////////////

void lsq_fit(float arrX[], float arrY[], int n, float &m, float &c)		//regression line is technically line
{																		//of best fit. We need to find
	float meanX = mean(arrX, n);										//gradient and y-intercept of the
	float meanY = mean(arrY, n);										//line of best fit. Used formulas
	float diffX, diffY, sumXY=0, squareX=0;								//available on link provided but done
																		//in smaller steps. Found differences
	for(int i=0; i<n; i++)												//b/w each x and y value with mean of
	{																	//x and y respectively. Then found sum
		diffX = arrX[i] - meanX;										//of products of difference b/w x and y
		diffY = arrY[i] - meanY;										//(sumXY). Then found the summation of
		sumXY += diffX*diffY;											//squares of difference of each x value
																		//(squareX). Gradient is sumXY divided by
		squareX += pow(diffX, 2);										//square X. Y-intercept is (meanY - gradient*meanX).
	}
	m = sumXY/squareX;
	c = meanY - m*meanX;
}
