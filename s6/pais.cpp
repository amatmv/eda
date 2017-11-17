// Amat Martínez Vilà
// u1939654
// Sessió 3

#include "pais.h"

Pais::Pais()
{
    _poblacio = 0;
    _extensio = 0;
    _comarques = map<int, Comarca>();
    _municipis = map<int, Municipi>();
    _indexos = new unordered_map<string, int>();
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

void Pais::inserir_municipi(const Municipi &m)
{
    _comarques[m.codi_comarca()].inserir_municipi(m);
    _indexos->insert(pair<string, int>(m.nom(), m.codi()));
    _municipis[m.codi()] = m;
    _extensio += m.extensio();
    _poblacio += m.poblacio();

}

bool Pais::existeix_municipi(const int& codi_municipi) const
{
    return _municipis.find(codi_municipi) != _municipis.end();
}

void Pais::llistar_comarques() const
{
    for (map<int, Comarca>::const_iterator comarca = _comarques.begin(); comarca != _comarques.end(); ++comarca)
        if(!comarca->second.buida())
            cout << comarca->second << endl;
}

void Pais::inserir_comarca(const Comarca &c)
{
    _comarques[c.codi()] = c;
    _num_comarques++;
}

void Pais::inserir_EMD(const EMD &e)
{
    if (existeix_municipi(e.codi_municipi()))
        _municipis[e.codi_municipi()].inserir_EMD(e);
}

void Pais::mostrar_info_municipi(const string &nom_municipi)
{
    int codi_municipi = (*_indexos)[nom_municipi];
    if(codi_municipi != 0)
    {
        Municipi m = _municipis[codi_municipi];
        cout << m;
    }
    else
        cout << "El municipi \"" << nom_municipi << "\" no existeix." << endl;
}
