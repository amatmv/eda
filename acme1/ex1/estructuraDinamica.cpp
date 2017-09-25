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


void estructuraDinamica::AfegirFinal(int i)
{
    node * aux = inici;
    inici->dada = i;
    while(aux->dada != 0)
        aux = aux->seguent;
    node * p = new node;
    p->seguent = NULL;
    p->dada = i;
}

void estructuraDinamica::Llistar() const {
 node * p = inici;

 while (p != final)  {
     cout << p->dada << " ";
     p = p->seguent;
 }
 cout << "S:" << p->dada << endl; // llista el sentinella
}

