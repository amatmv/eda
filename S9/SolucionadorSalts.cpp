//
// Created by amat on 12/12/17.
//

#include "SolucionadorSalts.h"

SolucionadorSalts::SolucionadorSalts()
{
    _solucio_trobada = false;
}

SolucionadorSalts::SolucionadorSalts(const SolucioSalts &s)
{
    _sol = s;
    _solucio_trobada = false;
}

void SolucionadorSalts::trobar_una_solucio()
{
    CandidatsSalts::posicio pos_inicial = CandidatsSalts::posicio(1,1);
//    _sol.anotar(_sol.inicialitzar_conjunt_candidats(pos_inicial));
    calcular_solucio(pos_inicial);
}

void SolucionadorSalts::calcular_solucio(const CandidatsSalts::posicio& act)
{
    CandidatsSalts iCan = _sol.inicialitzar_conjunt_candidats(act);
    while (!iCan.es_fi() and !_solucio_trobada)
    {
        if (_sol.acceptable(iCan))
        {
            _sol.anotar(iCan);
            if (!_sol.completa())
            {
                calcular_solucio(iCan.actual());
                if (!_solucio_trobada)
                    _sol.desanotar(iCan);
            }
            else
                _solucio_trobada = true;
        }
        iCan.seguent();
    }
}

std::list<SolucioSalts::posicio> SolucionadorSalts::cami() const
{
    return _sol.cami();
}
