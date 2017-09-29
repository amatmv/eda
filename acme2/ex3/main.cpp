#include <iostream>
#include "estructuraDinamica.h"
using namespace std;


//////// Problema 9
/*
 * Exemples d'execucio
 *
 * entrada:
   1 2 3 0
 * sortida:
   1 2 3 1 2 1 S:0
   N.ELEMENTS: 6
 *
 * entrada:
   3 2 1 0
 * sortida:
   1 1 2 1 2 3 S:0
   N.ELEMENTS: 6
 */

int main() {
	estructuraDinamica e;
	int n;
	
	cin >> n;
	while (n != 0) {
		e.OmplirInici(n);
		cin >> n;
	}
	e.Llistar();
	cout << "N.ELEMENTS: " << e.nElements() << endl;

	return 0;
}
