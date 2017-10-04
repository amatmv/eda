//
// Created by amat on 4/10/17.
//

#include <iostream>
#include "pilaDinamica.h"
using namespace std;

bool es_obertura(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool tanca(char a, char b)
{
    switch(a)
    {
        case ')':
            return b == '(';
        case ']':
            return b == '[';
        case '}':
            return b == '{';
        default:
            return false;
    }
}


int main()
{
    pilaDinamica p;
    char c;
    bool OK = true;

    cin >> c;
    while(OK && (c != '.'))
    {
        if(es_obertura(c))
            p.Empila(c);
        else
            if(tanca(c, p.Cim()))
                p.Desempila();
            else
                OK = false;
        cin >> c;
    }

    if (OK && p.Buida())
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

}



