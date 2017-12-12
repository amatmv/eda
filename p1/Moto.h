#ifndef P1_MOTO_H
#define P1_MOTO_H

#include <iostream>
#include "Vehicle.h"

/**
* @brief Implementació de %Vehicle que representa una moto.
*/
class Moto : public Vehicle
{
public:
    /// @pre Cert
    /// @post constructor per defecte del vehicle
    Moto() = default;

    /// @pre Cert
    /// @post constructor del vehicle donada una matrícula
    explicit Moto (std::string matricula) : _matricula (std::move(matricula)) {}

    /// @pre Cert
    /// @post getter que retorna la matrícula de la %moto
    std::string matricula() const override;

protected:

    std::string _matricula;

};

#endif //P1_MOTO_H
