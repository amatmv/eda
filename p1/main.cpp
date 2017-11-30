// Amat Martínez Vilà
// u1939654
//

#include <iostream>
#include "vehicle.h"
#include "ordinador.h"

using namespace std;

/**
 *  Importem tots els tipus definits per l'ordinador
 */
typedef ordinador::nat nat;

typedef ordinador::thora thora;
typedef ordinador::tminut tminut;
typedef ordinador::tsegon tsegon;

typedef ordinador::data data;
typedef ordinador::instant_temporal instant_temporal;

ostream &operator<<(ostream &os, const data &d)
{
    os << d.dia << "/" << d.mes << "/" << d.any;
    return os;
}

ostream &operator<<(ostream &os, const instant_temporal &temporal)
{
    os << temporal.hora << ":" << temporal.minut << ":" << temporal.segon;
    return os;
}

int main()
{

    /* ======= Format de les dades ====== */
    /*
     * DD/MM/YYYY ← data
     * hh:mm:ss ← instant_temporal
     * 50 ← velocitat
     * cotxe ← tipus de vehicle
     * 0000 AAA ← matricula
     * vermell ← color (nomes per als cotxes)
     *
     */

    ordinador o;
    ordinador::registre r;
    ordinador::data d;
    ordinador::instant_temporal instant;
    string d_in, h_in;
    float velocitat;
    vehicle v;
    string matricula, t_vehicle, color;
    cin >> d_in;
    while (stoi(d_in) != 0)
    {
        d = data(d_in);
        cin >> h_in;
        instant = instant_temporal(h_in);
        cin >> velocitat;
        cin.ignore(100, '\n');
        getline(cin, t_vehicle);
        getline(cin, matricula);
        getline(cin, color);
        o.registrar(ordinador::registre(t_vehicle, velocitat, matricula, color, d, instant));
        cin >> d_in;
        cin.ignore(100, '\n');
    }
    /* Llegir i executar consultes */
    string consulta;
    while (getline(cin, consulta))
    {
        if (consulta == "vehiclesHora")
        {
            string dia;
            thora hora;
            cin >> dia;
            cin >> hora;
            ordinador::data d(dia);

            cout << "Vehicles enregistrats el dia "
                 << d << ", " << hora << ":00:00-" << hora << ":59:59: "
                 << o.vehicles_hora(d, hora) << endl;
        }
        else if (consulta == "horaMaxVelCotxesiMotos")
        {
            list<thora> l = o.horaMaxVelCotxesiMotos();
        }
        else if (consulta == "maxMinVehicles")
        {
            /* NO IMPLEMENTAT */
        }
        else if (consulta == "colorCotxesMesRapids")
        {
            /* NO IMPLEMENTAT */
        }
        else if (consulta == "multes")
        {
            /* NO IMPLEMENTAT */
        }
    }

    return 0;
}