#include <iostream>
#include "estructuraDinamica.h"
using namespace std;


///////// Programa 4
/*
 * Exemples d'execucio
 *
 * entrada:
 3 4 2 4 0
 * sortida:
 2 3 4 4 S:4
 *
 * entrada:
 9 7 5 1 0
 * sortida:
 1 5 7 9 S:1
 */
int main () {
    int n;
    estructuraDinamica e;

    
    cin >> n;
    while (n != 0) {
        e.InserirOrdenadament(n);
        cin >> n;
    }
    e.Llistar();
    
    return 0;
}
