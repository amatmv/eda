ConjuntEnters GarbelEratostenes(int n)
{
	ConjuntEnters Candidats, Primers;
	for (int i = 0; i <= n; ++i)
	{
		Candidats.Afegir(i);
	}

	while (!Candidats.esBuit())
	{
		int i = Candidats.Minim();
		Primers.Afegir(i);
		int j = i*i;
		Candidats.Esborrar(i);
		while (j <= n)
		{
			Candidats.Esborrar(j);
			j += i;
		}
	}
	retorna Primers;
}