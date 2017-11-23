// Amat Martínez Vilà
// u1939654
// Sessió 6

#include "comarca.h"

Comarca::Comarca()
{
    _codi = 0;
    _poblacio = 0;
    _extensio = 0;
    _nom = "desconeguda";

}

Comarca::Comarca(int codi, const string &nom)
{
    _codi = codi;
    _nom = nom;
    _poblacio = 0;
    _extensio = 0;
}

void Comarca::inserir_municipi(const Municipi &m)
{
    if(!existeix(m))
    {
        _municipis.insert(m.codi());
        _extensio += m.extensio();
        _poblacio += m.poblacio();
    }
}

bool Comarca::existeix(const Municipi &m) const
{
    return _municipis.find(m.codi()) != _municipis.end();
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
