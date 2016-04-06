#include "Assignment2.h"

/////////////////////////////FINDING IF INTERSECTION POINT EXISTS B/W TWO LINE SEGMENTS/////////////////////////////////////

bool intersect(float l1[2][2], float l2[2][2])	//Used formula found from net. Then used
{												//conditions to see if it intersects or not.
	float uA = ( (l1[0][1] - l2[0][1])*(l2[1][0] - l2[0][0]) - (l1[0][0] - l2[0][0])*(l2[1][1] - l2[0][1]) )/( (l1[1][0] - l1[0][0])*(l2[1][1] - l2[0][1]) - (l1[1][1] - l1[0][1])*(l2[1][0] - l2[0][0]) );
	float uB = ( (l1[0][1] - l2[0][1])*(l1[1][0] - l1[0][0]) - (l1[0][0] - l2[0][0])*(l1[1][1] - l1[0][1]) )/( (l1[1][0] - l1[0][0])*(l2[1][1] - l2[0][1]) - (l1[1][1] - l1[0][1])*(l2[1][0] - l2[0][0]) );

	if( ( (uA>=0)&&(uA<=1) )&&( (uB>=0)&&(uB<=1) ) )
		return true;
	else
		return false;
}

/////////////////////////////FINDING THE AREA OVERLAP//////////////////////////////////////////////////////////////////////

float area_overlap(float rect1[4], float rect2[4])
{
	float bottomLine1[2][2]={ {rect1[1], rect1[2]}, {(rect1[1]+rect1[3]), rect1[2]} };			//Made arrays which are the line segments.
	float leftLine1[2][2]={ {rect1[1], rect1[2]}, {rect1[1], (rect1[2]+rect1[4])} };			//Then checking if there is any intersection or not.
	float rightLine1[2][2]={ {(rect1[1]+rect1[3]), rect1[2]}, {(rect1[1]+rect1[3]), (rect1[2]+rect1[4])} };		//If no intersection then return 0 area.
	float topLine1[2][2]={ {rect1[1], (rect1[2]+rect1[4])}, {(rect1[1]+rect1[3]), (rect1[2]+rect1[4])} };
	float bottomLine2[2][2]={ {rect2[1], rect2[2]}, {(rect2[1]+rect2[3]), rect2[2]} };
	float leftLine2[2][2]={ {rect2[1], rect2[2]}, {rect2[1], (rect2[2]+rect2[4])} };
	float rightLine2[2][2]={ {(rect2[1]+rect2[3]), rect2[2]}, {(rect2[1]+rect2[3]), (rect2[2]+rect2[4])} };
	float topLine2[2][2]={ {rect2[1], (rect2[2]+rect2[4])}, {(rect2[1]+rect2[3]), (rect2[2]+rect2[4])} };

	if( (intersect(bottomLine1, leftLine2)) || (intersect(bottomLine1, rightLine2)) || (intersect(topLine1, leftLine2)) || (intersect(topLine1, rightLine2)) || (intersect(leftLine1, bottomLine2)) || (intersect(leftLine1, topLine2)) || (intersect(rightLine1, bottomLine2)) || (intersect(rightLine1, topLine2)) || ( ( (rect2[1]>rect1[1])&&((rect2[1]+rect2[3])<(rect1[1]+rect1[3])) )&&( (rect2[2]>rect1[2])&&((rect2[2]+rect2[4])<(rect1[2]+rect1[4])) ) ) || ( ( (rect1[1]>rect2[1])&&((rect1[1]+rect1[3])<(rect2[1]+rect2[3])) )&&( (rect1[2]>rect2[2])&&((rect1[2]+rect1[4])<(rect2[2]+rect2[4])) ) ) )
	{
		return 1;
		//if(rect1[3]>rect2[3])
		//{
		//}
	}
	else
	{
		return 0;
	}

}

////////////////////////////FINDING THE AREA OF A POLYGON WITH N-VERTICES///////////////////////////////////////////////////

float polygon_area(float arrX[], float arrY[], int n)		//taking the summation of
{															//determinants. Then adding
	float det=0, area=0;									//the determinant b/w last
															//and 1st column to summation.
	for(int i=0; i<n; i++)									//Then taking half of this
	{														//to get the area.
		det += ( (arrX[i]*arrY[i+1]) - (arrX[i+1]*arrY[i]) );
	}
	det += ( (arrX[n-1]*arrY[0]) - (arrX[0]*arrY[n-1]) );

	area = det/2;

	return area;
}
