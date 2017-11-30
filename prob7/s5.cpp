a)

bool * Ocupacio(const Fitxers &f, int T)
{
	int it_fitxers = 0;
	bool sol[f.nFitxers()];
	int tamany_restant = T;
	bool final = false;

	while (it_fitxers < f.nFitxers() && !final)
	{
		int prometedor = -1, mida_minima = INT_MAX;
		for (int i = 1; i < f.nFitxers(); ++i)
		{
			if (f.Mida(i) < mida_minima && !sol[i])
			{
				prometedor = i;
			}
		}
		int tamany_actual = tamany_restant - mida_minima;
		if (prometedor != -1 && tamany_actual < tamany_restant)
		{
			tamany_restant -= mida_minima;
			sol[it_fitxers] = true;
			it_fitxers++;
		}
		else
			final = true;
	}

	return sol;
}

b) 	En el cas que el primer fitxer ja sigui tant gran com la capacitat del disc, 
	el voraç deixaria d'explorar les possibilitats i no seria una sol·lució òptima.

c) 	El cost és O(n²) on n és el nombre de fitxers de f.

d) 	Una sol·lució mes optima seria ordenar la taula per la mida dels fitxers,
 	de manera que no caldria anar buscant el minim a cada iteracio, així passariem 
 	d'un O(n²) a un O(n·log n).


