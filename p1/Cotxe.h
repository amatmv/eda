#ifndef P1_COTXE_H
#define P1_COTXE_H

#include "Vehicle.h"

/**
* @brief Implementació de %Vehicle que representa un Cotxe
*/
class Cotxe : public Vehicle
{

public:
    /// @pre Cert
    /// @post constructor per defecte
    Cotxe () = default;

    /// @pre Cert
    /// @post constructor amb paràmetres
    Cotxe (const std::string &matricula, std::string color) :
            Vehicle(matricula), _color(std::move(color)) {}

    /// @pre Cert
    /// @post destructor de cotxe.
    ~Cotxe() = default;

    /// @pre Cert
    /// @post getter que retorna el color del %cotxe.
    std::string color () const override;

    /// @pre Cert
    /// @post getter que retorna la matrícula del %cotxe.
    std::string matricula () const override;

private:

    std::string _color;

};


#endif //P1_COTXE_H
