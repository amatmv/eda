#ifndef P2_SOLUCIONADAL_H
#define P2_SOLUCIONADAL_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

#include "CandidatsTaula.h"

class SolucioNadal 
{
public:

    SolucioNadal();

    explicit SolucioNadal(const int& tamany,
                          const std::vector<std::vector<int>>& aversions,
                          const std::string* convidats);

    explicit SolucioNadal(const int& tamany,
                          const int& aversio,
                          const std::vector<std::vector<int>>& aversions,
                          const std::string* convidats);

    /**
     * @pre: --
     * @post: Retorna cert si el candidat es pot afegir a la solució
     */
    bool acceptable(const CandidatsTaula& iCan) const;

    /**
     * @pre: --
     * @post: Retorna cert si el candidat es pot afegir a la solució segons l'algorisme de backtracking òptim
     */
    bool acceptableOptim(const CandidatsTaula &iCan) const;

    /**
     * @pre: --
     * @post: Retorna cert si la sol·lució és completa
     */
    bool completa() const;

    /**
     * @pre: --
     * @post: Retorna cert si la sol·lució actual és millor que %optima
     */
    bool esMillor(const SolucioNadal& optima) const;

    /**
     * @pre: --
     * @post: Retorna cert si la sol·lució actual es pot millorar
     */
    bool esPotMillorar(const SolucioNadal &optima);

    /**
     * @pre: --
     * @post: Inicialitza un conjunt de candidats que representen convidats del sopar
     */
    CandidatsTaula inicialitzarConjuntCandidats() const;

    /**
     * @pre: --
     * @post: Mostra la disposició dels convidats a la taula
     */
    void mostrar() const;

    /**
     * @pre: iCan és acceptable
     * @post: Anota la posició de l'iterador iCan a la Solució
     */
    void anotar(const CandidatsTaula& iCan);

    /**
     * @pre: --
     * @post: Desanota la posició de l'iterador iCan a la Solució
     */
    void desanotar(const CandidatsTaula &iCan);

    SolucioNadal operator=(SolucioNadal s);
private:

    typedef std::pair<int, int> posicio;

    /// Posicio de la recursio actual
    std::pair<int,int> _nivell;
    /// Estructura de dades que emmagatzema els convidats, juntament amb si han estat asseguts o no
    std::vector<std::pair<std::string,bool>> _convidats;
    /// Estructura de dades per a emmagatzemar la màxima aversió per a cada un dels convidats
    std::vector<int> _max_aversions;
    /// Taula on s'asseuen els convidats. Sempre es de tamany: (n_convidats/2) x 3
    int** _taula;
    /// Nombre de candidats a asseure
    int _n_convidats;
    /// Matriu d'aversions entre els convidats, tamany: n_convidats x n_convidats
    std::vector<std::vector<int>> _aversions;
    /// Maxima aversio, la qual no es pot superar.
    int _max_aversio;
    /// Suma de aversions totals
    int _total_aversio;

    /**
     * @pre: a < %_n_convidats && b < %_n_convidats
     * @post: retorna si a i b no superen el límit d'aversió
     */
    bool compatibles(const int& a, const int& b) const;

    /**
     * @pre: --
     * @post: crea i reserva espai per a les estructures de dades i atributs
     */
    void construirEstructures(const int &tamany,
                              const std::vector<std::vector<int>> &vector,
                              const std::string *convidats);

    /**
     * @pre: %pos_act és una posició de la taula
     * @post: retorna una llista amb els convidats que són veins del convidat assegut a %pos_act
     */
    std::vector<int> convidatsVeins(const posicio &pos_act) const;

    /**
     * @pre: %pos_act és una posició de la taula
     * @post: retorna una llista amb les posicions veines de %pos_act
     */
    std::vector<posicio> posicionsVeines(const posicio &pos_actual) const;

    /**
     * @pre: %convidat_actual < _n_convidats && %pos_actual és una posició de la taula
     * @post: actualitza el valor de màxima aversió del convidat actual
     */
    void actualitzarMaximesAversions(const int &convidat_actual, const posicio& pos_actual);

    /**
     * @pre: %convidat_actual < _n_convidats && %pos_actual és una posició de la taula
     * @post: actualitza els valors de màxima aversió dels veins del convidat actual
     */
    void actualitzarMaximesAversionsVeins(const int &convidat_actual, const posicio &pos_actual);
};


#endif //P2_SOLUCIONADAL_H
