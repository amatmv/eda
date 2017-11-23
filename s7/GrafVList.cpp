// Amat Martínez Vilà
// u1939654
// Sessió 7

#include "GrafVList.h"


GrafVList::GrafVList(int nVertexs, bool dirigit)
{
    construir_graf(nVertexs);
    _dirigit = dirigit;
}

GrafVList::GrafVList(const char *nomFitxerTGF, bool dirigit)
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

int GrafVList::nVertexs() const
{
    return _nVertexs;
}

int GrafVList::nArestes() const
{
    return _nArestes;
}

bool GrafVList::esDirigit() const
{
    return _dirigit;
}

bool GrafVList::ExisteixAresta(int v1, int v2) const
{
    if (!esValid(v1) or !esValid(v2))
        return false;
    else
        return (_arestes[v1].end() != find(_arestes[v1].begin(), _arestes[v1].end(), v2));
}

void GrafVList::AfegirAresta(int v1, int v2)
{
    if (!esValid(v1) or !esValid(v2))
        throw("ERROR: v1 o v2 no existeixen.");
    else if (!ExisteixAresta(v1,v2))
    {
        _arestes[v1].push_back(v2);
        _nArestes++;
        if (!_dirigit)
            _arestes[v2].push_back(v1);
    }
}

void GrafVList::EsborrarAresta(int v1, int v2)
{
    if (!esValid(v1))
        throw("ERROR. El vèrtex " + to_string(v1) + " no existeix.");
    auto it_aresta = find(_arestes[v1].begin(), _arestes[v1].end(), v2);
    if (it_aresta != _arestes[v1].end())
    {
        _arestes[v1].erase(it_aresta);
        _nArestes--;
        if (!_dirigit)
            EsborrarAresta(v2, v1);
    }
}

void GrafVList::EscriureGraf(const char *nomFitxerTGF) const
{
    ofstream f_sort;
    f_sort.open(nomFitxerTGF, ofstream::out);
    if (f_sort.fail())
        cerr << "Ha fallat l'escriptura del fitxer:" << nomFitxerTGF;
    else
    {
        for (int i = 1; i <= _nVertexs; i++)
            f_sort << i << '\n';
        f_sort << '#' << '\n';
        for (int i = 1; i <= _nVertexs ; i++)
            for (auto it = _arestes[i].begin(); it != _arestes[i].end(); it++)
                f_sort << i << ' ' << *it << '\n';
        f_sort.close();
    }
}

bool GrafVList::esValid(int v) const
{
    return v >= 1 and v <= _nVertexs;
}

void GrafVList::construir_graf(const int &nVertexs)
{
    _nVertexs = nVertexs;
    _arestes = vector<list<int>>(nVertexs+1);
    for (int i = 1; i <= nVertexs; i++)
        _arestes[i] = list<int>();
}
