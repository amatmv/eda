//
// Created by amat on 12/12/17.
//

#include "SolucioSalts.h"

SolucioSalts::SolucioSalts(const std::vector<std::vector<int>>& m)
{
    _matriu = m;
    auto mida = m.size();
    _visitats = std::vector<std::vector<bool>>(mida, std::vector<bool>(mida+1));
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
    auto max = _matriu.size();
    return pos.x > 0 && pos.x < max && pos.y > 0 && pos.y < max;
}

bool SolucioSalts::completa() const
{
    auto max = (int) _matriu.size()-1;
    return es_posicio_visitada(posicio(max,max));
}

std::list<SolucioSalts::posicio> SolucioSalts::cami() const
{
    return _salts;
}

CandidatsSalts SolucioSalts::inicialitzar_conjunt_candidats(const posicio &pos) const
{
    return CandidatsSalts(pos, _matriu[pos.x][pos.y]);
}
