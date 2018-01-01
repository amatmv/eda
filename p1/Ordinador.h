#ifndef P1_ORDINADOR_H
#define P1_ORDINADOR_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include "Cotxe.h"
#include "Vehicle.h"
#include "Moto.h"

/**
* @brief Classe que representa un ordinador monoplaca que recopila informació sobre els vehicles que ha registrat
* un radar (fictíci) i n'emmagatzema la informació per a poder consultar-la.
*/
class Ordinador
{
public:

    /* ---- Definició de tipus interns de la classe Ordinador ---- */

    typedef unsigned int    natural;
    typedef float           velocitat;
    typedef short           thora;
    typedef short           tminut;
    typedef short           tsegon;

    struct data
    {
        data () = default;
        explicit data (const std::string& d);

        short dia;
        short mes;
        short any;

        std::string to_string() const;
        bool operator== (const data &d) const;
        bool operator< (const data &d) const;
    };

    struct instant_temporal
    {
        instant_temporal();

        /// @pre la cadena h ha de tenir el format HH:MM:SS
        /// @post construeix un instant temporal a partir de la cadena h
        explicit instant_temporal(const std::string& h);

        thora   hora;
        tminut  minut;
        tsegon  segon;
    };

    /**
     * @brief   Tupla que representa la informació que queda emmagatzemada per a cada
     *          observació del radar.
     *          Aquesta informació es classifica en l'ordinador en una estructura
     *          de dades especialitzada.
     **/
    struct registre
    {

        registre () = default;

        explicit registre(std::string tipus_vehicle, const Ordinador::velocitat &velocitat, std::string color,
                          std::string matricula, const Ordinador::data &data, const instant_temporal &hora);

        std::string                 r_tipus_vehicle;
        std::string                 r_color;
        std::string                 r_matricula;
        Ordinador::velocitat        r_velocitat;
        Ordinador::data             r_data;
        Ordinador::instant_temporal r_instant;

    };

    /**
     * @brief   Tuple que guarda la informació d'una %multa.
     **/
    struct multa
    {
        std::string             matricula;
        Ordinador::velocitat    velocitat;
        thora                   hora;
        tminut                  minut;
        tsegon                  segon;

        explicit multa(const std::string &matricula, Ordinador::velocitat velocitat, thora hora, tminut minut, tsegon segon);
    };

    /// @pre Cert
    /// @post constructor per defecte de %ordinador
    Ordinador() = default;

    /// @pre  0 <= h <= 23
    /// @post retorna el nombre de vehicles registrats el dia  d  en
    ///       l’interval horari h:00:00 - h:59:59
    natural vehiclesHora (const Ordinador::data& d, thora h) const;

    /// @pre  Cert
    /// @post retorna les hora del dia en que la velocitat mitjana de
    ///       cotxes i motos es mes elevada, considerant tots els dies
    ///       (una llista per si hi ha empat; ordenada creixentment)
    std::list<thora> horaMaxVelCotxesiMotos () const;

    /// @pre  Cert
    /// @post retorna un parell de llistes, la primera amb els dies que
    ///       hi ha hagut mes transit, i la segona amb els dies que n’hi
    ///       ha hagut menys; les dues llistes ordenades per data
    std::pair< std::list<data>, std::list<data> > maxMinVehicles() const;

    /// @pre Cert
    /// @post retorna el color dels cotxes que corren mes en mitjana
    ///       (una llista per si hi ha empat; ordenada alfabeticament)
    std::list<std::string> colorCotxesMesRapids() const;

    /// @pre Cert
    /// @post retorna una llista amb la matricula, velocitat i instant
    ///       de pas dels vehicles que el dia d han superat la
    ///       velocitat v (ordenada per matricula)
    std::list<Ordinador::multa> multes(const Ordinador::data& d, const Ordinador::velocitat& v) const;

    /// @pre r és un registre no buit
    /// @post emmagatzema el registre d'un vehicle a l'ordinador
    void registrar (const registre& r);

private:

    /// Estructura que conté tota la informació que recopila l'ordinador i l'emmagatzema per a poder efecturar
    /// les consultes que ofereix l'ordinador monoplaca.
    std::map<
            Ordinador::data,
            std::vector<
                    std::list<
                            std::pair<
                                    instant_temporal,
                                    std::pair<
                                            Vehicle*,
                                            velocitat>>>>> _info_vehicles;

    /// @pre Cert
    /// @post retorna el resultat de comparar els dos registres %a i %b segons els criteris adients
    static bool comparador_cotxes_velocitat (const std::pair<Ordinador::velocitat, std::string> &a,
                                               const std::pair<Ordinador::velocitat, std::string> &b);
    /// @pre Cert
    /// @post retorna el resultat de comparar els dos registres %a i %b segons els criteris adients
    static bool comparador_velocitats (const std::pair<Ordinador::velocitat, std::pair<Ordinador::thora, Ordinador::natural>> &a,
                                         const std::pair<Ordinador::velocitat, std::pair<Ordinador::thora, Ordinador::natural>> &b);

    /// @pre Cert
    /// @post retorna el resultat de comparar els dos registres %a i %b segons els criteris adients
    static bool comparador_cotxes_dia (const std::pair<Ordinador::natural, Ordinador::data> &a,
                                         const std::pair<Ordinador::natural, Ordinador::data> &b);
    /// @pre Cert
    /// @post retorna el resultat de comparar els dos registres %a i %b segons els criteris adients
    static bool comparador_multes (const multa&a, const multa&b);
};


#endif //P1_ORDINADOR_H
