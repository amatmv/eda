#include <iostream>
#include "estructuraDinamica.h"
using namespace std;


//////// Problema 6
/*
 * Exemples d'execucio
 *
 * entrada:
 3 4 2 5 0
 * sortida:
 5 2 4 0 3 S:3
 *
 * entrada:
 9 7 5 1 0
 * sortida:
 1 5 7 0 9 S:9
 */
int main()
{
	estructuraDinamica e;
	int primer, anterior, n;


	cin >> primer;
	anterior = primer;
	e.AfegirInici(primer);
  
	cin >> n;
	while (n != 0) {
		e.AfegirAbans(n, anterior);
		anterior = n;
		cin >> n;
	}
	e.AfegirAbans(n, primer);
	e.Llistar();
	
	return 0;
}
