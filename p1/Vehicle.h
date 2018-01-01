#ifndef P1_VEHICLE_H
#define P1_VEHICLE_H

#include <iostream>

/**
* @brief Classe que representa un %Vehicle genèric
*/
class Vehicle
{
public:
    /// @pre Cert
    /// @post constructor per defecte del %vehicle
    Vehicle() = default;

    /// @pre Cert
    /// @post constructor del %vehicle donada una matrícula
    explicit Vehicle (std::string matricula) : _matricula (std::move(matricula)) {}

    /// @pre Cert
    /// @post mètode abstracte que retorna el color del %vehicle
    virtual std::string color() const {};

    /// @pre Cert
    /// @post mètode abstracte que retorna la matrícula del %vehicle
    virtual std::string matricula() const;

protected:

    std::string _matricula;

};

#endif //P1_VEHICLE_H
