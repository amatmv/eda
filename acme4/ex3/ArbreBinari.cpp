//
// Created by amat on 26/10/17.
//

#include "ArbreBinari.h"

ArbreBinari::ArbreBinari()
{
    arrel = NULL;
}

ArbreBinari::ArbreBinari(const char *s)
{
    int i = 0;
    arrel = iArbreBinari(s, i);
}

bool ArbreBinari::esBuit() const {
    return arrel == NULL;
}

ArbreBinari *ArbreBinari::FillDret() const
{
    ArbreBinari* a = new ArbreBinari();
    a->arrel = arrel->fd;
    return a;
}

ArbreBinari *ArbreBinari::FillEsquerre() const
{
    ArbreBinari* a = new ArbreBinari();
    a->arrel = arrel->fe;
    return a;
}

char ArbreBinari::Contingut() const
{
    if (!esBuit())
        return arrel->dada;
    else
        throw("Arbre Buit!");
}

ArbreBinari::node *ArbreBinari::iArbreBinari(const char *s, int &i)
{
    node *fe = NULL, *fd = NULL;
    char dada = s[i];
    i++;
    if (s[i] == '(')
    {
        i++;
        if (s[i] != ' ')
            fe = iArbreBinari(s, i);
        if (s[i] == ' ')
        {
            i++;
            fd = iArbreBinari(s, i);
            i++;
        }
        else
            i++;
    }
    return new node(dada, fe, fd);
}
