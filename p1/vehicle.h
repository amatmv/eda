//
// Created by amat on 1/11/17.
//

#ifndef P1_VEHICLE_H
#define P1_VEHICLE_H

#include <iostream>

using namespace std;

class vehicle
{

public:
    /// @pre --
    /// @post constructor per defecte del vehicle
    vehicle() = default;

    /// @pre --
    /// @post constructor del vehicle donada una matrícula
    vehicle(const string& matricula);

protected:
    string _matricula;

};


#endif //P1_VEHICLE_H
