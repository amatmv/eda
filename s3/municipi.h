//
// Created by amat on 23/10/17.
//

#ifndef S2_MUNICIPI_H
#define S2_MUNICIPI_H

#include <iostream>
#include <set>
#include "EMD.h"

using namespace std;

class Municipi
{
public:

    Municipi();

    Municipi(const int& codi_comarca, const int& codi, const string& nom, const int& poblacio, const float& extensio);

    //Pre: --;
    //Post: retorna el codi del municipi
    int codi() const;

    //Pre: --;
    //Post: retorna el codi de la comarca a la qual pertany el municipi
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
    //Post: indexa una EMD al municipi
    void inserir_EMD(const EMD& e);

    //Pre: --;
    //Post: redefinició de sortida per a mostrar el municipi m
    friend ostream& operator << (ostream& o, const Municipi& m);

private:

    int _codi_comarca;
    int _codi;
    string _nom;
    int _poblacio;
    float _extensio;

    set<EMD> _emds;
};


#endif //S2_MUNICIPI_H
