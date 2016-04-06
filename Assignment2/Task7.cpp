#include "Assignment2.h"

/////////////////////////////I-GAME//////////////////////////////////////////////////////////////////////

void IGame(bool arr[], int turnR[], int turnC[], int n, int nTurns)
{
	for(int i=0; i<nTurns; i++)
	{
		arr[(n*(turnR[i])+turnC[i])]=!arr[(n*(turnR[i])+turnC[i])];									//Checking whether each part of
																									//letter I is on the board or not.
		if( (((turnR[i]+1)<n) && ((turnR[i]+1)>=0))&&((turnC[i]<n) && (turnC[i]>=0)) )				//If on the board, then change the
		{																							//0 (False) to a 1 (True) OR
			arr[(n*(turnR[i]+1)+turnC[i])]=!arr[(n*(turnR[i]+1)+turnC[i])];							//1 (True) to a 0 (False).
		}

		if( (((turnR[i]+1)<n) && ((turnR[i]+1)>=0))&&(((turnC[i]+1)<n) && ((turnC[i]+1)>=0)) )
	    {
			arr[(n*(turnR[i]+1)+(turnC[i]+1))]=!arr[(n*(turnR[i]+1)+(turnC[i]+1))];
		}

		if( (((turnR[i]+1)<n) && ((turnR[i]+1)>=0))&&(((turnC[i]-1)<n) && ((turnC[i]-1)>=0)) )
		{
			arr[(n*(turnR[i]+1)+(turnC[i]-1))]=!arr[(n*(turnR[i]+1)+(turnC[i]-1))];
		}

		if( (((turnR[i]-1)<n) && ((turnR[i]-1)>=0))&&(((turnC[i])<n) && ((turnC[i])>=0)) )
		{
			arr[(n*(turnR[i]-1)+(turnC[i]))]=!arr[(n*(turnR[i]-1)+(turnC[i]))];
		}

		if( (((turnR[i]-1)<n) && ((turnR[i]-1)>=0))&&(((turnC[i]+1)<n) && ((turnC[i]+1)>=0)) )
		{
			arr[(n*(turnR[i]-1)+(turnC[i]+1))]=!arr[(n*(turnR[i]-1)+(turnC[i]+1))];
		}

		if( (((turnR[i]-1)<n) && ((turnR[i]-1)>=0))&&(((turnC[i]-1)<n) && ((turnC[i]-1)>=0)) )
		{
			arr[(n*(turnR[i]-1)+(turnC[i]-1))]=!arr[(n*(turnR[i]-1)+(turnC[i]-1))];
		}
	}
}

/////////////////////////////K-GAME/////////////////////////////////////////////////////////////////////

void KGame(bool arr[], int turnR[], int turnC[], int n, int nTurns)
{
	for(int i=0; i<nTurns; i++)
	{
		arr[(n*(turnR[i])+turnC[i])]=!arr[(n*(turnR[i])+turnC[i])];									//Checking whether each part of
																									//letter K is on the board or not.
		if( (((turnR[i]+1)<n) && ((turnR[i]+1)>=0))&&(((turnC[i]+1)<n) && ((turnC[i]+1)>=0)) )		//If on the board, then change the
		{																							//0 (False) to a 1 (True) OR
			arr[(n*(turnR[i]+1)+(turnC[i]+1))]=!arr[(n*(turnR[i]+1)+(turnC[i]+1))];					//1 (True) to a 0 (False).
		}

		if( (((turnR[i]+1)<n) && ((turnR[i]+1)>=0))&&(((turnC[i]-1)<n) && ((turnC[i]-1)>=0)) )
		{
			arr[(n*(turnR[i]+1)+(turnC[i]-1))]=!arr[(n*(turnR[i]+1)+(turnC[i]-1))];
		}

		if( (((turnR[i]-1)<n) && ((turnR[i]-1)>=0))&&(((turnC[i]+1)<n) && ((turnC[i]+1)>=0)) )
		{
			 arr[(n*(turnR[i]-1)+(turnC[i]+1))]=!arr[(n*(turnR[i]-1)+(turnC[i]+1))];
		}

		if( (((turnR[i]-1)<n) && ((turnR[i]-1)>=0))&&(((turnC[i]-1)<n) && ((turnC[i]-1)>=0)) )
		{
			arr[(n*(turnR[i]-1)+(turnC[i]-1))]=!arr[(n*(turnR[i]-1)+(turnC[i]-1))];
		}

		if( (((turnR[i])<n) && ((turnR[i])>=0))&&(((turnC[i]-1)<n) && ((turnC[i]-1)>=0)) )
		{
			arr[(n*(turnR[i])+(turnC[i]-1))]=!arr[(n*(turnR[i])+(turnC[i]-1))];
		}
	}
}
