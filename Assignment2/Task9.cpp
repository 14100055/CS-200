#include "Assignment2.h"

//////////////////////////FINDING THE UNIQUE NUMBER////////////////////////////////////////////

int unique(int arr[], int n)			//Get each value and compare it to
{										//every value in the array. Each time
	int unique;							//it matches, increment unique by 1.
	for(int i=0; i<(2*n-1); i++)		//If at the end of checking that value
	{									//unique is 1 then that means that, that
		unique=0;						//value was present only once and is thus
		for(int j=0; j<(2*n-1); j++)	//the unique value.
		{
			if(arr[i]==arr[j])
			{
				unique++;
			}
		}
		if(unique==1)
		{
			return arr[i];
		}
	}
}
