void EDFDispersioAORL::Ampliar()
{
	int mida_vella = maxDades;
	maxDades *= 2;
	node* nova = new node[maxDades];
	for (int i = 0; i < mida_vella; ++i)
	{
		if (dades[i].estat == PLENA)
		{
			// Nova posició, aplicada a partir de la nova mida de la taula. 
			int c = dades[i].h() % maxDades;

			// Per defecte, C++ copia els struct camp a 
			// camp sense necessitat de implementar un operador de copia 
			nova.dades[c] = dades[i]; 
		}
	}
	allibera();
	dades = nova;
}

void EDFDispersioAORL::allibera()
{
	delete [] dades;
	dades = NULL;
}