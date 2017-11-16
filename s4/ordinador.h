//
// Created by amat on 1/11/17.
//

#ifndef P1_ORDINADOR_H
#define P1_ORDINADOR_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include "data.h"
#include "cotxe.h"
#include "instant_temporal.h"

class ordinador
{
public:

    // Struct que representa la informació que queda emmagatzemada per a cada
    // observació del radar.
    // Aquesta informació es classifica en l'ordinador en una estructura
    // de dades especialitzada.
    struct registre
    {
        registre(const string &tv, const float& v, const string &c, const string &m, const data &d,
                 const instant_temporal &i);

        registre();

        string r_tipus_vehicle;
        string r_color;
        string r_matricula;
        float r_velocitat;
        data r_data;
        instant_temporal r_instant;

    };

    //Pre: --
    //Post: constructor per defecte
    ordinador() = default;

    //Pre: --
    //Post: retorna una llista amb els cotxes que han passat una data i una hora determinada
    list<cotxe> llista_vehicles_per_hora(const data& d, short h) const;

    //Pre: r és un registre no buit
    //Post: emmagatzema el registre d'un vehicle a l'ordinador
    void registrar (const registre& r);

private:

    //Pre: r és un registre no buit
    //Post: emmagatzema el registre d'un cotxe a l'ordinador
    void registrar_cotxe (const registre& r);

    //Pre: r és un registre no buit
    //Post: emmagatzema el registre d'una moto a l'ordinador
    void registrar_moto (const registre& r);

    //Pre: r és un registre no buit
    //Post: emmagatzema el registre d'un vehicle especial a l'ordinador
    void registrar_vehicle (const registre& r);

    unordered_map<data, vector<list<pair<instant_temporal, vehicle>>>> _info_vehicles;
    unordered_map<data, vector<list<pair<instant_temporal, cotxe>>>> _info_cotxes;

};


#endif //P1_ORDINADOR_H
