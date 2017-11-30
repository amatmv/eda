//
// Created by amat on 1/11/17.
//

#ifndef P1_INSTANT_TEMPORAL_H
#define P1_INSTANT_TEMPORAL_H

#include <iostream>
#include <ctime>

using namespace std;

class instant_temporal
{

public:

    /// @pre --
    /// @post constructor per defecte
    instant_temporal();

    /// @pre la cadena h ha de tenir el format HH:MM:SS
    /// @post construeix un instant temporal a partir de la cadena h
    explicit instant_temporal(const string& h);

    /// @pre --
    /// @post retorna la hora de l'instant
    short hora() const;

    /// @pre --
    /// @post retorna el minut de l'insant
    short minut() const;

    /// @pre --
    /// @post retorna el segon de l'instant
    short segon() const;

private:
    short _hores;
    short _minuts;
    short _segons;

};


#endif //P1_INSTANT_TEMPORAL_H
