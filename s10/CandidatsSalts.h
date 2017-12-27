//
// Created by amat on 12/12/17.
//

#ifndef S9_CANDIDATSSALTS_H
#define S9_CANDIDATSSALTS_H

#include <iostream>

class CandidatsSalts
{
public:

    /**
     * @brief: Estructura de dades que representa les coordenades
     * d'una posició, sobre les quals itera el Conjunt de Candidats
     */
    struct posicio
    {
        int x;
        int y;
        posicio ():
                x(0), y(0) {}
        posicio (int j, int i):
                x(j), y(i) {}

        posicio operator*(const int& n);
        posicio operator+(const posicio& p);
        int operator-(const posicio& p);
    };

    /**
     * @pre: --
     * @post: Construeix un Conjunt de Candidats a partir de la posició actual i el valor d'aquesta.
     */
    explicit CandidatsSalts (const posicio& p_act, const int& v_act);

    /**
     * @pre: --
     * @post: Incrementa l'iterador dels candidats que conté la classe.
     */
    void seguent ();

    /**
     * @pre: --
     * @post: Retorna cert si l'iterador ha arribat al final.
     */
    bool es_fi () const;

    /**
     * @pre: --
     * @post: Retorna el valor de la posició actual.
     */
    posicio actual () const;

private:
    const posicio DESPLACAMENTS[4] = {
            posicio(0,-1),
            posicio(1,0),
            posicio(0,1),
            posicio(-1,0),
    };
    int _iCan;
    int _v_ant;
    posicio _pos_actual;
};


#endif //S9_CANDIDATSSALTS_H
