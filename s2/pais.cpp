// Amat Martínez Vilà
// u1939654
// Sessió 2

#include "pais.h"

Pais::Pais()
{
    _poblacio = 0;
    _extensio = 0;
    _llista_comarques = vector<Comarca>();
    _comarques_ordenades_per_densitat = new vector<Comarca>();
    _num_comarques = 0;
}

int Pais::nombre_comarques() const
{
    return _num_comarques;
}

float Pais::extensio() const
{
    return _extensio;
}

int Pais::poblacio() const
{
    return _poblacio;
}

void Pais::afegir_municipi(const Municipi&m)
{
    if(m.codi_comarca() < _llista_comarques.size())
    {
        _llista_comarques[m.codi_comarca()].afegir_municipi(m);
        _extensio += m.extensio();
        _poblacio += m.poblacio();
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

void Pais::afegir_comarca(const Comarca &c)
{
    if(c.codi() >= _llista_comarques.size())
        resize_vector(c.codi()+1);
    if(_llista_comarques[c.codi()].buida())
    {
        _llista_comarques[c.codi()] = c;
        _num_comarques++;
    }
}

Comarca Pais::obtenir_comarca(int codi) const
{
    return _llista_comarques[codi];
}

Municipi Pais::municipi_amb_mes_densitat() const
{
    if(_comarques_ordenades_per_densitat->empty())
        generar_llista_comarques_ordenades_per_densitat();
    return _comarques_ordenades_per_densitat->front().municipi_amb_mes_densitat();
}

Municipi Pais::municipi_amb_menys_densitat() const
{
    Municipi m(0,0,"desconegut",9999999,1), temp;
    for (vector<Comarca>::const_iterator it = _llista_comarques.begin(); it != _llista_comarques.end(); ++it) {
        temp = it->municipi_amb_menys_densitat();
        if(temp.densitat() < m.densitat())
            m = temp;
    }
    return m;
}

vector<Comarca>* Pais::generar_llista_comarques_ordenades_per_densitat() const
{
    if(_comarques_ordenades_per_densitat->empty())
    {
        *_comarques_ordenades_per_densitat = _llista_comarques;
        sort(
                _comarques_ordenades_per_densitat->begin(),
                _comarques_ordenades_per_densitat->end(),
                comparador_comarques_densitat
        );
    }
    return _comarques_ordenades_per_densitat;
}

bool Pais::comparador_comarques_densitat(const Comarca &c1, const Comarca &c2)
{
    return c1.municipi_amb_mes_densitat().densitat() > c2.municipi_amb_mes_densitat().densitat();
}


