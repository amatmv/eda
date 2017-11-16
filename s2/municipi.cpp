//
// Created by amat on 23/10/17.
//

#include <cfloat>
#include "municipi.h"


Municipi::Municipi()
{
    _codi_comarca = 0;
    _nom = "desconegut";
    _codi = 0;
    _poblacio = 0;
    _extensio = 0;
}

Municipi::Municipi(int codi_comarca, int codi, string municipi, int poblacio, float extensio)
{
    _codi_comarca = codi_comarca;
    _nom = municipi;
    _codi = codi;
    _poblacio = poblacio;
    _extensio = extensio;
}

int Municipi::codi() const
{
    return _codi;
}

string Municipi::nom() const
{
    return _nom;
}

int Municipi::poblacio() const
{
    return _poblacio;
}

float Municipi::extensio() const
{
    return _extensio;
}

float Municipi::densitat() const
{
    return _extensio > 0 ? _poblacio/_extensio : -1;
}

bool Municipi::operator==(const Municipi &m) const
{
    return _codi == m._codi;
}

int Municipi::codi_comarca() const
{
    return _codi_comarca;
}