#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <iostream>
#include "cadena.hpp"
#include "clave.hpp"
#include "tarjeta.hpp"
#include "numero.hpp"
#include "articulo.hpp"

class Tarjeta;

class Usuario
{
public:
    Usuario(const Cadena &, const Cadena &, const Cadena &, const Cadena &, const Clave &);

    class Id_duplicado
    {
    public:
        Id_duplicado(const Cadena &);
        Cadena idd() const;

    private:
        Cadena id_;
    };

    void es_titular_de(Tarjeta &);
    void no_es_titular_de(Tarjeta &);
    Cadena id() const;
    Cadena nombre() const;
    Cadena apellidos() const;
    Cadena direccion() const;
    //const Tarjeta &tarjetas() const;          HAY QUE PONER LAS TARJETAS
    void compra(Articulo &, unsigned);
    const Articulo &compra() const;
    size_t n_articulos() const;

    private:
    Cadena identificador_,nombre_,apellidos_,dirección_;
    Clave clave_;
    //Tarjeta t_;        HAY QUE PONER LAS TARJETAS
};

#endif