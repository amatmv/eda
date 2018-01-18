// Amat Martínez Vilà
// u1939654
// Practica d'algorísmica

#include "SolucionadorNadal.h"
#include "CandidatsTaula.h"

SolucionadorNadal::SolucionadorNadal(const SolucioNadal& sol)
{
    _sol_actual = sol;
    _solucio_trobada = false;
}

void SolucionadorNadal::solucio_index_aversio()
{
    asseure_convidats_index_maxim();
    _sol_optima = _sol_actual;
}

void SolucionadorNadal::asseure_convidats_index_maxim()
{
    CandidatsTaula iCan = _sol_actual.inicialitzarConjuntCandidats();
    while (!iCan.es_fi() and !_solucio_trobada)
    {
        if (_sol_actual.acceptable(iCan))
        {
            _sol_actual.anotar(iCan);
            if (!_sol_actual.completa())
            {
                asseure_convidats_index_maxim();
                if (!_solucio_trobada)
                    _sol_actual.desanotar(iCan);
            }
            else
                _solucio_trobada = true;
        }
        iCan.seguent();
    }
}

void SolucionadorNadal::solucio_minima_aversio()
{
    CandidatsTaula iCan = _sol_actual.inicialitzarConjuntCandidats();
    while (!iCan.es_fi())
    {
        if (_sol_actual.acceptableOptim(iCan) && _sol_actual.esPotMillorar(_sol_optima))
        {
            _sol_actual.anotar(iCan);
            if (!_sol_actual.completa())
                solucio_minima_aversio();
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

bool SolucionadorNadal::solucio_trobada() const
{
    return _solucio_trobada;
}

void SolucionadorNadal::mostrar() const
{
    _sol_optima.mostrar();
}


