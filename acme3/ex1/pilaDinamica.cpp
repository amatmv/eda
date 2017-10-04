//
// Created by amat on 4/10/17.
//

#include "pilaDinamica.h"

using namespace std;

pilaDinamica::pilaDinamica()
{
    inici = NULL;
}

void pilaDinamica::Empila(element e)
{
    node *nou = new node;
    nou->dada = e;

    if(inici != NULL)
        nou->seguent = inici;
    else
        nou->seguent = NULL;

    inici = nou;
}
void pilaDinamica::Desempila()
{
    if(!Buida())
    {
        node *p = inici;
        inici = inici->seguent;
        delete p;
    }
}

element pilaDinamica::Cim() const
{
    if(!Buida())
        return inici->dada;
    else
        return NULL;
}

bool pilaDinamica::Buida() const
{
    return inici == NULL;
}


