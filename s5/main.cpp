// Amat Martínez Vilà
// u1939654
// Sessió 5

#include <iostream>
#include "ArbreBinariDinamic.h"

using namespace std;

bool es_fulla(const ArbreBinariDinamic * a)
// pre: a és un arbre no nul
// post: retorna cert si l'arbre no té fills
{
    return a->FillEsquerre()->esBuit() && a->FillDret()->esBuit();
}

void mostrar_expressio(const ArbreBinariDinamic * a)
// pre: a és un arbre no nul
// post: mostra la expressió que emmagatzema l'arbre fent el recorregut en inordre
{
    if (!a->esBuit())
    {
        bool fulla = es_fulla(a);
        if (!fulla)
            cout << "(";
        if (not a->FillEsquerre()->esBuit())
            mostrar_expressio(a->FillEsquerre());
        if (fulla)
            cout << a->Contingut();
        else
            cout << " " << char(a->Contingut()) << " ";
        if (not a->FillDret()->esBuit())
            mostrar_expressio(a->FillDret());
        if (!fulla)
            cout << ")";
    }
}

float calcular(int operacio, float e, float d)
// pre: cert
// post: retorna el resultat de operar e i d amb l'operació "operacio"
{
    if (operacio == '+')
        return e+d;
    if (operacio == '-')
        return e-d;
    if (operacio == '*')
        return e*d;
    if (operacio == '/')
        if (d == 0)
            throw("l'operand dret no pot ser 0!");
        else
            return e/d;
}

float iOperar(const ArbreBinariDinamic* a)
// pre: a és un arbre no nul
// post: retorna el resultat d'operar l'expressió que emmagatzema l'arbre
{
    if (es_fulla(a))
        return (float)a->Contingut();
    float op_esquerre = iOperar(a->FillEsquerre());
    float op_dret = iOperar(a->FillDret());
    return calcular(a->Contingut(), op_esquerre, op_dret);
}

float operar(const ArbreBinariDinamic* a)
// pre: cert
// post: retorna el resultat d'operar l'expressió que emmagatzema l'arbre
{
    if (!a->esBuit())
        return iOperar(a);
    return 0;
}

int main()
{
    string expressio;
    getline(cin, expressio);
    ArbreBinariDinamic* a = new ArbreBinariDinamic(expressio.c_str());

    mostrar_expressio(a);
    cout << endl;
    try
    {
        cout << operar(a);
    }
    catch(const char* missatge_err)
    {
        cerr << "===> Excepció: " << missatge_err;
    }

    return 0;
}