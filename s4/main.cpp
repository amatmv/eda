// Amat Martínez Vilà
// u1939654
// Sessió 4

#include <iostream>
#include "data.h"
#include "vehicle.h"
#include "ordinador.h"

using namespace std;

typedef unsigned int nat;

typedef short thora;
typedef short tminut;
typedef short tsegon;

// Pre:  0 <= h <= 23
// Post: retorna el nombre de vehicles registrats el dia  d  en
//       l’interval horari h:00:00 - h:59:59
nat vehicles_hora(const ordinador& o, data d, thora h);


ostream &operator<<(ostream &os, const data &d)
{
    os << d.dia() << "/" << d.mes() << "/" << d.any();
    return os;
}

ostream &operator<<(ostream &os, const instant_temporal &temporal)
{
    os << temporal.hora() << ":" << temporal.minut() << ":" << temporal.segon();
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
    data d;
    instant_temporal instant;
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
            data d(dia);

            cout << "Vehicles enregistrats el dia "
                 << d << ", " << hora << ":00:00-" << hora << ":59:59: "
                 << vehicles_hora(o, d, hora) << endl;
        }
        else if (consulta == "horaMaxVelCotxesiMotos")
        {
            /* NO IMPLEMENTAT */
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

// Pre:  0 <= h <= 23
// Post: retorna el nombre de vehicles registrats el dia  d  en
//       l’interval horari h:00:00 - h:59:59
nat vehicles_hora(const ordinador& o, data d, thora h)
{
    list<cotxe> llista_vehicles_hora = o.llista_vehicles_per_hora(d, h);
    return (nat)llista_vehicles_hora.size();
}