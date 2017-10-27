//
// Created by amat on 26/10/17.
//

#ifndef ARBRE_BINARI_H
#define ARBRE_BINARI_H

#include <iostream>

using namespace std;

class ArbreBinari { // Arbre Binari
public:
    ArbreBinari();
    ArbreBinari(const char *s);
    bool esBuit() const;
    ArbreBinari * FillDret() const;
    ArbreBinari * FillEsquerre() const;
    int Contingut() const;
private:
    struct node {
        node(int n, node *e, node *d)
        {
            dada = n;
            fe = e;
            fd = d;
        }
        int dada;
        node *fe, *fd;
    };

    node * arrel;

    node * iArbreBinari(const char *s, int &i); // metode auxiliar del constructor
    int charToInt(const char & c);
    bool esSeparador(const char & c);
    int llegirNombre(const char * t, int & i);
};


#endif //ACME_ARBREBINARI_H
