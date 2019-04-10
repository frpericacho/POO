#ifndef ARTICULO_HPP
#define ARTICULO_HPP
#include <iostream>
#include "cadena.hpp"
#include "fecha.hpp"

class articulo{
    public:
        articulo(Cadena ,Cadena ,Fecha ,double ,unsigned );
        Cadena referencia() const;
        Cadena titulo() const;
        Fecha f_publi() const;
        unsigned stock() const;
        unsigned& stock();
        double precio() const;
        double& precio();

    private:
        Cadena referencia_,titulo_;
        Fecha f_publi_;
        double precio_;
        unsigned stock_;
};

std::ostream &operator<<(std::ostream &, const articulo &);

#endif