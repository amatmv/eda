//
// Created by amat on 27/10/17.
//

#ifndef S3_EMD_H
#define S3_EMD_H

#include <iostream>

using namespace std;

class EMD
{
public:

    //Pre: --;
    //Post: constructor per defecte de EMD
    EMD();

    //Pre: --;
    //Post: constructor amb paràmetres de EMD
    EMD(const int& codi_municipi, const string& codi, const string& nom);

    //Pre: --;
    //Post: retorna el codi postal del municipi actual
    int codi_municipi() const;

    //Pre: --;
    //Post: retorna el codi del municipi actual
    string codi() const;

    //Pre: --;
    //Post: retorna el nom del municipi actual
    string nom() const;

    //Pre: --;
    //Post: comparador de EMDs segons el codi
    bool operator< (const EMD&e) const;

    //Pre: --;
    //Post: redefinició de sortida per a mostrar la EMD e
    friend ostream& operator << (ostream& o, const EMD& e);

private:
    int _codi_municipi;
    string _codi, _nom;
};


#endif //S3_EMD_H
