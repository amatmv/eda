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

    //Pre: --
    //Post: constructor per defecte
    instant_temporal();

    //Pre: la cadena h ha de tenir el format HH:MM:SS
    //Post: construeix un instant temporal a partir de la cadena h
    explicit instant_temporal(const string& h);

    //Pre: --
    //Post: retorna la hora de l'instant
    short hora() const;

    //Pre: --
    //Post: retorna el minut de l'insant
    short minut() const;

    //Pre: --
    //Post: retorna el segon de l'instant
    short segon() const;

private:
    short _hores;
    short _minuts;
    short _segons;

};


#endif //P1_INSTANT_TEMPORAL_H
