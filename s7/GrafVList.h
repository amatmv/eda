#ifndef S7_GRAFVLIST_H
#define S7_GRAFVLIST_H

#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MIDA_DEFECTE = 1000;

class GrafVList
{
public:

    explicit GrafVList(int nVertexs = MIDA_DEFECTE, bool dirigit = false);

    explicit GrafVList(const char *nomFitxerTGF, bool dirigit = false);

    int nVertexs() const;

    int nArestes() const;

    bool esDirigit() const;

    // Pre: v1 i v2 son vertexs del graf
    // Post: afegeix l'aresta (v1,v2) si no existia
    void AfegirAresta(int v1, int v2);

    // Pre: cert
    // Post: diu si hi ha aresta de v1 a v2
    bool ExisteixAresta(int v1, int v2) const;

    void EsborrarAresta ( int v1, int v2);

    void EscriureGraf(const char *nomFitxerTGF) const;

private:
    int _nVertexs; // = _arestes.size()-1 (despreciem element 0)
    int _nArestes;
    bool _dirigit;
    vector<list<int>> _arestes; // veïns o successors (depenent si dirigit)
    bool esValid(int v) const;

    void construir_graf(const int &nVertexs);
};


#endif //S7_GRAFVLIST_H
