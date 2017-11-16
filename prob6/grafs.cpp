GrafEtiquetat::GrafEtiquetat(int v, int a, int p, bool dirigit)
{
	_nVertexs = n;
	_nArestes = 0;
	_drigit = true;
	Arestes = new nodeAresta[_nVertexs + 1];
	for (int i = 0; i <= _nVertexs; ++i)
		Arestes[i] = NULL;
	for (int i = 1; i < _nVertexs; ++i)
	{
		nodeAresta* nou = new nodeAresta;
		nou->desti = i+1;
		nou->pes = p;
		nou->seguent = NULL;
		Arestes[i] = nou;
		_nArestes++;
	}
	while (_nArestes < a)
	{
		int n1 = rand() % _nVertexs + 1;
		int n2 = rand() % _nVertexs + 1;
		int pes = rand() % p + 1;
		nodeAresta* nou = Arestes[n1];
		nodeAresta* ant = NULL;
		while (nou != NULL and nou->desti != n2)
		{
			ant = nou;
			nou = nou->seguent;
		}
		if (nou == NULL)
		{
			nodeAresta* aux = new nodeAresta;
			aux->desti = n2;
			aux->pes = pes;
			aux->seguent = NULL;
			ant->seguent = aux;
			_nArestes++;
		}
	}

}