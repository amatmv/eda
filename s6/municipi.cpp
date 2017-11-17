//
// Created by amat on 23/10/17.
//

#include <cfloat>
#include "municipi.h"


Municipi::Municipi()
{
    _codi_comarca = 0;
    _nom = "desconegut";
    _codi = 0;
    _poblacio = 0;
    _extensio = 0;
    _emds = set<EMD>();
}

Municipi::Municipi(const int& codi_comarca, const int& codi, const string& municipi, const int& poblacio, const float& extensio)
{
    _codi_comarca = codi_comarca;
    _nom = municipi;
    _codi = codi;
    _poblacio = poblacio;
    _extensio = extensio;
    _emds = set<EMD>();
}

int Municipi::codi() const
{
    return _codi;
}

string Municipi::nom() const
{
    return _nom;
}

int Municipi::poblacio() const
{
    return _poblacio;
}

float Municipi::extensio() const
{
    return _extensio;
}

int Municipi::codi_comarca() const
{
    return _codi_comarca;
}

void Municipi::inserir_EMD(const EMD &e)
{
    /*
     * Es podria augmentar la població i la extensió del municipi afegint la de les EMDs,
     * però l'enunciat no especifica.
     */
    _emds.insert(e);
}

ostream& operator << (ostream& o, const Municipi& m)
{
    o << "====== " << m._nom << " ======" << endl;
    o << "\t- Codi Postal: " << m._codi << endl;
    o << "\t- Extensió: " << m._extensio << endl;
    o << "\t- Poblacio: " << m._poblacio << endl;
    if (!m._emds.empty())
    {
        o << "\n\tLes EMDs de " << m._nom << " són:" << endl;
        for (set<EMD>::const_iterator it = m._emds.begin(); it != m._emds.end() ; ++it)
            o << "\t" << *it;
    }
    return o;
}
