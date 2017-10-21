// Amat Martínez Vilà
// u1939654
// Sessió 1

#include <iostream>
#include "pais.h"

using namespace std;

//Pre: --;
//Post: calcula la mitjana de les extensions del pais *p*
float extensio_mitjana_comarques_pais(const Pais &p)
{
    cout.setf(ios::fixed);
    cout.precision(3);
    return p.extensio()/p.nombre_comarques();
}

//Pre: --;
//Post: classifica les comarques en dos paisos temporals segons
//      si son menors o majors que la mitjana d'extensio del pais *p*. Al final, mostra ambdos paisos.
void llistar_comarques_menors_i_majors_que_mitjana(const Pais &p, float extensio_mitjana)
{
    Pais pais_extensio_menor, pais_extensio_major;
    for (vector<Comarca>::const_iterator comarca = p.inici_iterador_comarques(); comarca != p.fi_iterador_comarques(); ++comarca)
    {
        if(!comarca->buida())
            if(comarca->extensio() < extensio_mitjana)
                pais_extensio_menor.afegir_comarca(*comarca);
            else
                pais_extensio_major.afegir_comarca(*comarca);
    }
    pais_extensio_menor.llistar();
    cout << "========================================" << endl;
    pais_extensio_major.llistar();
}

int main()
{

    Pais p;
    int codi, poblacio;
    float extensio;
    string nom;
    cin >> codi;
    while(codi != 0)
    {
        cin.ignore();
        getline(cin, nom);
        cin >> poblacio >> extensio;
        p.afegir_comarca(Comarca(codi, nom, poblacio, extensio));
        cin >> codi;
    }
    cout << "----------------------------------------" << endl;
    float extensio_mitjana = extensio_mitjana_comarques_pais(p);
    cout << "mitjana extensio: " << extensio_mitjana << endl;
    cout << "========================================" << endl;
    llistar_comarques_menors_i_majors_que_mitjana(p, extensio_mitjana);
    cout << "----------------------------------------" << endl;
    cout << "número de comarques: " << p.nombre_comarques() << endl;
    cout << "població: " << p.nombre_habitants() << endl;
    cout << "extensió: " << p.extensio() << "km²" << endl;

    return 0;
}