//
// Created by amat on 1/11/17.
//

#ifndef P1_COTXE_H
#define P1_COTXE_H

#include "vehicle.h"

class cotxe : public vehicle
{

public:
    /// @pre --
    /// @post constructor per defecte
    cotxe() = default;

    /// @pre --
    /// @post constructor amb paràmetres
    cotxe(const string& matricula, const string& color);
private:
    string _color;

};


#endif //P1_COTXE_H
