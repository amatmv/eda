//#include "ordinador.h"
//struct ordinador::data
//{
//    short dia;
//    short mes;
//    short any;
//
//    ordinador::data() = default;
//
//    ordinador::data(const string& d)
//    {
//        struct tm tm;
//        if (strptime(d.c_str(), "%d/%m/%Y", &tm))
//        {
//            dia = (short)tm.tm_mday;
//            mes = (short)(tm.tm_mon + 1);
//            any = (short)(tm.tm_year + 1900);
//        }
//    }
//
//    bool ordinador::data::operator==(const ordinador::data &d) const
//    {
//        return any == d.any and mes == d.mes and dia == d.dia;
//    }
//
//    bool operator== (const ordinador::data &d) const;
//};
//
//namespace std
//{
//    template <>
//    struct hash<data>
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
