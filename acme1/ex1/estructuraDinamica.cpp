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

//estructuraDinamica::~estructuraDinamica()
//{
//	allibera();
//}

void estructuraDinamica::AfegirFinal(int i)
{
    node *nou = new node(i);

    if (inici == final)
        inici = nou;
    else
    {
        node * aux = inici;
        while(aux->seguent->dada != 0)
            aux = aux->seguent;
        aux->seguent = nou;
    }
    nou->seguent = final;
}

void estructuraDinamica::Llistar() const
{
     node * p = inici;

     while (p != final)  {
         cout << p->dada << " ";
         p = p->seguent;
     }
     cout << "S:" << p->dada << endl; // llista el sentinella
}

//void estructuraDinamica::allibera()
//{
//    node * aux = inici;
//    while (aux->seguent != final)
//        delete aux;
//    delete final;
//}

