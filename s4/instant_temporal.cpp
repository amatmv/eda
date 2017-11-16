// Amat Martínez Vilà
// u1939654
// Sessió 4

#include "instant_temporal.h"

instant_temporal::instant_temporal() = default;

instant_temporal::instant_temporal(const string& h)
{
    struct tm tm;
    if (strptime(h.c_str(), "%H:%M:%S", &tm))
    {
        _hores = (short)tm.tm_hour;
        _minuts = (short)tm.tm_min;
        _segons = (short)tm.tm_sec;
    }
}

short instant_temporal::hora() const {
    return _hores;
}

short instant_temporal::minut() const {
    return _minuts;
}

short instant_temporal::segon() const {
    return _segons;
}
