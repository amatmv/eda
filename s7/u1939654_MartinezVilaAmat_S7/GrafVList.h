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

    // pre: cert
    // post: a partir d'un nombre de vèrtexs i un booleà, construeix el graf.
    explicit GrafVList(int nVertexs = MIDA_DEFECTE, bool dirigit = false);

    // pre: el fitxer amb nom: nomFitxerTGF, ha d'existir.
    // post: llegeix fitxer amb nom: nomFitxerTGF i en construeix el graf.
    //       Llança una excepció si el fitxer no existeix.
    explicit GrafVList(const char *nomFitxerTGF, bool dirigit = false);

    // pre: cert
    // post: retorna el nombre de vèrtexs del graf
    int nVertexs() const;

    // pre: cert
    // post: retorna el nombre d'arestes del graf.
    int nArestes() const;

    // pre: cert
    // post: retorna cert si el graf és dirigit; fals altrament.
    bool esDirigit() const;

    // Pre: v1 i v2 son vertexs del graf
    // Post: afegeix l'aresta (v1,v2) si no existia
    void AfegirAresta(int v1, int v2);

    // Pre: v1 i v2 son vertexs del graf
    // Post: diu si hi ha aresta de v1 a v2
    bool ExisteixAresta(int v1, int v2) const;

    // pre: v1 i v2 son vertexs del graf
    // post: esborra l'aresta entre v1 i v2
    void EsborrarAresta ( int v1, int v2);

    // pre: cert
    // post: escriu el graf en el fitxer amb nom: nomFitxerTGF.
    void EscriureGraf(const char *nomFitxerTGF) const;

    // pre: v es un vertex del graf
    // post: retorna el nombre de veins del vertex
    int n_veins(int v) const;

private:

    int _nVertexs; // = _arestes.size()-1 (despreciem element 0)
    int _nArestes;
    bool _dirigit;
    vector<list<int>> _arestes; // veïns o successors (depenent si dirigit)

    // pre: cert
    // post: retorna si v és un vèrtexs del graf.
    bool esValid(int v) const;

    // pre: nVertexs > 0
    // post: inicialitza totes les estructures de dades del graf a partir del nombre de vèrtexs.
    void construir_graf(const int &nVertexs);
};


#endif //S7_GRAFVLIST_H
