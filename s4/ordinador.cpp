// Amat Martínez Vilà
// u1939654
// Sessió 4

#include "ordinador.h"

void ordinador::registrar(const ordinador::registre& r)
{
    if (r.r_tipus_vehicle == "cotxe")
        registrar_cotxe(r);
    else if (r.r_tipus_vehicle == "moto")
        registrar_moto(r);
    else
        registrar_vehicle(r);
}

void ordinador::registrar_cotxe(const ordinador::registre &r)
{
    short hora_registre = r.r_instant.hora();
    pair<instant_temporal, cotxe> cotxe_registrat(r.r_instant, cotxe(r.r_matricula, r.r_color));

    auto consulta = _info_cotxes.find(r.r_data);
    if (consulta == _info_cotxes.end())
    {
        vector<list<pair<instant_temporal, cotxe>>> v(24);
        v[hora_registre].push_back(cotxe_registrat);

        pair<data, vector<list<pair<instant_temporal, cotxe>>>> registre_a_inserir(r.r_data, v);
        _info_cotxes.insert(registre_a_inserir);
    }
    else
    {
        consulta->second[hora_registre].push_back(cotxe_registrat);
    }
}

void ordinador::registrar_moto(const ordinador::registre &r) {

}

void ordinador::registrar_vehicle(const ordinador::registre &r)
{

}

list<cotxe> ordinador::llista_vehicles_per_hora(const data& d, short h) const
{
    auto consulta = _info_cotxes.find(d);
    list<cotxe> l;
    if (consulta != _info_cotxes.end())
    {
        if (!consulta->second[h].empty())
        {
            for (auto it_list = consulta->second[h].begin(); it_list != consulta->second[h].end(); ++it_list)
                l.push_back(it_list->second);
        }
    }
    return l;
}

ordinador::registre::registre(const string &tv,
                              const float& v,
                              const string &c,
                              const string &m,
                              const data &d,
                              const instant_temporal &i) : r_tipus_vehicle(tv), r_color(c), r_velocitat(v), r_matricula(m), r_data(d), r_instant(i) {}

ordinador::registre::registre() = default;