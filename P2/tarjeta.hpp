#ifndef TARJETA_HPP
#define TARJETA_HPP
#include <iostream>
#include "cadena.hpp"

class Numero
{
public:
    Numero(const Cadena &cad);
    operator const char *() const;
    enum Razon
    {
        LONGITUD,
        DIGITOS,
        NO_VALIDO
    };
    friend bool operator<(const Numero &A, const Numero &B);

    class Incorrecto
    {
    public:
        Incorrecto(Razon r) : r_(r) {}
        const Razon &razon() const { return r_; }

    private:
        Razon r_;
    };

private:
    Cadena cad_;
    Cadena quitar_espacio(const Cadena &A);
    Cadena mirar_longitud(const Cadena &A);
};

class Tarjeta
{
public:
private:
};

#endif