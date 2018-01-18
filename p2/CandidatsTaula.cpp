// Amat Martínez Vilà
// u1939654
// Practica d'algorísmica

#include "CandidatsTaula.h"

CandidatsTaula::CandidatsTaula()
{
    _iCan = 0;
    _convidats = 0;
}

CandidatsTaula::CandidatsTaula(const int &n_candidats)
{
    _iCan = 0;
    _convidats = n_candidats;
}

int CandidatsTaula::actual() const
{
    return _iCan;
}

bool CandidatsTaula::es_fi() const
{
    return _iCan >= _convidats;
}

void CandidatsTaula::seguent()
{
    _iCan++;
}
