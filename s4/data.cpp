// Amat Martínez Vilà
// u1939654
// Sessió 4

#include "data.h"

data::data() = default;

data::data(const string& d)
{
    struct tm tm;
    if (strptime(d.c_str(), "%d/%m/%Y", &tm))
    {
        _dia = (short)tm.tm_mday;
        _mes = (short)(tm.tm_mon + 1);
        _any = (short)(tm.tm_year + 1900);
    }
}

short data::dia() const
{
    return _dia;
}

short data::mes() const
{
    return _mes;
}

short data::any() const
{
    return _any;
}

bool data::operator==(const data &d) const
{
    return _any == d._any and _mes == d._mes and _dia == d._dia;
}
