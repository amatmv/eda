// Amat Martínez Vilà
// u1939654
// Sessió 3

#ifndef S1_COMARCA_H
#define S1_COMARCA_H

#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
#include "municipi.h"

using namespace std;

/// @brief Classe que re/ @presenta una comarca i n'emmagatzema la seva informació
class Comarca
{
public:

    /// @pre: cert
    /// @post retorna el nombre de comarques que te el pais
    Comarca();

    /// @pre: cert
    /// @post retorna el nombre de comarques que te el pais
    Comarca(int codi, const string &nom);

    /// @pre: cert
    /// @post retorna el codi de la comarca actual
    int codi() const;

    /// @pre: cert
    /// @post retorna el nom de la comarca
    string nom() const;

    /// @pre: cert
    /// @post retorna la extensio de la comarca
    float extensio() const;

    /// @pre: cert
    /// @post retorna la poblacio de la comarca
    int poblacio() const;

    /// @pre: cert
    /// @post retorna cert si la comarca conte les dades del constructor per defecte; fals altrament
    bool buida() const;

    /// @pre: cert
    /// @post retorna cert si el Municipi es troba a la comarca, fals altrament
    bool existeix(const Municipi &m) const;

    /// @pre: cert
    /// @post afegeix un Municipi a la comarca
    void inserir_municipi(const Municipi &m);

    /// @pre: cert
    /// @post redefinició de l'operador de sortida / @predeterminat
    friend ostream& operator << (ostream& o, const Comarca& p);

private:

    /// Estructura de dades que emmagatzema els municipis que pertanyen a la comarca.
    set<int> _municipis;
    /// Codi de la comarca.
    int _codi;
    /// Nombre d'habitants de la comarca.
    int _poblacio;
    /// Nom de la comarca.
    string _nom;
    /// Extensió (en km²) de la comarca.
    float _extensio;
};

#endif //S1_COMARCA_H
