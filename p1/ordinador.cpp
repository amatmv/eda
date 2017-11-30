// Amat Martínez Vilà
// u1939654
//

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
    short hora_registre = r.r_instant.hora;
    pair<cotxe, short> registre_velocitat(cotxe(r.r_matricula, r.r_color), 0);
    pair<instant_temporal, pair<cotxe, int>> cotxe_registrat(r.r_instant, registre_velocitat);

    auto consulta = _info_cotxes.find(r.r_data);
    if (consulta == _info_cotxes.end())
    {
        vector<list<pair<instant_temporal, pair<cotxe, short>>>> v(24);
        v[hora_registre].emplace_back(cotxe_registrat);

        pair<ordinador::data, vector<list<pair<instant_temporal, cotxe>>>> registre_a_inserir(r.r_data, v);
        _info_cotxes.insert(registre_a_inserir);
    }
    else
    {
        consulta->second[hora_registre].emplace_back(cotxe_registrat);
    }
}

void ordinador::registrar_moto(const ordinador::registre &r) {

}

void ordinador::registrar_vehicle(const ordinador::registre &r)
{

}

ordinador::nat ordinador::vehicles_hora(const ordinador::data& d, thora h) const
{
    list<cotxe> llista_vehicles_hora = llista_vehicles_per_hora(d, h);
    return (nat)llista_vehicles_hora.size();
}

list<ordinador::thora> ordinador::horaMaxVelCotxesiMotos() const
{
//    map<ordinador::data, vector<list<pair<instant_temporal, pair<cotxe, short>>>>> _info_cotxes;
    for (auto it_cotxes = _info_cotxes.begin(); it_cotxes != _info_cotxes.end(); ++it_cotxes)
    {
        for (auto it_hores = it_cotxes->second.begin(); it_hores != it_cotxes->second.end(); ++it_hores)
        {
            int vel_acumulada = 0, cotxes = 0;
            for (auto it_cotxes = it_hores->begin();it_cotxes != it_hores->end(); ++it_cotxes)
            {
                vel_acumulada += it_cotxes->second.second;
                cotxes++;
            }

        }
    }
    list<cotxe> llista_vehicles_hora;
    list<thora> hora_max_vel;
}

list<cotxe> ordinador::llista_vehicles_per_hora(const ordinador::data& d, short h) const
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
                              const ordinador::data &d,
                              const instant_temporal &i) :
        r_tipus_vehicle(tv), r_color(c),
        r_velocitat(v), r_matricula(m),
        r_data(d), r_instant(i) {}

ordinador::data::data(const string& d)
{
    struct tm tm;
    if (strptime(d.c_str(), "%d/%m/%Y", &tm))
    {
        dia = (short)tm.tm_mday;
        mes = (short)(tm.tm_mon + 1);
        any = (short)(tm.tm_year + 1900);
    }
}

bool ordinador::data::operator==(const ordinador::data &d) const
{
    return any == d.any and mes == d.mes and dia == d.dia;
}

bool ordinador::data::operator<(const ordinador::data &d) const
{
    if (any < d.any)
        return true;
    else if (any > d.any)
        return false;
    // any == d.any
    if (mes < d.mes)
        return true;
    else if (mes > d.mes)
        return false;
    // mes == d.mes
    if (dia < d.dia)
        return true;
    else
        return false;
}

ordinador::instant_temporal::instant_temporal() = default;

ordinador::instant_temporal::instant_temporal(const string& h)
{
    struct tm tm;
    if (strptime(h.c_str(), "%H:%M:%S", &tm))
    {
        hora = (short)tm.tm_hour;
        minut = (short)tm.tm_min;
        segon = (short)tm.tm_sec;
    }
}

//namespace std
//{
//    template <>
//    struct hash<ordinador::data>
//    {
//        /// @pre --
//        /// @post redefinició del hasher de la data
//        size_t operator()(const ordinador::data& k) const
//        {
//            return ((hash<short>()(k.any)
//                     ^ (hash<short>()(k.mes) << 1)) >> 1)
//                   ^ (hash<short>()(k.dia) << 1);
//        }
//    };
//}
