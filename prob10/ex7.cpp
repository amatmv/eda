
// Versio 1

int sumaMesGran(int t[], int n)
{
	int res = t[0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int suma = 0;
			for (int k = i; k <= j; ++i)
			{
				suma += t[k];
			}
			if (suma > res)
				res = suma;
		}
	}
	return res;
}

// Versio 2

int sumaMesGran(int t[], int n)
{
	int res = t[0];
	for (int i = 0; i < n; ++i)
	{
		int suma = 0;
		for (int j = i; j < n; ++j)
		{
			suma += t[k];
			if (suma > res)
				res = suma;
		}
	}
	return res;
}

// Versio 3

int sumaMesGran(int t[], int n)
{
	return iSumaMesGran(t, 0, n-1);
}

int iSumaMesGran(int t[], int min, int max)
{
	if (min > max)
		return 0;
	else if (min == max)
		return t[max];
	else
	{
		int mig = (min+max)/2;
		int suma_e = iSumaMesGran(t,min,mig);
		int suma_d = iSumaMesGran(t,mig+1,max);
		
	}
}