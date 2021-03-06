//
// Created by amat on 12/12/17.
//

#ifndef S9_SOLUCIO_H
#define S9_SOLUCIO_H

#include <vector>
#include <list>
#include "CandidatsSalts.h"

class SolucioSalts
{
public:

    typedef CandidatsSalts::posicio posicio;

    /**
     * @pre: --
     * @post: Construeix una %SolucioSalts buida.
     */
    SolucioSalts() = default;

    /**
     * @pre: --
     * @post: Construeix una %SolucioSalts a partir de una matriu bidimensional %v.
     */
    explicit SolucioSalts(const std::vector<std::vector<int>>& v);

    /**
     * @pre: --
     * @post: Retorna cert si el candidat es pot afegir a la solució
     */
    bool acceptable(const CandidatsSalts& iCan) const;

    /**
     * @pre: --
     * @post: Retorna cert si la sol·lució és completa
     */
    bool completa () const;

    /**
     * @pre: --
     * @post: Retorna una llista de posicions que és el camí que va des de (1,1) a (n,n).
     */
    std::list<posicio> cami() const;

    /**
     * @pre: --
     * @post: Inicialitza un conjunt de candidats relatius a la posició %pos.
     */
    CandidatsSalts inicialitzar_conjunt_candidats(const posicio& pos) const;

    /**
     * @pre: iCan és acceptable
     * @post: Anota la posició de l'iterador iCan a la Solució
     */
    void anotar(const CandidatsSalts& iCan);

    /**
     * @pre: --
     * @post: Desanota la posició de l'iterador iCan a la Solució
     */
    void desanotar(const CandidatsSalts &iCan);

private:

    /**
     * @pre: --
     * @post: Retorna cert si el la posició és dins el tauler.
     */
    bool es_posicio_valida(const posicio& pos) const;

    /**
     * @pre: --
     * @post: Retorna cert si la posició %pos de la matriu ha estat visitada.
     */
    bool es_posicio_visitada(const posicio& pos) const;

    std::vector<std::vector<bool>> _visitats;
    std::vector<std::vector<int>> _matriu;
    std::list<posicio> _salts;
};


#endif //S9_SOLUCIO_H
