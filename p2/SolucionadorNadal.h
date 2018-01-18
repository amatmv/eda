#ifndef P2_SOLUCIONADORNADAL_H
#define P2_SOLUCIONADORNADAL_H

#include <iostream>
#include "SolucioNadal.h"

class SolucionadorNadal
{
public:

    SolucionadorNadal() = default;

    explicit SolucionadorNadal(const SolucioNadal& sol);

    /**
     * @pre: --
     * @post: troba una sol·lució donat un màxim grau d'aversió entre convidats utilitzant l'algorisme de backtracking
     */
    void solucio_index_aversio();

    /**
     * @pre: --
     * @post: troba una sol·lució garantint un grau d'aversió total mínim entre convidats utilitzant l'algorisme de backtracking
     */
    void solucio_minima_aversio();

    /**
     * @pre: --
     * @post: retorna cert si la sol·lució ha estat trobada
     */
    bool solucio_trobada() const;

    /**
     * @pre: --
     * @post: mostra la sol·lució actual
     */
    void mostrar() const;

private:

    /**
     * @pre: --
     * @post: algorísme de backtracking donada un grau d'aversió màxim
     */
    void asseure_convidats_index_maxim();

    /// Sol·lucions actuals i òptimes sobre les quals es treballen
    SolucioNadal _sol_actual, _sol_optima;
    /// Variable booleana de control
    bool _solucio_trobada;
};


#endif //P2_SOLUCIONADORNADAL_H
