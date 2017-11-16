// Amat Martínez Vilà
// u1939654
// Sessió 3

#ifndef S1_PAIS_H
#define S1_PAIS_H

#include <iostream>
#include <map>
#include <unordered_map>
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
    void llistar_comarques() const;

    //Pre: --;
    //Post: retorna cert si el municipi  indicat per el codi existeix
    bool existeix_municipi(const int& codi_municipi) const;

    //Pre: --;
    //Post: mostra la informació del municipi en el cas que existeixi. Si no existeix mostra un missatge indicant-ho.
    void mostrar_info_municipi(const string& nom_municipi);

    //Pre: --
    //Post: afegeix un Municipi al País
    void inserir_municipi(const Municipi &m);

    //Pre: --
    //Post: afegeix una EMD al municipi corresponent. Si no existeix, no fa res
    void inserir_EMD(const EMD &m);

    //Pre:
    //Post: afegeix una Comarca País
    void inserir_comarca(const Comarca &m);

private:

    float _extensio;
    int _poblacio;
    int _num_comarques;
    map<int, Municipi> _municipis;
    map<int, Comarca> _comarques;
    unordered_map<string, int>* _indexos;
};

#endif //S1_PAIS_H
