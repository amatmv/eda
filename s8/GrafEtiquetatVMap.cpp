// Amat Martínez Vilà
// u1939654
// Sessió 8

#include <sstream>
#include <list>
#include "GrafEtiquetatVMap.h"


GrafEtiquetatVMap::GrafEtiquetatVMap(int nVertexs, bool dirigit)
{
    construir_graf(nVertexs);
    _dirigit = dirigit;
}

GrafEtiquetatVMap::GrafEtiquetatVMap(const char *nomFitxerTGF, bool dirigit)
{
    _dirigit = dirigit;
    ifstream file;
    file.open(nomFitxerTGF,ifstream::in);
    if (file.fail())
        throw("Fitxer no trobat");
    string s;
    int nVertexs = 0;
    while (getline(file,s) and s!="#")
        nVertexs++;
    construir_graf(nVertexs);
    int v1 = 0, v2 = 0;
    while (file >> v1 >> v2 and !file.eof())
        AfegirAresta(v1, v2);
    file.close();
}

int GrafEtiquetatVMap::nVertexs() const
{
    return _nVertexs;
}

int GrafEtiquetatVMap::n_veins(int v) const
{
    if (!esValid(v))
        throw("No existeix el vèrtex.");
    return _arestes[v].first.size();
}

int GrafEtiquetatVMap::nArestes() const
{
    return _nArestes;
}

bool GrafEtiquetatVMap::esDirigit() const
{
    return _dirigit;
}

bool GrafEtiquetatVMap::ExisteixAresta(int v1, int v2) const
{
    if (!esValid(v1) or !esValid(v2))
        return false;
    else
        return (_arestes[v1].first.end() != find(_arestes[v1].first.begin(), _arestes[v1].first.end(), v2));
}

void GrafEtiquetatVMap::AfegirAresta(int v1, int v2)
{
    if (!esValid(v1) or !esValid(v2))
        throw("ERROR: v1 o v2 no existeixen.");
    else if (!ExisteixAresta(v1,v2))
    {
        _arestes[v1].first.push_back(v2);
        _nArestes++;
        if (!_dirigit)
            _arestes[v2].first.push_back(v1);
    }
}

void GrafEtiquetatVMap::EsborrarAresta(int v1, int v2)
{
    if (!esValid(v1))
        throw("ERROR. El vèrtex v1 no existeix.");
    auto it_aresta = find(_arestes[v1].first.begin(), _arestes[v1].first.end(), v2);
    if (it_aresta != _arestes[v1].first.end())
    {
        _arestes[v1].first.erase(it_aresta);
        _nArestes--;
        if (!_dirigit)
            EsborrarAresta(v2, v1);
    }
}

bool GrafEtiquetatVMap::esValid(int v) const
{
    return v >= 1 and v <= _nVertexs;
}

void GrafEtiquetatVMap::construir_graf(const int &nVertexs)
{
    if (nVertexs < 1)
        throw("El nombre de vèrtexs ha de ser major de 0.");
    _nVertexs = nVertexs;
    _arestes = vector<pair<list<int>, etiqueta>>(nVertexs+1);
    for (int i = 1; i <= nVertexs; i++)
        _arestes[i] = pair<list<int>, etiqueta>();
}

void GrafEtiquetatVMap::AfegirEtiqueta(int v, etiqueta c)
{
    if (!esValid(v))
        throw("ERROR: v no existeix.");
    _arestes[v].second = c;
}

etiqueta GrafEtiquetatVMap::ObtenirEtiqueta(int v) const
{
    if (!esValid(v))
        throw("ERROR: v no existeix.");
    return _arestes[v].second;
}
