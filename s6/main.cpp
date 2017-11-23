// Amat Martínez Vilà
// u1939654
// Sessió 6

#include <iostream>
#include "pais.h"

using namespace std;

int main ()
{
    Pais p;

    unsigned codi_comarca;
    string nom_comarca;

    /* Comencem a llegir comarques */
    cin >> codi_comarca;
    while (codi_comarca != 0)
    {
        cin.ignore ();
        getline (cin, nom_comarca);
        p.inserir_comarca (Comarca (codi_comarca, nom_comarca));
        cin >> codi_comarca;
    }

    unsigned codi_municipi, poblacio;
    float extensio;
    string nom_municipi;

    /* Ara llegim municipis i els afegim al Pais*/
    cin >> codi_comarca;
    while (codi_comarca != 0)
    {
        cin >> codi_municipi;
        cin.ignore ();
        getline (cin, nom_municipi);
        cin >> poblacio >> extensio;
        p.inserir_municipi (Municipi (codi_comarca, codi_municipi, nom_municipi, poblacio, extensio));
        cin >> codi_comarca;
    }

    string codi_EMD, nom_EMD;
    cin >> codi_municipi;
    while (codi_municipi != 0)
    {
        cin.ignore ();
        getline (cin, codi_EMD);
        getline (cin, nom_EMD);
        p.inserir_EMD (EMD(codi_municipi, codi_EMD, nom_EMD));
        cin >> codi_municipi;
    }
    cin.ignore();
    cout << "----------------------------------------" << endl << endl;
    cout << "INFORMACIÓ DEL PAÍS" << endl;
    cout << " - Població: "
         << p.poblacio () << endl;
    cout << " - Extensió: "
         << p.extensio () << endl;
    cout << " - Nombre de comarques: "
         << p.nombre_comarques () << endl << endl;
    cout << "----------------------------------------" << endl << endl;
    cout << "INFORMACIÓ DEL PAÍS PER COMARCA  (codi, nom, població, extensió)" << endl << endl;
    p.llistar_comarques ();
    cout << "----------------------------------------" << endl;
    cout << "Introdueix el nom del municipi del qual vols consultar la informació (\"FI\" per a acabar el programa)" << endl;
    string entrada;
    cout << "> ";
    getline(cin, entrada);
    while (entrada != "FI")
    {
        p.mostrar_info_municipi(entrada);
        cout << "----------------------------------------" << endl;
        cout << "Introdueix el nom del municipi del què vols consultar la informació (\"FI\" per a acabar el programa)" << endl;
        cout << "> ";
        getline(cin, entrada);
    }
    cout << "**************** FI ****************" << endl;
    return 0;
}
