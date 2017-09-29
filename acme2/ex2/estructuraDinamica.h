/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell & David Figuls on Wed Oct 06 2004.
 *  Copyright (c) 2004 __MyCompanyName__. All rights reserved.
 *
 * IMPORTANT:
 * Aquest fitxer es comu a tots els programes que usen l'estructura dinamica
 * simplement encadenada. Cal implementar nomes els metodes que demana cada 
 * enunciat. 
 */

#ifndef TAD_estructuraDinamicaSentinellaFinal_h
#define TAD_estructuraDinamicaSentinellaFinal_h


#include <cstdlib>
#include <iostream>
using namespace std;

struct node
{
    int dada;
    node *seguent;
};

class estructuraDinamica  // Final
{
    node * inici;
    node * final;
public:
	estructuraDinamica();
    estructuraDinamica(estructuraDinamica & e);
    
    void AfegirInici(int i);
    void AfegirFinal(int i);
    void InserirOrdenadament(int i);

    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    
    void Esborrar(int i);
    bool Existeix(int i) const;

	void OmplirInici(int n);
	int TreureFinal();
	void OmplirFinal(int n);
	int nElements() const;

    void Llistar() const;

//    ~estructuraDinamica();
};


#endif
