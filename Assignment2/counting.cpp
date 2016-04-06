int fact(int n)
{
	int factorial=1;

	for(int i=2; i<=n; i++)
	{
		factorial *= i;
		return factorial;
	}
}

int perm(int n, int r)
{
	int permutation=1;

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

int comb(int n, int r)
{
	int combination=1;

	if(n==r)
	{
		return combination;
	}
	else if( r<=(n/2) )
	{
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
