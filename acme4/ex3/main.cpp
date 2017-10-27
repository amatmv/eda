//
// Created by amat on 26/10/17.
//

#include <iostream>
#include "ArbreBinari.h"

using namespace std;

void inordre_binari(const ArbreBinari * a)
{
    if (!a->esBuit())
    {
        inordre_binari(a->FillEsquerre());
        cout << a->Contingut() << " ";
        inordre_binari(a->FillDret());
    }
}

int main() {
    ArbreBinari *a;
    char entrada[100];

    cin.getline(entrada, 100);
    a = new ArbreBinari(entrada);
    cout << "Inordre: ";
    inordre_binari(a);
    cout << endl;
    return 0;
}