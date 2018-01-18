// Amat Martínez Vilà
// u1939654
// Practica d'algorísmica

#include <climits>
#include "SolucioNadal.h"

SolucioNadal::SolucioNadal()
{
    _total_aversio = INT_MAX;
}

SolucioNadal::SolucioNadal(const int &tamany,
                           const std::vector<std::vector<int>>& aversions,
                           const std::string* convidats)
{
    construirEstructures(tamany, aversions, convidats);
}

SolucioNadal::SolucioNadal(const int &tamany,
                           const int& aversio_max,
                           const std::vector<std::vector<int>>& aversions,
                           const std::string* convidats)
{
    construirEstructures(tamany, aversions, convidats);
    _max_aversio = aversio_max;
}

bool SolucioNadal::acceptableOptim(const CandidatsTaula &iCan) const
{
    return !_convidats[iCan.actual()].second;
}

bool SolucioNadal::acceptable(const CandidatsTaula &iCan) const
{
    int convidat_actual = iCan.actual();

    if (!_convidats[convidat_actual].second)
    {
        std::vector<int> veins = convidatsVeins(_nivell);
        for (const auto& vei : veins)
            if (vei != -1 && !compatibles(convidat_actual, vei) || convidat_actual == vei)
                return false;
        return true;
    }
    return false;
}

bool SolucioNadal::completa() const
{
    // Si el nombre de canidats es parell, conve mirar la posicio y=0. Si es imparell, mirarem la n_convidats
    int y_max = _n_convidats % 2 == 0 ? 0 : _n_convidats/2;

    return _nivell.first == y_max && _nivell.second == 2
           && _taula[_nivell.first][_nivell.second] > -1;
}

bool SolucioNadal::esMillor(const SolucioNadal &optima) const
{
    return _total_aversio == INT_MAX || _total_aversio < optima._total_aversio;
}

bool SolucioNadal::esPotMillorar(const SolucioNadal &optima)
{
    return esMillor(optima);
}

CandidatsTaula SolucioNadal::inicialitzarConjuntCandidats() const
{
    return CandidatsTaula(_n_convidats);
}

void SolucioNadal::actualitzarMaximesAversionsVeins(const int &convidat_actual, const posicio &pos_actual)
{
    for (auto& vei : posicionsVeines(pos_actual))
    {
        if (_taula[vei.first][vei.second] != -1)
            actualitzarMaximesAversions(_taula[vei.first][vei.second], vei);
    }
}

void SolucioNadal::actualitzarMaximesAversions(const int &convidat_actual, const posicio& pos_actual)
{
    std::vector<int> veins = convidatsVeins(pos_actual);
    if (!veins.empty())
    {
        if (_total_aversio != INT_MAX)
            _total_aversio -= _max_aversions[convidat_actual];
        int max_aversio = 0;
        for (auto& vei : veins)
            if (vei != -1 && _aversions[convidat_actual][vei] > max_aversio)
                max_aversio = _aversions[convidat_actual][vei];
        if (_total_aversio == INT_MAX)
            _total_aversio = 0;
        _max_aversions[convidat_actual] = max_aversio;
        _total_aversio += max_aversio;
    }
}

void SolucioNadal::anotar(const CandidatsTaula &iCan)
{
    int convidat_actual = iCan.actual();
    int ultima_pos = (int) round(_n_convidats/2.0)-1;

    _convidats[convidat_actual].second = true;
    _taula[_nivell.first][_nivell.second] = convidat_actual;
    actualitzarMaximesAversions(convidat_actual, _nivell);
    actualitzarMaximesAversionsVeins(convidat_actual, _nivell);
    if (_nivell.first == 0 && _nivell.second == 1)
        _nivell.first++;
    else
    {
        if (_nivell.second == 2)
        {
            if (_nivell.first == ultima_pos && _n_convidats % 2 == 0)
                _nivell.first = 0;
            else if (_nivell.first > 0 && _nivell.first < ultima_pos)
            {
                _nivell.first++;
                _nivell.second = 1;
            }
        }
        else
            _nivell.second = 2;
    }
}

void SolucioNadal::desanotar(const CandidatsTaula &iCan)
{
    if (_nivell != posicio(0,1))
    {
        int ultima_pos = (int) round(_n_convidats/2.0)-1;
        if (_nivell.first == 0 && _nivell.second == 2)
        {
            if (ultima_pos == 0)
                _nivell.second--;
            else
                _nivell.first = ultima_pos;
        }
        else if (_nivell.first == 1 && _nivell.second == 1)
            _nivell.first--;
        else {
            if (_nivell.second == 1)
            {
                _nivell.first--;
                _nivell.second++;
            }
            else
                _nivell.second--;
        }
    }
    int convidat_actual = iCan.actual();
    _total_aversio -= _max_aversions[convidat_actual];
    _max_aversions[convidat_actual] = 0;
    _convidats[convidat_actual].second = false;
    _taula[_nivell.first][_nivell.second] = -1;
    actualitzarMaximesAversionsVeins(convidat_actual, _nivell);
}

