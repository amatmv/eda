// Amat Martínez Vilà
// u1939654
// Sessió 6

#ifndef S2_MUNICIPI_H
#define S2_MUNICIPI_H

#include <iostream>
#include <set>
#include "EMD.h"

using namespace std;

/// @brief Classe que represente un minicipi, el qual té un codi, un nom, una població, una extensió.
class Municipi
{
public:

    /// @pre cert
    /// @post constructor per defecte.
    Municipi();

    /// @pre cert
    /// @post construeix un Municipi amb les dades donades per paràmetre.
    Municipi(const int& codi_comarca, const int& codi, const string& nom, const int& poblacio, const float& extensio);

    /// @pre cert
    /// @post retorna el codi del municipi
    int codi() const;

    /// @pre cert
    /// @post retorna el codi de la comarca a la qual pertany el municipi
    int codi_comarca() const;

    /// @pre cert
    /// @post retorna el nom del municipi
    string nom() const;

    /// @pre cert
    /// @post retorna la poblacio del municipi
    int poblacio() const;

    /// @pre cert
    /// @post retorna la extensió del municipi
    float extensio() const;

    /// @pre cert
    /// @post indexa una EMD al municipi
    void inserir_EMD(const EMD& e);

    /// @pre cert
    /// @post redefinició de sortida per a mostrar el municipi m
    friend ostream& operator << (ostream& o, const Municipi& m);

private:

    /// Codi de la comarca a la que pertany el municipi.
    int _codi_comarca;
    /// Codi del municipi
    int _codi;
    /// Nom del municipi
    string _nom;
    /// Nombre d'habitants del municipi actual
    int _poblacio;
    /// Extensió (en km²) del municipi
    float _extensio;
    /// Estructura de dades per emmagatzemar les Entitats Municipals Descentralitzades que pertanyen a aquest municipi.
    set<EMD> _emds;
};


#endif //S2_MUNICIPI_H
