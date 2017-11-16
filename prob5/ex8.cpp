ArbreBinari::ArbreBinari(int t[], int n)
{
	arrel = iArbreBinari(t, 0, n-1);
}

ArbreBinari::Nus* ArbreBinari::iArbreBinari(int *t, int e, int d)
{
	if (e > d)
	{
		return NULL;
	}
	else if (e == d)
	{
		return new Nus(NULL, NULL, t[e]);
	}
	else
	{
		int mig = e+1;
		while (mig <= d && t[mig] < e)
			mig++;
		Nus* aux1 = iArbreBinari(t, e+1, mig-1);
		Nus* aux2 = iArbreBinari(t, mig, d);
		return new Nus(aux1, aux2, t[e]);
	}
}