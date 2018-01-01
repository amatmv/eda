// Amat Martínez Vilà
// u1939654
// Sessió 10

#include "SolucionadorSalts.h"


SolucionadorSalts::SolucionadorSalts(const SolucioSalts &s)
{
    _sol_actual = s;
}

void SolucionadorSalts::trobar_una_solucio()
{
    calcular_solucio(CandidatsSalts::posicio(1,1));
}

void SolucionadorSalts::calcular_solucio(const CandidatsSalts::posicio& act)
{
    CandidatsSalts iCan = _sol_actual.inicialitzar_conjunt_candidats(act);
    while (!iCan.es_fi())
    {
        if (_sol_actual.acceptable(iCan) && _sol_actual.esPotMillorar(_sol_optima))
        {
            _sol_actual.anotar(iCan);
            if (!_sol_actual.completa())
                calcular_solucio(iCan.actual());
            else
            {
                if (_sol_actual.esMillor(_sol_optima))
                    _sol_optima = _sol_actual;
            }
            _sol_actual.desanotar(iCan);
        }
        iCan.seguent();
    }
}

std::list<SolucioSalts::posicio> SolucionadorSalts::cami() const
{
    return _sol_optima.cami();
}
