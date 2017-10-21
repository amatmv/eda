// Amat Martínez Vilà
// u1939654
// Sessió 1

#include "comarca.h"

Comarca::Comarca(){
    _codi = 0;
    _poblacio = 0;
    _extensio = 0;
    _nom = "desconeguda";
}

Comarca::Comarca(int codi, const string &nom, int poblacio, float extensio)
{
    _codi = codi;
    _nom = nom;
    _poblacio = poblacio;
    _extensio = extensio;
}

int Comarca::codi() const
{
    return _codi;
}

int Comarca::poblacio() const
{
    return _poblacio;
}

string Comarca::nom() const
{
    return _nom;
}

float Comarca::extensio() const
{
    return _extensio;
}

bool Comarca::buida() const
{
    return _nom == "desconeguda";
}

ostream &operator << (ostream &o, const Comarca&p)
{
    cout.setf(ios::fixed);
    cout.precision(1);
    o << p._codi << ", " << p._nom << ", " << p._poblacio << ", " << p._extensio;

    return o;
}
