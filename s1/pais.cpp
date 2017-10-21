// Amat Martínez Vilà
// u1939654
// Sessió 1

#include "pais.h"

Pais::Pais()
{
    _poblacio = _num_comarques = 0;
    _extensio = 0;
    _llista_comarques = vector<Comarca>();
}

int Pais::nombre_comarques() const
{
    return _num_comarques;
}

float Pais::extensio() const
{
    return _extensio;
}

int Pais::nombre_habitants() const
{
    return _poblacio;
}

vector<Comarca>::const_iterator Pais::inici_iterador_comarques() const
{
    return _llista_comarques.begin();
}

vector<Comarca>::const_iterator Pais::fi_iterador_comarques() const
{
    return _llista_comarques.end();
}

void Pais::afegir_comarca(const Comarca& c)
{
    if(c.codi() >= _llista_comarques.size())
        resize_vector(c.codi()+1);
    if(_llista_comarques[c.codi()].buida())
    {
        _llista_comarques[c.codi()] = c;
        _extensio += c.extensio();
        _poblacio += c.poblacio();
        _num_comarques++;
    }
}

void Pais::llistar() const
{
    for (vector<Comarca>::const_iterator comarca = _llista_comarques.begin(); comarca != _llista_comarques.end(); ++comarca)
        if(!comarca->buida())
            cout << *comarca << endl;
}

void Pais::resize_vector(const int &n)
{
    _llista_comarques.resize(n);
}