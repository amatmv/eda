//
// Created by amat on 27/10/17.
//

#include "EMD.h"

EMD::EMD()
{
    _codi_municipi = 0;
    _codi = "";
    _nom = "desconegut";
}

EMD::EMD(const int& codi_municipi, const string& codi, const string& nom)
{
    _codi_municipi = codi_municipi;
    _codi = codi;
    _nom = nom;
}

int EMD::codi_municipi() const
{
    return _codi_municipi;
}

string EMD::codi() const
{
    return _codi;
}

string EMD::nom() const
{
    return _nom;
}

bool EMD::operator<(const EMD &e) const
{
    return _codi < e._codi;
}

ostream& operator << (ostream& o, const EMD& e)
{
    o << e._nom << endl
      << "\t - Codi: " << e._codi << endl
      << "\t - CP del municipi al que pertany: " << e._codi_municipi << endl;
    return o;
}
