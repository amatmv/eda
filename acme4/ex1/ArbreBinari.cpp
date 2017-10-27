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

int ArbreBinari::Contingut() const
{
    if (!esBuit())
        return arrel->dada;
    else
        throw("Arbre Buit!");
}

int ArbreBinari::charToInt(const char & c)
{
    return int(c)-48;
}

bool ArbreBinari::esSeparador(const char & c)
{
    return (c == '(' or c == ')' or c == ' ');
}

int ArbreBinari::llegirNombre(const char * t, int & i)
{
    int n = charToInt(t[i++]);
    while (!esSeparador(t[i]))
        n = n*10 + charToInt(t[i++]);
    return n;
}

ArbreBinari::node *ArbreBinari::iArbreBinari(const char *s, int &i)
{
    node *fe = NULL, *fd = NULL;
    int dada = llegirNombre(s, i);
    if (s[i] == '(')
    {
        i++;
        if (s[i] != ' ')
            fe = iArbreBinari(s, i);
        i++;
        if (s[i] != ')')
        {
            fd = iArbreBinari(s, i);
            i++;
        }
    }
    return new node(dada, fe, fd);
}
