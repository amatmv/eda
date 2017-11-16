// Amat Martínez Vilà
// u1939654
// Sessió 2

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
    //Post: retorna el nombre de comarques que té el pais
    int nombre_comarques() const;

    //Pre: --;
    //Post: retorna el la extensio total del pais
    float extensio() const;

    //Pre: --;
    //Post: retorna la poblacio total del pais
    int poblacio() const;

    //Pre: --;
    //Post: llista les comarques que te el pais
    void llistar() const;

    //Pre: codi és el codi d'una comarca que existeix
    //Post: retorna la comarca associada al codi indicat.
    Comarca obtenir_comarca(int codi) const;

    //Pre: --
    //Post: retorna el municipi amb més densitat del país
    Municipi municipi_amb_mes_densitat() const;

    //Pre: --
    //Post: retorna el municipi amb menys densitat del país
    Municipi municipi_amb_menys_densitat() const;

    //Pre: --
    //Post: afegeix un Municipi al País
    void afegir_municipi(const Municipi& m);

    //Pre:
    //Post: afegeix una Comarca País
    void afegir_comarca(const Comarca&m);

private:

    vector<Comarca>* generar_llista_comarques_ordenades_per_densitat() const;

    static bool comparador_comarques_densitat(const Comarca &c1, const Comarca &c2);

    float _extensio;
    int _poblacio;
    int _num_comarques;

    vector<Comarca> _llista_comarques;

    vector<Comarca> *_comarques_ordenades_per_densitat;

    void resize_vector(const int &n);
};

#endif //S1_PAIS_H
