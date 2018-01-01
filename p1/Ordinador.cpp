// Amat Martínez Vilà
// u1939654
// Pràctica ED


#include "Ordinador.h"

void Ordinador::registrar (const Ordinador::registre& r)
{
    std::pair<Vehicle*, velocitat> registre_velocitat;
    if (r.r_tipus_vehicle == "cotxe")
    {
        registre_velocitat = std::pair<Vehicle*, velocitat> (new Cotxe (r.r_matricula, r.r_color), r.r_velocitat);
    }
    else if (r.r_tipus_vehicle == "moto")
    {
        registre_velocitat = std::pair<Vehicle*, velocitat> (new Moto (r.r_matricula), r.r_velocitat);
    }
    else
    {
        registre_velocitat = std::pair<Vehicle*, velocitat> (new Vehicle (r.r_matricula), r.r_velocitat);
    }
    std::pair<instant_temporal, std::pair<Vehicle*, velocitat>> vehicle_registrat;
    vehicle_registrat.first = r.r_instant;
    vehicle_registrat.second = registre_velocitat;
    auto consulta_vehicle_igual_data = _info_vehicles.find (r.r_data);
    thora hora_registre = r.r_instant.hora;
    if  (consulta_vehicle_igual_data == _info_vehicles.end ())
    {
        std::vector<std::list<std::pair<instant_temporal, std::pair<Vehicle*, velocitat>>>> v (24);
        v[hora_registre].emplace_back  (vehicle_registrat);

        std::pair<Ordinador::data, std::vector<std::list<std::pair<instant_temporal, std::pair<Vehicle*, velocitat>>>>> registre_a_inserir (r.r_data, v);
        _info_vehicles.insert (registre_a_inserir);
    }
    else
    {
        consulta_vehicle_igual_data->second[hora_registre].emplace_back (vehicle_registrat);
    }
}

Ordinador::natural Ordinador::vehiclesHora (const Ordinador::data& d, thora h) const
{
    auto consulta = _info_vehicles.find (d);
    Ordinador::natural n = 0;
    if (consulta != _info_vehicles.end ())
        return (Ordinador::natural) consulta->second[h].size ();
    return n;
}

bool Ordinador::comparador_velocitats (
        const std::pair<Ordinador::velocitat, std::pair<Ordinador::thora, Ordinador::natural>>& a,
        const std::pair<Ordinador::velocitat, std::pair<Ordinador::thora, Ordinador::natural>>& b)
{
    return a.first == b.first ? a.second.first < b.second.first :  a.first > b.first ;
}

std::list<Ordinador::thora> Ordinador::horaMaxVelCotxesiMotos () const
{
    std::vector<std::pair<Ordinador::velocitat, std::pair<Ordinador::thora, Ordinador::natural>>> velocitats_mitjanes (24);

    for (const auto &_info_vehicle : _info_vehicles)
    {
        for (const auto &it_hores : _info_vehicle.second)
        {
            for (const auto &it_registres : it_hores)
            {
                if (dynamic_cast<Cotxe*> (it_registres.second.first) != nullptr
                    or dynamic_cast<Moto*> (it_registres.second.first) != nullptr)
                {
                    velocitat v = it_registres.second.second;
                    velocitats_mitjanes[it_registres.first.hora].second.first = it_registres.first.hora;
                    velocitats_mitjanes[it_registres.first.hora].second.second++;

                    natural nombre_vehicles = velocitats_mitjanes[it_registres.first.hora].second.second;
                    velocitats_mitjanes[it_registres.first.hora].first += v;
                    velocitats_mitjanes[it_registres.first.hora].first /= nombre_vehicles;
                }
            }
        }
    }

    std::sort (
            std::begin(velocitats_mitjanes),
            std::end(velocitats_mitjanes),
            comparador_velocitats
    );

    std::list<Ordinador::thora> hores;

    auto it = std::begin (velocitats_mitjanes);
    auto it_end = std::end (velocitats_mitjanes);
    Ordinador::thora max_mitjana = (thora) it->first;

    hores.push_back (it->second.first);
    ++it;
    while (it != it_end && it->first == max_mitjana)
    {
        hores.push_back (it->second.first);
        ++it;
    }
    return hores;
}

