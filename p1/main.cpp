// Amat Martínez Vilà
// u1939654
// Pràctica ED

#include <iostream>
#include "Vehicle.h"
#include "Ordinador.h"

using namespace std;

/**
 *  Importem tots els tipus definits per l'ordinador
 */
typedef Ordinador::natural natural;

typedef Ordinador::thora thora;
typedef Ordinador::tminut tminut;
typedef Ordinador::tsegon tsegon;

typedef Ordinador::data data;
typedef Ordinador::instant_temporal instant_temporal;
typedef Ordinador::velocitat velocitat;
typedef Ordinador::multa multa;

/// @pre Cert
/// @post Llegeix dades amb el format següent i registra la informació a l'%ordinador.
/**
* DD/MM/YYYY   ← data
* HH:MM:SS     ← instant_temporal
* 50           ← velocitat
* Cotxe        ← tipus de Vehicle
* 0000 AAA     ← matrícula
* vermell      ← color  (només per als cotxes)
*
**/
void llegir_dades_de_teclat(Ordinador &o)
{
    Ordinador::registre r;
    data d;
    instant_temporal instant;
    std::string d_in, h_in;
    velocitat velocitat;
    std::string matricula, t_vehicle, color;

    cin >> d_in;
    while (stoi (d_in) != 0)
    {
        d = data (d_in);
        cin >> h_in;
        instant = instant_temporal (h_in);
        cin >> velocitat;
        cin.ignore (100, '\n');
        getline (cin, t_vehicle);
        getline (cin, matricula);
        if (t_vehicle == "cotxe")
            getline (cin, color);
        o.registrar (Ordinador::registre (t_vehicle, velocitat, color, matricula, d, instant));
        cin >> d_in;
        cin.ignore (100, '\n');
    }
}

/// @pre Cert
/// @post Llegeix una data i hora determinada i consulta la informació dels vehicles registrats a l'%ordinador.
/// Finalment mostra el resultat per pantalla.
void mostrar_vehicles_per_hora(const Ordinador &o)
{
    std::string dia;
    thora hora;
    cin >> dia;
    cin >> hora;
    cin.ignore (100, '\n');
    data d (dia);

    cout << "Vehicles enregistrats el dia "
         << d.to_string() << ", " << hora << ":00:00-" << hora << ":59:59: "
         << o.vehiclesHora (d, hora) << endl << endl;
}

/// @pre Cert
/// @post Consulta a l'%ordinador la hora en que els cotxes i motos circulen a velocitat més ràpida a l'ordinador i les mostra per pantalla.
void mostrar_hora_velocitat_maxima (const Ordinador& o)
{
    std::list<thora> l = o.horaMaxVelCotxesiMotos ();
    if (l.empty())
    {
        cout << "No hi ha cotxes a ser consultats." << endl;
        return;
    }
    cout << "Hores en que cotxes i motos circulen a major velocitat: ";
    for (const auto &it_hores : l)
        cout << it_hores << " ";
    cout << endl << endl;
}

/// @pre Cert
/// @post Consulta a l'%ordinador els dies amb més i menys vehicles registrats i els mostra per pantalla.
void mostrar_dies_mes_menys_vehicles (const Ordinador& o)
{
    std::pair<std::list<data>, std::list<data>> dies_mes_menys_vehicles;
    dies_mes_menys_vehicles = o.maxMinVehicles();
    if (dies_mes_menys_vehicles.first.empty() && dies_mes_menys_vehicles.second.empty())
    {
        cout << "No hi ha cotxes a ser consultats." << endl;
        return;
    }
    cout << "Dies amb major nombre de vehicles enregistrats: ";
    for (const auto &it_dies : dies_mes_menys_vehicles.first)
        cout << it_dies.to_string() << " ";
    cout << endl;
    cout << "Dies amb menor nombre de vehicles enregistrats: ";
    for (const auto &it_dies : dies_mes_menys_vehicles.second)
        cout << it_dies.to_string() << " ";
    cout << endl << endl;
}

/// @pre Cert
/// @post Consulta la hora en que els cotxes i motos circulen a velocitat més ràpida a l'ordinador i les mostra per pantalla.
void mostrar_color_cotxes_mes_rapids (const Ordinador& o)
{
    std::list<std::string> color_cotxes_mes_rapids = o.colorCotxesMesRapids();
    if (color_cotxes_mes_rapids.empty())
    {
        cout << "No hi ha cotxes a ser consultats." << endl;
        return;
    }
    cout << "Color dels cotxes que corren mes en mitjana: ";
    for (const auto &it_colors : color_cotxes_mes_rapids)
        cout << it_colors << " ";
    cout << endl << endl;
}

/// @pre Cert
/// @post Llegeix una data i hora determinada i consulta a l'%ordinador les multes que es podrien posar en aquella data i hora.
void mostrar_vehicles_multats_per_dia_i_velocitat(const Ordinador& o)
{
    data d;
    velocitat v;
    std::string d_in;
    getline (cin, d_in);
    d = data (d_in);
    cin >> v;
    cin.ignore (100, '\n');
    cout << "Vehicles multats el dia " << d.to_string() << " per excedir " << v << " km/h:" << endl << endl;
    std::list<multa> multes = o.multes(d, v);
    for (auto &it_multes : multes)
    {
        std::string h = it_multes.hora < 10 ? "0" + std::to_string(it_multes.hora) : std::to_string(it_multes.hora);
        std::string m = it_multes.minut < 10 ? "0" + std::to_string(it_multes.minut) : std::to_string(it_multes.minut);
        std::string s = it_multes.segon < 10 ? "0" + std::to_string(it_multes.segon) : std::to_string(it_multes.segon);
        cout << it_multes.matricula << endl
             << it_multes.velocitat << " km/h" << endl
             << h << ":" << m << ":" << s << endl
             << "--------------" << endl;
    }
    cout << endl;
}

/**
* @brief Programa que registra les dades d'un radar a un %ordinador per a després fer una sèrie de consultes.
*/
int main ()
{

    Ordinador o;
    llegir_dades_de_teclat(o);

    /* Llegir i executar consultes */
    std::string consulta;
    while (getline (cin, consulta))
    {
        if (consulta == "vehiclesHora")
        {
            mostrar_vehicles_per_hora(o);
        }
        else if (consulta == "horaMaxVelCotxesiMotos")
        {
            mostrar_hora_velocitat_maxima (o);
        }
        else if (consulta == "maxMinVehicles")
        {
            mostrar_dies_mes_menys_vehicles (o);
        }
        else if (consulta == "colorCotxesMesRapids")
        {
            mostrar_color_cotxes_mes_rapids (o);
        }
        else if (consulta == "multes")
        {
            mostrar_vehicles_multats_per_dia_i_velocitat (o);
        }
    }

    return 0;
}

