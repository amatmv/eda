/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule & Joan Surrell.
 *  Copyright (c) 2004, 2005 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * simplement encadenada amb sentinella. Cal implementar nomes els metodes  
 * que demana cada enunciat. 
 */

#ifndef TAD_EstructuraCircularSentinella_h
#define TAD_EstructuraCircularSentinella_h


#include <cstdlib>
#include <iostream>
using namespace std;


struct node
{
    int dada;
    node * seguent;
};

class estructuraDinamica // circular sentinella
{
    node *inici;
public:
    estructuraDinamica();
    estructuraDinamica(estructuraDinamica &e);

    void AfegirInici(int i);
    void AfegirFinal(int i);
    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    void InserirOrdenadament(int i);

    bool Existeix(int i) const;
	int TreureFinal();
    void Esborrar(int i);

	void OmplirInici(int n);
	void OmplirFinal(int n);
	int nElements() const;
	
    void Llistar( ) const;
    

//    ~estructuraDinamica();
};

#endif	