bool Ordinador::comparador_cotxes_velocitat (
        const std::pair<Ordinador::velocitat, std::string>& a,
        const std::pair<Ordinador::velocitat, std::string>& b)
{
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

std::list<std::string> Ordinador::colorCotxesMesRapids() const
{
    if (_info_vehicles.empty())
        return std::list<std::string>();
    typedef std::string color;
    std::unordered_map<std::string, std::pair<velocitat, natural>> velocitats_per_color;

    for (const auto &_info_vehicle : _info_vehicles)
    {
        for (const auto &it_hores : _info_vehicle.second)
        {
            for (const auto &it_vehicles : it_hores)
            {
                if (dynamic_cast<Cotxe*>(it_vehicles.second.first) != nullptr)
                {
                    std::string color = it_vehicles.second.first->color();
                    velocitats_per_color[color].second++;
                    velocitats_per_color[color].first += it_vehicles.second.second;
                    velocitats_per_color[color].first /= velocitats_per_color[color].second;
                }
            }
        }
    }
    std::vector<std::pair<velocitat, color>> cotxes_registrats (0, std::pair<velocitat, color> (0,""));
    for (const auto &it_velocitats : velocitats_per_color)
    {
        auto cotxe_actual = std::pair<velocitat, color> (
                it_velocitats.second.first,
                it_velocitats.first
        );
        auto it = std::upper_bound (
                std::begin (cotxes_registrats),
                std::end (cotxes_registrats),
                cotxe_actual,
                comparador_cotxes_velocitat
        );
        cotxes_registrats.insert (it, cotxe_actual);
    }

    std::list<color> colors;
    auto it = std::begin (cotxes_registrats);
    auto it_end = std::end (cotxes_registrats);
    Ordinador::velocitat max_mitjana = it->first;
    colors.push_back (it->second);
    ++it;
    while (it != it_end && it->first == max_mitjana)
    {
        colors.push_back (it->second);
        ++it;
    }
    return colors;
}

bool Ordinador::comparador_cotxes_dia (
        const std::pair<Ordinador::natural, Ordinador::data>& a,
        const std::pair<Ordinador::natural, Ordinador::data>& b)
{
    return a.first == b.first ? a.second < b.second :  a.first > b.first ;
}

std::pair<std::list<Ordinador::data>, std::list<Ordinador::data>> Ordinador::maxMinVehicles() const
{
    if (_info_vehicles.empty())
        return std::pair<std::list<Ordinador::data>, std::list<Ordinador::data>>();
    std::vector<std::pair<Ordinador::natural, Ordinador::data>> max_vehicles;

    std::pair<Ordinador::natural, Ordinador::data> dia_actual;
    for (const auto &_info_vehicle : _info_vehicles)
    {
        dia_actual = std::pair<Ordinador::natural, Ordinador::data> (0, _info_vehicle.first);
        for (const auto &it_hores : _info_vehicle.second)
        {
            dia_actual.first += it_hores.size();
        }
        auto it = std::upper_bound (std::begin (max_vehicles), std::end (max_vehicles), dia_actual, comparador_cotxes_dia);
        max_vehicles.insert (it, dia_actual);
    }

    std::list<Ordinador::data> dies_max_vehicles;
    std::list<Ordinador::data> dies_min_vehicles;

    auto it = max_vehicles.begin ();
    auto it_end = max_vehicles.end ();

    auto r_it = max_vehicles.rbegin ();
    auto r_it_end = max_vehicles.rend();

    natural max = it->first;
    natural min = r_it->first;
    dies_max_vehicles.push_back(it->second);
    dies_min_vehicles.push_back(r_it->second);
    it++; r_it++;
    while (it != it_end && r_it != r_it_end && (it->first == max || r_it->first == min))
    {
        if (it->first == max)
        {
            dies_max_vehicles.push_back(it->second);
            it++;
        }
        if (r_it->first == min)
        {
            dies_min_vehicles.push_front(r_it->second);
            r_it++;
        }
    }
    return std::pair<std::list<Ordinador::data>, std::list<Ordinador::data>>(dies_max_vehicles, dies_min_vehicles);
}

bool Ordinador::comparador_multes (const multa& a, const multa& b)
{
    return a.matricula < b.matricula;
}

std::list<Ordinador::multa> Ordinador::multes(const Ordinador::data &d, const Ordinador::velocitat &v) const
{
    std::list<multa> multes;
    auto consulta = _info_vehicles.find (d);
    if (consulta != _info_vehicles.end ())
    {
        for (const auto &it_hores : consulta->second)
        {
            for (const auto &it_vehicles : it_hores)
            {
                if (it_vehicles.second.second > v)
                {
                    multa m (
                            it_vehicles.second.first->matricula(),
                            it_vehicles.second.second,
                            it_vehicles.first.hora,
                            it_vehicles.first.minut,
                            it_vehicles.first.segon
                    );
                    multes.insert (std::upper_bound (std::begin (multes), std::end (multes), m, comparador_multes), m);
                }
            }
        }
    }

    return multes;
}

Ordinador::registre::registre (std::string tipus_vehicle,
                               const Ordinador::velocitat& velocitat,
                               std::string color,
                               std::string matricula,
                               const Ordinador::data& data,
                               const Ordinador::instant_temporal& hora) :
        r_tipus_vehicle (tipus_vehicle), r_color (color),
        r_velocitat (velocitat), r_matricula (matricula),
        r_data (data), r_instant (hora) {}

Ordinador::data::data (const std::string& d)
{
    struct tm tm;
    if  ((bool) strptime (d.c_str (), "%d/%m/%Y", &tm))
    {
        dia =  (short) tm.tm_mday;
        mes =  (short) (tm.tm_mon + 1);
        any =  (short) (tm.tm_year + 1900);
    }
}

bool Ordinador::data::operator== (const Ordinador::data &d) const
{
    return any == d.any and mes == d.mes and dia == d.dia;
}

bool Ordinador::data::operator< (const Ordinador::data &d) const
{
    if  (any < d.any)
        return true;
    if  (any > d.any)
        return false;
    // any == d.any
    if  (mes < d.mes)
        return true;
    if  (mes > d.mes)
        return false;
    // mes == d.mes
    return dia < d.dia;
}

std::string Ordinador::data::to_string() const
{
    std::string d = dia < 10 ? "0" + std::to_string(dia) : std::to_string(dia);
    std::string m = dia < 10 ? "0" + std::to_string(mes) : std::to_string(mes);
    return d + "/" + m + "/" + std::to_string(any);
}

Ordinador::instant_temporal::instant_temporal () = default;

Ordinador::instant_temporal::instant_temporal (const std::string& h)
{
    struct tm tm;
    if  ((bool)strptime (h.c_str (), "%H:%M:%S", &tm))
    {
        hora =  (short)tm.tm_hour;
        minut =  (short)tm.tm_min;
        segon =  (short)tm.tm_sec;
    }
}

Ordinador::multa::multa(const std::string &matricula, Ordinador::velocitat velocitat, Ordinador::thora hora, Ordinador::tminut minut,
                        Ordinador::tsegon segon) : matricula(matricula), velocitat(velocitat), hora(hora), minut(minut),
                                                   segon(segon) {}
