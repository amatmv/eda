//
// Created by amat on 26/10/17.
//

#include <iostream>
#include "ArbreBinari.h"

using namespace std;

void preordre_binari(const ArbreBinari * a)
{
    if (!a->esBuit())
    {
        cout << a->Contingut() << " ";
        preordre_binari(a->FillEsquerre());
        preordre_binari(a->FillDret());
    }
}

int main() {
    ArbreBinari *a;
    char entrada[100];

    cin.getline(entrada, 100);
    a = new ArbreBinari(entrada);
    cout << "Preordre: ";
    preordre_binari(a);
    cout << endl;
    return 0;
}