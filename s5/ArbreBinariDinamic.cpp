// Amat Martínez Vilà
// u1939654
// Sessió 5

#include "ArbreBinariDinamic.h"

ArbreBinariDinamic::ArbreBinariDinamic()
{
    arrel = NULL;
}

ArbreBinariDinamic::ArbreBinariDinamic(const char *s)
{
    int i = 0;
    arrel = iArbreBinariDinamic(s, i);
}

bool ArbreBinariDinamic::esBuit() const {
    return arrel == NULL;
}

ArbreBinariDinamic* ArbreBinariDinamic::FillDret() const
{
    ArbreBinariDinamic* a = new ArbreBinariDinamic();
    a->arrel = arrel->fd;
    return a;
}

ArbreBinariDinamic* ArbreBinariDinamic::FillEsquerre() const
{
    ArbreBinariDinamic* a = new ArbreBinariDinamic();
    a->arrel = arrel->fe;
    return a;
}

int ArbreBinariDinamic::Contingut() const
{
    if (!esBuit())
        return arrel->dada;
    else
        throw("Arbre Buit!");
}
int ArbreBinariDinamic::charToInt(const char & c)
{
    return c >= '0' && c <= '9' ? int(c)-48 : int(c);
}

bool ArbreBinariDinamic::esSeparador(const char & c)
{
    return (c == '(' or c == ')' or c == ' ');
}

int ArbreBinariDinamic::llegirNombre(const char * t, int & i)
{
    int n = charToInt(t[i++]);
    while (!esSeparador(t[i]))
        n = n*10 + charToInt(t[i++]);
    return n;
}

ArbreBinariDinamic::node *ArbreBinariDinamic::iArbreBinariDinamic(const char *t, int &i)
{
    node *fe = NULL, *fd = NULL;
    int dada = llegirNombre(t, i);
    if (t[i] == '(')
    {
        i++;
        if (t[i] != ' ')
            fe = iArbreBinariDinamic(t, i);
        if (t[i] == ' ')
        {
            i++;
            fd = iArbreBinariDinamic(t, i);
            i++;
        }
        else
            i++;
    }
    return new node(dada, fe, fd);
}