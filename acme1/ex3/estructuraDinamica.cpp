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

void estructuraDinamica::AfegirInici(int i)
{
    node *p = new node;
    p->dada = i;
    p->seguent = inici;
    inici = p;
}

bool estructuraDinamica::Existeix(int i) const
{
    final->dada = i;
    node *aux = inici;
    while (aux->dada != i)
        aux = aux->seguent;
    return (aux != final);
}

 void estructuraDinamica::Llistar() const {
     node * p = inici;

     while (p != final)  {
         cout << p->dada << " ";
         p = p->seguent;
     }
     cout << "S:" << p->dada << endl; // llista el sentinella
 }