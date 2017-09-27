#include <iostream>
#include "estructuraDinamica.h"
using namespace std;


//////// Programa 8
/*
 * Exemples d'execucio
 *
 * entrada:
   3 4 2 -4 0
 * sortida:
   2 4 3 S:4
   4 S:0
 *
 * entrada:
   9 7 5 -5 0
 * sortida:
   5 7 9 S:5
   5 S:0
 */
int main () {
    int n;
    estructuraDinamica e1, e2;


    cin >> n;
    while (n != 0) {
        if (n > 0)
            e1.AfegirInici(n);
        else if (e1.Existeix(-n))
            e2.AfegirInici(-n);
        cin >> n;
    }
    e1.Llistar();
    e2.Llistar();

    return 0;
} 