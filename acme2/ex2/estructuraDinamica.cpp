/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2009
 *    cal afegir-hi els metodes a implementar
 *    el destructor s'ha d'implementar si ho demana el professor
 */

#include <iostream>
#include "estructuraDinamica.h"


estructuraDinamica::estructuraDinamica()
{
	inici = final = new node;
	inici->seguent = NULL; 
	inici->dada = 0; 
}
estructuraDinamica::estructuraDinamica(estructuraDinamica & e)
{
	inici = final = new node;
    inici->seguent = NULL;
    inici->dada = e.inici->dada;
	node *aux1 = e.inici;
	node *aux2 = inici;
    node *nou;
	while(aux1 != e.final)
	{
        aux1 = aux1->seguent;
        nou = new node;
        nou->seguent = NULL;
        nou->dada = aux1->dada;
        aux2->seguent = nou;
        aux2 = aux2->seguent;
    }
    final = aux2;

}
void estructuraDinamica::AfegirInici(int i)
{
    node *p = new node;
    p->dada = i;
    p->seguent = inici;
    inici = p;
}



 void estructuraDinamica::Llistar() const {
	 node * p = inici;
	 
	 while (p != final)  { 
		 cout << p->dada << " ";
		 p = p->seguent;
	 }
	 cout << "S:" << p->dada << endl; // llista el sentinella
 }

