//
// Created by amat on 27/10/17.
//

#ifndef S3_EMD_H
#define S3_EMD_H

#include <iostream>

using namespace std;

/// @brief Una EMD representa una Entitat Municipal Descentralitada, que és un nucli urbà que no està adjunt al terme d'un municipi.
class EMD
{
public:

    /// @pre cert
    /// @post constructor per defecte de EMD
    EMD();

    /// @pre cert
    /// @post constructor amb paràmetres de EMD
    EMD(const int& codi_municipi, const string& codi, const string& nom);

    /// @pre cert
    /// @post retorna el codi postal del municipi actual
    int codi_municipi() const;

    /// @pre cert
    /// @post retorna el codi del municipi actual
    string codi() const;

    /// @pre cert
    /// @post retorna el nom del municipi actual
    string nom() const;

    /// @pre cert
    /// @post comparador de EMDs segons el codi
    bool operator< (const EMD&e) const;

    /// @pre cert
    /// @post redefinició de sortida per a mostrar la EMD e
    friend ostream& operator << (ostream& o, const EMD& e);

private:
    /// Codi del municipi al que pertanyen
    int _codi_municipi;
    /// Codi de la EMD
    string _codi;
    /// Nom de la EMD
    string _nom;
};


#endif //S3_EMD_H
