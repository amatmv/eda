//
// Created by amat on 23/10/17.
//

#ifndef S2_MUNICIPI_H
#define S2_MUNICIPI_H

#include <iostream>

using namespace std;

class Municipi
{
public:

    Municipi();

    Municipi(int codi_comarca, int codi, string nom, int poblacio, float extensio);

    //Pre: --;
    //Post: retorna el codi del municipi
    int codi() const;

    //Pre: --;
    //Post: retorna el codi de la comarca
    int codi_comarca() const;

    //Pre: --;
    //Post: retorna el nom del municipi
    string nom() const;

    //Pre: --;
    //Post: retorna la poblacio del municipi
    int poblacio() const;

    //Pre: --;
    //Post: retorna la extensió del municipi
    float extensio() const;

    //Pre: --;
    //Post: retorna la densitat d'habitants del municipi
    float densitat() const;

    bool operator==(const Municipi &m) const;

private:

    int _codi_comarca;
    int _codi;
    string _nom;
    int _poblacio;
    float _extensio;
};


#endif //S2_MUNICIPI_H
