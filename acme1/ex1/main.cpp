#include <iostream>
#include "estructuraDinamica.h"
using namespace std;

//////// Problema 2
/*
 * Exemples d'execucio
 *
 * entrada:
   5 9 10 0
 * sortida:
   5 9 10 S:0
 *
 * entrada:
   9 7 5 3 1 0
 * sortida
   9 7 5 3 1 S:0
 */
int main()
{
	estructuraDinamica e;
	int n;

	cin >>n;
  
	while (n!=0) {
		e.AfegirFinal(n);
		cin >> n;
	}
	e.Llistar();
	
	return 0;
}
