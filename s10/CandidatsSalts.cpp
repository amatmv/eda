//
// Created by amat on 12/12/17.
//

#include <cmath>
#include "CandidatsSalts.h"

CandidatsSalts::CandidatsSalts(const posicio& pos_act,const int& valor_act)
{
    _v_ant = valor_act;
    _pos_actual = pos_act;
    _iCan = 0;
}

CandidatsSalts::posicio CandidatsSalts::actual() const
{
    if (es_fi ())
        throw ("Es l'ultim candidat.");
    CandidatsSalts::posicio desplacament = DESPLACAMENTS[_iCan], pos_actual = _pos_actual;
    return pos_actual+(desplacament*_v_ant);
}

bool CandidatsSalts::es_fi() const
{
    return _iCan >= 4;
}

void CandidatsSalts::seguent()
{
    if (es_fi())
        throw ("Es l'ultim candidat.");
    _iCan++;
}

CandidatsSalts::posicio CandidatsSalts::posicio::operator*(const int& n)
{
    return {x*n, y*n};
}

CandidatsSalts::posicio CandidatsSalts::posicio::operator+(const CandidatsSalts::posicio &p)
{
    return {x+p.x, y+p.y};
}

int CandidatsSalts::posicio::operator-(const CandidatsSalts::posicio &p)
{
    return (int) sqrt((p.x-x)^2+(p.y-y)^2);
}
