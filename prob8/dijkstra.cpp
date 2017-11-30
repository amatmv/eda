void GrafEtiquetat::mostrarDijkstra(int n)
{
	for (int i = 1; i <= nVers; ++i)
	{
		agafat[i] = false;
		distancia[i] = arestes[n][i];
	}
	agafat[n] = true;
	distancia[n] = 0;
	nVisitats = 1;
	int actual = n;
	while (nVisitats < nVers)
	{
		int node_mes_proper = cercaDistanciaMinima(actual)
		if (node_mes_proper == -1)
		{
			throw("No es connex");
		}
		else 
		{
			actualitzarEstructures(actual, node_mes_proper, distancia[node_mes_proper]);
			nVisitats++;
			atual = node_mes_proper;
		}
	}

	for (int i = 0; i < nVers; ++i)
	{
		cout << i << ", " << distancia[i] << endl;
	}
}

int cercaDistanciaMinima()
{
	int minima = INT_MAX;
	int node = -1;
	for (int i = 1; i <= nVers; ++i)
	{
		if (distancia[i] != -1 && !agafat[i])
		{
			if (distancia[i] < minima)
			{
				minima = distancia[i];
				node = i
			}
		}
	}
	return node;
}

void actualitzarEstructures(int origen, int desti)
{
	agafat[desti] = true;
	distancia[desti] = arestes[origen][desti];
}