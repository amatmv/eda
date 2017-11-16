//
// Created by amat on 26/10/17.
//

#ifndef ARBRE_BINARI_H
#define ARBRE_BINARI_H

#include <iostream>

using namespace std;

class ArbreBinariDinamic
{
public:

    // pre: cert
    // post: construeix un ArbreBinariDinamica buit
    ArbreBinariDinamic();

    // pre: s és el preordre d'un Arbre Binari vàlid
    // post: construeix un ArbreBinariDinamica a partir de la cadena de caràcters
    ArbreBinariDinamic(const char *s);

    // pre: cert
    // post: retorna cert si l'arbre actual està buit
    bool esBuit() const;

    // pre: cert
    // post: retorna un ArbreBinariDinamic on l'arrel és el fill dret de l'actual
    ArbreBinariDinamic * FillDret() const;

    // pre: cert
    // post: retorna un ArbreBinariDinamic on l'arrel és el fill esquerre de l'actual
    ArbreBinariDinamic * FillEsquerre() const;

    // pre: cert
    // post: retorna el contingut de l'arrel
    int Contingut() const;

private:
    struct node
    {
        node(int n, node *e, node *d)
        {
            dada = n;
            fe = e;
            fd = d;
        }
        float dada;
        node *fe, *fd;
    };

    node * arrel;

    node * iArbreBinariDinamic(const char *s, int &i);
    int charToInt(const char & c);
    bool esSeparador(const char & c);
    int llegirNombre(const char * t, int & i);
};


#endif //ACME_ARBREBINARI_H
