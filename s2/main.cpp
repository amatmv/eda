// Amat Martínez Vilà
// u1939654
// Sessió 2

#include <iostream>
#include "pais.h"

using namespace std;

int main()
{
    Pais p;
    unsigned codi_comarca;
    string nom_comarca;
    cin >> codi_comarca;
    while(codi_comarca != 0)
    {
        cin.ignore();
        getline(cin, nom_comarca);
        p.afegir_comarca(Comarca(codi_comarca, nom_comarca));
        cin >> codi_comarca;
    }
    unsigned codi_municipi, poblacio;
    float extensio;
    string nom_municipi;
    cin >> codi_comarca;
    while(codi_comarca != 0)
    {
        cin >> codi_municipi;
        cin.ignore();
        getline(cin, nom_municipi);
        cin >> poblacio >> extensio;
        p.afegir_municipi(Municipi(codi_comarca, codi_municipi, nom_municipi, poblacio, extensio));
        cin >> codi_comarca;
    }
    cout << "----------------------------------------" << endl;
    cout << "INFORMACIÓ DEL PAÍS" << endl;
    cout << "Població: "
         << p.poblacio() << endl;
    cout << "Extensió: "
         << p.extensio() << endl;
    cout << "Nombre de comarques: "
         << p.nombre_comarques() << endl;
    cout << "----------------------------------------" << endl;
    cout << "INFORMACIÓ DEL PAÍS PER COMARCA (codi, nom, població, extensió)" << endl;
    p.llistar();
    cout << "----------------------------------------" << endl;
    Municipi    m_mes_densitat = p.municipi_amb_mes_densitat(),
                m_menys_densitat = p.municipi_amb_menys_densitat();
    cout << "Municipi amb més densitat del país: ";
    if (m_mes_densitat.nom() != "desconegut")
    {
        cout << m_mes_densitat.nom() << ", "
             << p.obtenir_comarca(m_mes_densitat.codi_comarca()).nom() << ", "
             << (m_mes_densitat.densitat() > 1 ? m_mes_densitat.densitat() : 0)
             << endl;
    } else
        cout << "Desconegut" << endl;
    cout << "Municipi amb menys densitat del país: ";
    if (m_menys_densitat.nom() != "desconegut")
    {
        cout << m_menys_densitat.nom() << ", "
             << p.obtenir_comarca(m_menys_densitat.codi_comarca()).nom() << ", "
             << (m_menys_densitat.densitat() > 1 ? m_menys_densitat.densitat() : 0)
             << endl;
    } else
        cout << "Desconegut" << endl;
    return 0;
}