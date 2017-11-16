// Amat Martínez Vilà
// u1939654
// Sessió 2

#ifndef S1_COMARCA_H
#define S1_COMARCA_H

#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
#include "municipi.h"

using namespace std;

class Comarca
{
public:

    //Pre: --;
    //Post: retorna el nombre de comarques que te el pais
    Comarca();

    //Pre: --;
    //Post: retorna el nombre de comarques que te el pais
    Comarca(int codi, const string &nom);

    //Pre: --
    //Post: retorna el codi de la comarca actual
    int codi() const;

    //Pre: --
    //Post: retorna el nom de la comarca
    string nom() const;

    //Pre: --
    //Post: retorna la extensio de la comarca
    float extensio() const;

    //Pre: --
    //Post: retorna la poblacio de la comarca
    int poblacio() const;

    //Pre: --
    //Post: retorna cert si la comarca conte les dades del constructor per defecte; fals altrament
    bool buida() const;

    //Pre: --
    //Post: retorna el municipi amb menys densitat del país
    Municipi municipi_amb_mes_densitat() const;

    //Pre: --
    //Post: retorna el municipi amb menys densitat del país
    Municipi municipi_amb_menys_densitat() const;

    //Pre: --
    //Post: retorna cert si el Municipi es troba a la comarca, fals altrament
    bool existeix(const Municipi &m) const;

    //Pre: --
    //Post: afegeix un Municipi a la comarca
    void afegir_municipi(const Municipi &m);

    //Pre: --
    //Post: redefinició de l'operador de sortida predeterminat
    friend ostream& operator << (ostream& o, const Comarca& p);

private:


    static bool comparador_municipis_densitat(const Municipi &m1, const Municipi &m2);

    list<Municipi>* generar_llista_municipis_ordenats_per_densitat() const;

    /*emmagatzema els municipis ordenats per densitat una vegada calculats per a no tornar-los a calcular*/
    list<Municipi>* _municipis_ordenats_per_densitat;

    list<Municipi> _llista_municipis;
    int _codi, _poblacio;
    string _nom;
    float _extensio;
};

#endif //S1_COMARCA_H
