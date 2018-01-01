#ifndef S9_SOLUCIONADOR_H
#define S9_SOLUCIONADOR_H


#include "SolucioSalts.h"
#include "CandidatsSalts.h"

class SolucionadorSalts
{
public:

    /**
     * @pre: --
     * @post: Construeix un Solucionador de SolucioSalts buit.
     */
    SolucionadorSalts();

    /**
     * @pre: --
     * @post: Construeix un Solucionador de SolucioSalts a partir d'un d'aquests.
     */
    explicit SolucionadorSalts(const SolucioSalts& s);

    /**
     * @pre: --
     * @post: Busca una camí des de (1,1) a (n,n) en la taula de la Sol·lucióSalts.
     */
    void trobar_una_solucio ();

    /**
     * @pre: --
     * @post: Retorna una llista de posicions que conté el camí que s'ha trobat aplicant l'algorisme.
     */
    std::list<SolucioSalts::posicio> cami() const;

private:

    /**
     * @pre: %act és una posició vàlida en la taula de la SolucioSalts %_sol.
     * @post: Busca una camí des de (1,1) a (n,n) en la taula de la Sol·lucióSalts i l'escriu a la %SolucioSalts.
     */
    void calcular_solucio(const CandidatsSalts::posicio& act);

    SolucioSalts _sol_actual, _sol_optima;
};


#endif //S9_SOLUCIONADOR_H
