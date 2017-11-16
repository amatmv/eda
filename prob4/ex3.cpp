void edfOrdenada2::EliminarValor(const element& c)
{
	LlistaEnter l;
	int j = 0;
	for (int i = 0; i < nDades; ++i)
	{
		int k = index[i];
		if (dades[k].e == e)
			l.Inserir(e);
		else
		{
			index[j] = k;
			j++;
		}
	}
	l.Primer();
	for (int i = j; i < nDades; ++i)
		index[i] = l.Actual(); l.Seguent();
	nDades = j;

}