bool SolucioNadal::compatibles(const int& a, const int& b) const
{
    return _aversions[a][b] <= _max_aversio && _aversions[b][a] <= _max_aversio;
}

void SolucioNadal::mostrar() const
{
    if (_n_convidats > 0 && !_convidats.empty())
    {
        int y_max = _n_convidats > 1 ? _n_convidats/2 - 1 : 1;
        std::cout << "ce " << _convidats[_taula[0][1]].first << " " << _max_aversions[_taula[0][1]] << std::endl;
        for (int i = 1; i <= y_max; i++)
        {
            for (int j = 1; j <= 2; j++)
                std::cout << "c" << i << "," << j << "\t"
                          << _convidats[_taula[i][j]].first
                          << " " << _max_aversions[_taula[i][j]] << std::endl;
        }
        if (_n_convidats % 2 == 0)
            std::cout << "cd " << _convidats[_taula[0][2]].first
                      << " " << _max_aversions[_taula[0][2]] << std::endl;
        else
            std::cout << "cd desconegut" << std::endl;
        std::cout << "Total maxima aversió: " << _total_aversio << std::endl;
    }
}

std::vector<int> SolucioNadal::convidatsVeins(const posicio &pos_act) const
{
    std::vector<int> veins;
    for (const auto& pos_veina : posicionsVeines(pos_act))
        if (_taula[pos_veina.first][pos_veina.second] != -1)
            veins.push_back(_taula[pos_veina.first][pos_veina.second]);
    return veins;
}

void SolucioNadal::construirEstructures(const int &tamany,
                                        const std::vector<std::vector<int>> &aversions,
                                        const std::string *convidats)
{
    if (tamany < 4)
    {
        std::cerr << "Hi ha d'haver 4 convidats mínim" << std::endl;
        throw(-1);
    }
    _aversions = std::vector<std::vector<int>>(tamany, std::vector<int>(tamany, 0));
    _n_convidats = tamany;
    int limit = tamany/2;
    _taula = new int*[limit];
    for (int k = 0; k < limit; ++k)
    {
        _taula[k] = new int[3];
        for (int i = 0; i < 3; ++i)
            _taula[k][i] = -1;
    }
    _convidats = std::vector<std::pair<std::string,bool>>(tamany);
    _nivell = std::pair<int,int>(0,1);
    for (int i = 0; i < tamany; i++)
    {
        _convidats[i].first = convidats[i];
        _convidats[i].second = false;
        for (int j = 0; j < tamany; j++)
            _aversions[i][j] = aversions[i][j];
    }
    _max_aversions = std::vector<int>(tamany, 0);
    _total_aversio = INT_MAX;
}

std::vector<SolucioNadal::posicio> SolucioNadal::posicionsVeines(const posicio &pos_actual) const
{
    std::vector<posicio> veins;
    int ultima_pos = (int) round(_n_convidats/2.0)-1;
    if (pos_actual.first == 0 && pos_actual.second == 1)
    {
        return {posicio(1,1),
                posicio(1,2)};
    }
    else if (pos_actual.first == 0 && pos_actual.second == 2)
    {
        return {posicio(ultima_pos,1),
                posicio(ultima_pos,2)};
    }
    else
    {
        int j = pos_actual.second % 2 + 1;
        std::vector<SolucioNadal::posicio> v;
        if (pos_actual.first == 1 && _n_convidats > 4)
        {
            return {posicio(0,1),
                    posicio(1,j),
                    posicio(2,1),
                    posicio(2,2)};
        }
        else if (pos_actual.first == ultima_pos)
        {
            v = {posicio(ultima_pos-1, 1),
                 posicio(ultima_pos-1, 2),
                 posicio(ultima_pos, j)};
            if (_n_convidats % 2 == 0 && _n_convidats > 4)
                v.emplace_back(posicio(0,2));
        }
        else if (_n_convidats > 6)
        {
            return {posicio(pos_actual.first-1,1),
                    posicio(pos_actual.first-1,2),
                    posicio(pos_actual.first,j),
                    posicio(pos_actual.first+1,1),
                    posicio(pos_actual.first+1,2),};
        }
        return v;
    }
}

SolucioNadal SolucioNadal::operator=(SolucioNadal s)
{
    _nivell = s._nivell;
    _convidats = s._convidats;
    _max_aversions = s._max_aversions;
    _n_convidats = s._n_convidats;
    _aversions = s._aversions;
    _max_aversio = s._max_aversio;
    _total_aversio = s._total_aversio;
    int i_max = _n_convidats/2;
    _taula = new int*[i_max];
    for (int i = 0; i < i_max; ++i)
    {
        _taula[i] = new int[3];
        for (int j = 0; j < 3; ++j)
            _taula[i][j] = s._taula[i][j];
    }
    return *this;
}
