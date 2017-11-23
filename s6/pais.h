// Amat Martínez Vilà
// u1939654
// Sessió 6

#ifndef S1_PAIS_H
#define S1_PAIS_H

#include <iostream>
#include <map>
#include <unordered_map>
#include "comarca.h"

using namespace std;

/// @brief Pais amb la seva extensió, població, número de comarques, comarques i municipis
class Pais
{
public:

    /// @pre cert
    /// @post constructor per defecte
    Pais();

    /// @pre cert
    /// @post retorna el nombre de comarques que té el pais
    int nombre_comarques() const;

    /// @pre cert
    /// @post retorna el la extensio total del pais
    float extensio() const;

    /// @pre cert
    /// @post retorna la poblacio total del pais
    int poblacio() const;

    /// @pre cert
    /// @post llista les comarques que te el pais
    void llistar_comarques() const;

    /// @pre cert
    /// @post retorna cert si el municipi  indicat per el codi existeix
    bool existeix_municipi(const int& codi_municipi) const;

    /// @pre cert
    /// @post mostra la informació del municipi en el cas que existeixi. Si no existeix mostra un missatge indicant-ho.
    void mostrar_info_municipi(const string& nom_municipi);

    /// @pre cert
    /// @post afegeix un Municipi al País
    void inserir_municipi(const Municipi &m);

    /// @pre cert
    /// @post afegeix una EMD al municipi corresponent. Si no existeix, no fa res
    void inserir_EMD(const EMD &m);

    /// @pre cert
    /// @post afegeix una Comarca País
    void inserir_comarca(const Comarca &m);

private:

    /// Extensió (en km²) del país.
    float _extensio;
    /// Nombre d'habitants del país.
    int _poblacio;
    /// Nombre de comarques que conté el país.
    int _num_comarques;
    /// Contenidor dels municipis que conté el país, indexats per el seu codi.
    map<int, Municipi> _municipis;
    /// Contenidor de les comarques que té el país, indexats per el seu codi.
    map<int, Comarca> _comarques;
    /// Estructura de dades que indexa els municipis segons el seu nom i en retorna el seu codi.
    unordered_map<string, int>* _indexos;
};

#endif //S1_PAIS_H
