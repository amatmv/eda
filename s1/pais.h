// Amat Martínez Vilà
// u1939654
// Sessió 1

#ifndef S1_PAIS_H
#define S1_PAIS_H

#include <iostream>
#include <vector>
#include "comarca.h"

using namespace std;

class Pais
{
public:

    //Pre: --;
    //Post: constructor per defecte
    Pais();

    //Pre: --;
    //Post: retorna el nombre de comarques que te el pais
    int nombre_comarques() const;

    //Pre: --;
    //Post: retorna el la extensio total del pais
    float extensio() const;

    //Pre: --;
    //Post: retorna el nombre d'habitants del pais
    int nombre_habitants() const;

    //Pre: --;
    //Post: llista les comarques que te el pais
    void llistar() const;

    //Pre: --;
    //Post: retorna un iterador constant a la primera comarca
    vector<Comarca>::const_iterator inici_iterador_comarques() const;

    //Pre: --;
    //Post: retorna un iterador constant a la ultima comarca
    vector<Comarca>::const_iterator fi_iterador_comarques() const;

    //Pre: c es una Comarca;
    //Post: afegeix una Comarca al vector a la posicio del codi d'aquesta
    void afegir_comarca(const Comarca& p);

private:
    int _num_comarques, _poblacio;
    float _extensio;
    vector<Comarca> _llista_comarques;

    void resize_vector(const int &n);
};

#endif //S1_PAIS_H
