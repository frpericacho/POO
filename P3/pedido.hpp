#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include "tarjeta.hpp"
#include "fecha.hpp"
#include "articulo.hpp"
#include <ostream>

class Pedido
{
public:
    Pedido(Usuario, Tarjeta &,Fecha );

    class Vacia{
        public:
            Vacia(Usuario &);
            const usuario() const;
        private:
            Usuario *user;
    };

    class Imposrtor{
        public:
            Impostor(Usuario &);
            const usuario() const;
        private:
            Usuario *user;
    };

    class SinStock{
        public:
            SinStock(Articulo &);
            const articulo() const;
        private:
            Articulo *art;
    };

    int numero() const{ return num_; };
    const Tarjeta* tarjeta(){ return tarjeta_; };
    Fecha fecha() const{ return fecha_; };
    double total() const{ return total_; };
    int n_total_pedidos() const{ return N_pedidos; };

private:
    int N_pedidos ;
    int num_ ;
    Tarjeta *tarjeta_ ;
    Fecha fecha_ ;
    double total_ ;
};

std::ostream &operator<<(std::ostream &os, Pedido &P);

#endif