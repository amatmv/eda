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
