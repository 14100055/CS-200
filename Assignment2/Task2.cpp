#include "Assignment2.h"
#include <cmath>

//////////////////////////////////////MAGNITUDE OF A VECTOR///////////////////////////////////////////////////

float magnitude(float vec[], int n)				//taking square of each value
{												//and adding simultaneously
	float square=0, root;						//then taking the square root

	for(int i=0; i<n; i++)
	{
		square += pow(vec[i], 2);
	}
	root=sqrt(square);

	return root;
}

/////////////////////////////////////DOT PRODUCT OF TWO VECTORS//////////////////////////////////////////////

float dot(float vec1[], float vec2[], int n)	//multiplying and then adding each
{												//multiplication to get dot product
	float dotProduct=0;

	for(int i=0; i<n; i++)
	{
		dotProduct += (vec1[i]*vec2[i]);
	}

	return dotProduct;
}

/////////////////////////////////////ANGLE BETWEEN TWO VECTORS//////////////////////////////////////////////


float angle(float vec1[], float vec2[], int n)		//taking dot product of two vectors
{													//and then product of magnitude of
	float dotProduct, mag, division, theta;			//each vector. Divide dot product by
													//product of magnitudes and then
	dotProduct = dot(vec1, vec2, n);				//taking cos inverse to get angle
	mag = ( magnitude(vec1, n) * magnitude(vec2, n) );
	division = dotProduct/mag;
	theta = acos(division);

	return theta;
}

////////////////////////////////////NORMALIZING A VECTOR////////////////////////////////////////////////////

void normalize(float vec[], int n)				//finding magnitude of vector.
{												//then divide each value by
	float mag;									//magnitude to get unit vector(normalized)
	mag = magnitude(vec, n);

	for(int i=0; i<n; i++)
	{
		vec[i] = vec[i]/mag;
	}
}

////////////////////////////////CROSS PRODUCT OF TWO 3x3 VECTORS////////////////////////////////////////////

void cross(float result[3], float vec1[3], float vec2[3])	//taking cross product of
{															//two 1x3 vectors as taught
	result[0] = (vec1[1]*vec2[2]) - (vec1[2]*vec2[1]);		//in A'Levels
	result[1] = -( (vec1[0]*vec2[2]) - (vec1[2]*vec2[0]) );
	result[2] = (vec1[0]*vec2[1]) - (vec1[1]*vec2[0]);
}
