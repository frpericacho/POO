#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <iostream>
#include "cadena.hpp"
#include "clave.hpp"
#include "tarjeta.hpp"
#include "numero.hpp"
#include "articulo.hpp"

class Usuario{
    public:
        Usuario(const Cadena& , const Cadena& ,const Cadena& ,const Cadena& ,const Clave& );
        class Id_duplicado{
            public:
                Id_duplicado(const Cadena&);
                Cadena idd() const;
            private:
                Cadena id_;
        };

    private:
        Cadena identificador_, nombre_, apellidos_, dirección_;
        Clave clave_;
};

#endif