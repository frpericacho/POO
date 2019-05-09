#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include "tarjeta.hpp"
#include "fecha.hpp"
#include <ostream>

class pedido
{
public:
    pedido();

    class Vacia{
        public:

        private:

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

#endif