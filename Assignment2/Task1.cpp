#include "Assignment2.h"
#include <iostream>

using namespace std;

//////////////////////////CALCULATING FACTORIAL//////////////////////////////////////////////////////////////////

int fact(int n)								//multiply by each consecutive value till n
{											//(starting from 1)
	int factorial=1;

	for(int i=2; i<=n; i++)
	{
		factorial *= i;
		return factorial;
	}
}

/////////////////////////CALCULATING PERMUTATION/////////////////////////////////////////////////////////////////

int perm(int n, int r)						//if n equals r then taking factorial else
{											//multiplying from (n-r+1) till n, thus,
	int permutation=1;						//reducing the number of multiplications but
											//also allowing calculation of slightly larger permutations
	if(n==r)
	{
		permutation=fact(n);
		return permutation;
	}
	else
	{
		for(int i=(n-r)+1; i<=n; i++)
			permutation *= i;

		return permutation;
	}
}

//////////////////////////CALCULATING COMBINATION////////////////////////////////////////////////////////////////

int comb(int n, int r)						//if n equals r then we get "1"
{											//else if r is less than n/2 we permute
	int combination=1;						//and then divide by factorial of r.
											//But if r is more than n/2 we multiply
	if(n==r)								//from (r+1) till n and then we divide
		return combination;					//by factorial of (n-r). This allows
	else if( r<=(n/2) )						//to calculate a slightly
	{										//larger range of combinations.
		combination = perm(n, r);
		for(int i=r; i>1; i--)
		{
			combination /= i;
		}

		return combination;
	}
	else
	{
		for(int i=(r+1); i<=n; i++)
		{
			combination *=i;
		}

		for(int i=(n-r); i>1; i--)
		{
			combination /=i;
		}
	}
}
