//
// Created by amat on 1/11/17.
//

#ifndef P1_ORDINADOR_H
#define P1_ORDINADOR_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <map>
#include "cotxe.h"

class ordinador
{
public:

    typedef unsigned int nat;
    typedef short thora;
    typedef short tminut;
    typedef short tsegon;

    struct data
    {
        data () = default;
        explicit data (const string& d);

        short dia;
        short mes;
        short any;

        bool operator== (const data &d) const;
        bool operator< (const data &d) const;
    };

    struct instant_temporal
    {
        instant_temporal();

        /// @pre la cadena h ha de tenir el format HH:MM:SS
        /// @post construeix un instant temporal a partir de la cadena h
        explicit instant_temporal(const string& h);

        short hora;
        short minut;
        short segon;
    };

    /**
     * @brief   Struct que representa la informació que queda emmagatzemada per a cada
     *          observació del radar.
     *          Aquesta informació es classifica en l'ordinador en una estructura
     *          de dades especialitzada.
     **/
    struct registre
    {
        registre (const string &tv, const float& v, const string &c,
                  const string &m, const ordinador::data &d,
                  const ordinador::instant_temporal &i);

        registre () = default;

        string r_tipus_vehicle;
        string r_color;
        string r_matricula;
        float r_velocitat;
        ordinador::data r_data;
        ordinador::instant_temporal r_instant;

    };


    /// @pre --
    /// @post constructor per defecte
    ordinador() = default;

    /// @pre --
    /// @post retorna una llista amb els cotxes que han passat una data i una hora determinada
    list<cotxe> llista_vehicles_per_hora (const ordinador::data& d, short h) const;

    /// @pre  0 <= h <= 23
    /// @post retorna el nombre de vehicles registrats el dia  d  en
    ///       l’interval horari h:00:00 - h:59:59
    nat vehicles_hora (const ordinador::data& d, thora h) const;

    /// @pre  ---
    /// @post retorna les hora del dia en que la velocitat mitjana de
    ///       cotxes i motos es mes elevada, considerant tots els dies
    ///       (una llista per si hi ha empat; ordenada creixentment)
    list<thora> horaMaxVelCotxesiMotos () const;

    /// @pre r és un registre no buit
    /// @post emmagatzema el registre d'un vehicle a l'ordinador
    void registrar (const registre& r);

private:

    /// @pre r és un registre no buit
    /// @post emmagatzema el registre d'un cotxe a l'ordinador
    void registrar_cotxe (const registre& r);

    /// @pre r és un registre no buit
    /// @post emmagatzema el registre d'una moto a l'ordinador
    void registrar_moto (const registre& r);

    /// @pre r és un registre no buit
    /// @post emmagatzema el registre d'un vehicle especial a l'ordinador
    void registrar_vehicle (const registre& r);

    map<ordinador::data, vector<list<pair<instant_temporal, pair<vehicle, short>>>>> _info_vehicles;
    map<ordinador::data, vector<list<pair<instant_temporal, pair<cotxe, short>>>>> _info_cotxes;

};


#endif //P1_ORDINADOR_H
