#include "Assignment2.h"

////////////////////////////////BUBBLESORT/////////////////////////////////////////////////////////////////////////////

void bubbleSort(int arr[], int n)	//Compare each value with the next value.
{									//If greater than the next value, we swap
	int temp;						//the values in the array. This will bring
									//the largest to the end. But we run it again
	for(int i=0; i<n-1; i++)		//till all the values are in order. If 1st time
	{								//brings largest value to end then 2nd time
		for(int j=0; j<n-1-i; j++)	//brings 2nd largest value to 2nd last index.
		{							//We got to continue until the (n-1)th largest
			if(arr[j]>arr[j+1])		//value is 2nd index (nth largest will already be
			{						//1st then). So run outer loop (n-1) times. And we
				temp=arr[j];		//got to compare from 1st value to the last value.
				arr[j]=arr[j+1];	//But its more efficient if we just stop till the
				arr[j+1]=temp;		//last largest cause that is already sorted
			}
		}
	}
}
