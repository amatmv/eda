//
// Created by amat on 1/11/17.
//

#ifndef P1_DATA_H
#define P1_DATA_H

#include <iostream>
#include <ctime>

using namespace std;

class data
{
public:

    //Pre: --
    //Post: constructor per defecte de la data
    data();

    //Pre: d és una cadena del format 'DD/MM/YYYY'
    //Post: construeix una data a partir de la cadena d
    explicit data(const string& d);

    //Pre: --
    //Post: retorna el dia de la data
    short dia() const;

    //Pre: --
    //Post: retorna el mes de la data
    short mes() const;

    //Pre: --
    //Post: retorna l'any de la data
    short any() const;

    //Pre: --
    //Post: redefineix l'operador d'igualtat
    bool operator==(const data &rhs) const;

private:

    short _dia;
    short _mes;
    short _any;

};

namespace std
{
    template <>
    struct hash<data>
    {
        //Pre: --
        //Post: redefinició del hasher de la data
        size_t operator()(const data& k) const
        {
            return ((hash<short>()(k.any())
                     ^ (hash<short>()(k.mes()) << 1)) >> 1)
                   ^ (hash<short>()(k.dia()) << 1);
        }
    };

}


#endif //P1_DATA_H
