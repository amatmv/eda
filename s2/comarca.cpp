// Amat Martínez Vilà
// u1939654
// Sessió 2

#include "comarca.h"

Comarca::Comarca()
{
    _codi = 0;
    _poblacio = 0;
    _extensio = 0;
    _nom = "desconeguda";
    _municipis_ordenats_per_densitat =  new list<Municipi>();
    _llista_municipis = list<Municipi>(1);
}

Comarca::Comarca(int codi, const string &nom)
{
    _codi = codi;
    _nom = nom;
    _poblacio = 0;
    _extensio = 0;
    _municipis_ordenats_per_densitat = new list<Municipi>();
    _llista_municipis = list<Municipi>(1);
}

void Comarca::afegir_municipi(const Municipi &m)
{
    if(!existeix(m))
    {
        _llista_municipis.push_back(m);
        _extensio += m.extensio();
        _poblacio += m.poblacio();
    }
}

bool Comarca::existeix(const Municipi &m) const
{
    return find(_llista_municipis.begin(), _llista_municipis.end(), m) != _llista_municipis.end();
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

Municipi Comarca::municipi_amb_mes_densitat() const
{
    return generar_llista_municipis_ordenats_per_densitat()->front();
}

Municipi Comarca::municipi_amb_menys_densitat() const
{
    Municipi temp, m(0,0,"desconegut",9999999,1);
    for (list<Municipi>::const_iterator it = _municipis_ordenats_per_densitat->begin(); it != _municipis_ordenats_per_densitat->end(); ++it) {
        if(it->nom() != "desconegut")
        {
            temp = *it;
            if(temp.densitat() < m.densitat() and temp.densitat() != -1)
                m = temp;
        }
    }
    return m;
}

ostream &operator << (ostream &o, const Comarca&p)
{
    cout.setf(ios::fixed);
    cout.precision(1);
    o << p._codi << ", " << p._nom << ", " << p._poblacio << ", " << p._extensio;
    return o;
}

list<Municipi>* Comarca::generar_llista_municipis_ordenats_per_densitat() const
{
    if(_municipis_ordenats_per_densitat->size() <= 1)
    {
        *_municipis_ordenats_per_densitat = _llista_municipis;
        _municipis_ordenats_per_densitat->sort(comparador_municipis_densitat);
    }
    return _municipis_ordenats_per_densitat;
}


bool Comarca::comparador_municipis_densitat(const Municipi &m1, const Municipi &m2)
{
    return m1.densitat() > m2.densitat();
}
