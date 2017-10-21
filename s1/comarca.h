// Amat Martínez Vilà
// u1939654
// Sessió 1

#ifndef S1_COMARCA_H
#define S1_COMARCA_H

#include <iostream>
#include <vector>

using namespace std;

class Comarca{
public:

    //Pre: --;
    //Post: retorna el nombre de comarques que te el pais
    Comarca();

    //Pre: --;
    //Post: retorna el nombre de comarques que te el pais
    Comarca(int codi, const string &nom, int poblacio, float extensio);

    //Pre: --;
    //Post: retorna el codi de la comarca actual
    int codi() const;

    //Pre: --;
    //Post: retorna el nom de la comarca
    string nom() const;

    //Pre: --;
    //Post: retorna la extensio de la comarca
    float extensio() const;

    //Pre: --;
    //Post: retorna la poblacio de la comarca
    int poblacio() const;

    //Pre: --;
    //Post: retorna cert si la comarca conte les dades del constructor per defecte; fals altrament
    bool buida() const;

    //Pre: --;
    //Post: redefinicio de l'operador de sortida predeterminat
    friend ostream &operator << (ostream &o, const Comarca&p);

private:
    int _codi, _poblacio;
    string _nom;
    float _extensio;
};

#endif //S1_COMARCA_H
