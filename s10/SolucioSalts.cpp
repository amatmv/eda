//
// Created by amat on 12/12/17.
//

#include <climits>
#include "SolucioSalts.h"

SolucioSalts::SolucioSalts(const std::vector<std::vector<int>>& m)
{
    _mida = (int) m.size()-1;
    _matriu = new int*[_mida+1];
    _visitats = new bool*[_mida+1];
    for (int i = 0; i <= _mida; ++i)
    {
        _matriu[i] = new int[_mida+1];
        for (int j = 1; j <= _mida; ++j)
            _matriu[i][j] = m[i][j];
        _visitats[i] = new bool[_mida+1];
    }
}

bool SolucioSalts::acceptable(const CandidatsSalts &iCan) const
{
    posicio actual = iCan.actual ();
    return es_posicio_valida (actual) && !es_posicio_visitada (actual);
}

void SolucioSalts::anotar(const CandidatsSalts &iCan)
{
    posicio actual = iCan.actual ();
    _visitats[actual.y][actual.x] = true;
    _salts.emplace_back(CandidatsSalts::posicio(actual.x, actual.y));
}

void SolucioSalts::desanotar(const CandidatsSalts &iCan)
{
    posicio actual = iCan.actual ();
    _visitats[actual.y][actual.x] = false;
    _salts.pop_back();
}

bool SolucioSalts::es_posicio_visitada(const posicio& pos) const
{
    return _visitats[pos.y][pos.x];
}

bool SolucioSalts::es_posicio_valida (const posicio& pos) const
{
    return pos.x > 0 && pos.x <= _mida && pos.y > 0 && pos.y <= _mida;
}

bool SolucioSalts::completa() const
{
    return es_posicio_visitada(posicio(_mida,_mida));
}

std::list<SolucioSalts::posicio> SolucioSalts::cami() const
{
    return _salts;
}

CandidatsSalts SolucioSalts::inicialitzar_conjunt_candidats(const posicio &pos) const
{
    return CandidatsSalts(pos, _matriu[pos.x][pos.y]);
}

SolucioSalts& SolucioSalts::operator=(const SolucioSalts &sol)
{
    if (this != &sol)
    {
        _visitats = sol._visitats;
        _matriu = sol._matriu;
        _salts = sol._salts;
        _mida = sol._mida;
    }
    return *this;
}

bool SolucioSalts::esMillor(const SolucioSalts &optima) const
{
    int distancia_optima = optima._salts.empty() ? INT_MAX : optima._salts.size();
    return _salts.size() < distancia_optima;
}

bool SolucioSalts::esPotMillorar(const SolucioSalts &sol, const CandidatsSalts& iCan) const
{
    int distancia_a_origen_actual = posicio(1,1)-_salts.back();
    int distancia_a_origen_optim = posicio(1,1)-sol._salts.back();
    if (distancia_a_origen_actual < 0)
        distancia_a_origen_actual = 0;
    if (distancia_a_origen_optim < 0)
        distancia_a_origen_optim = 0;
    return true;
}

