/*
 *  pilaDinamica.h
 *  PilaDinamica
 *
 *  Created by Joan Surrell on Mon Oct 30 2006.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 * Aquest fitxer conte la definicio de la pila dinamica simplement
 * encadenada. Cal implementar tots els metodes. 
 * La definicio s'ha fet per una pila d'enters, pero es pot 
 * adaptar facilment a qualsevol tipus base.
 */

#ifndef TAD_pilaDinamica_h
#define TAD_pilaDinamica_h

#include <cstdlib>
#include <iostream>
using namespace std;

// typedef int element; //"descomentar" per fer una pila d'enter
typedef char element; //"descomentar" per fer una pila de caracters

struct node
{
    element dada;
    node *seguent;
};

class pilaDinamica
{
    node * inici;
public:
    pilaDinamica();
    pilaDinamica(const pilaDinamica & p); // no es demana
    
    void Empila(element e);
    void Desempila();
    element Cim() const;
    bool Buida() const;

//    ~pilaDinamica(); // cal implementar-lo
};


#endif
