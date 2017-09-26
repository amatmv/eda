/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule & Joan Surrell.
 *  Copyright (c) 2004, 2005 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * simplement encadenada amb sentinella.   
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 * JSS [ACS] - 2010
 *    s'ha canviat una diferencia amb el codi de l'enunciat  
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;

estructuraDinamica::estructuraDinamica()
{
	 inici = new node;
	 inici->seguent = inici;
	 inici->dada = 0;
}


void estructuraDinamica::AfegirInici(int i)
{
    node *nou = new node(i);
    nou->seguent = inici->seguent;
    inici->seguent = nou;
}

bool estructuraDinamica::Existeix(int n) const
{
    if (inici->seguent == inici)
        return inici->dada == n;
    inici->dada = n;
    node *aux = inici->seguent;
    while(aux->dada != n)
        aux = aux->seguent;
    return aux->dada == n;
}


void estructuraDinamica::AfegirAbans(int i, int j)
{
    if (Existeix(j))
    {
        node *nou = new node(i);
        node *aux = inici->seguent;
        node *ant = inici;
        while(aux->dada != j)
        {
            ant = aux;
            aux = aux->seguent;
        }
        ant->seguent = nou;
        nou->seguent = aux;
    }

}

void estructuraDinamica::Llistar() const
{
	 if (inici != inici->seguent) {
		 node *p = inici->seguent; 
		 while (p != inici) { 
			 cout << p->dada << " "; 
			 p = p->seguent;
		 }
	 } 
	 cout << "S:" << inici->dada << endl; // llista el sentinella 
}
