#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include "tarjeta.hpp"
#include "fecha.hpp"
#include "articulo.hpp"
#include <ostream>

class Pedido_Articulo;
class Usuario_Pedido;

class Pedido
{
public:
    Pedido(Usuario, Tarjeta &,Fecha );

    class Vacia{
        public:
            Vacia(Usuario &u):user(&u){};
            Usuario &usuario() const{return *user;}
        private:
            Usuario *user;
    };

    class Impostor{
        public:
            Impostor(Usuario &u):user(&u){};
            Usuario &usuario() const {return *user;}
        private:
            Usuario *user;
    };

    class SinStock{
        public:
            SinStock(Articulo *art): art_(art){};
            Articulo &articulo() const {return *art_;}
        private:
            Articulo *art_;
    };

    int numero() const{ return num_; };
    const Tarjeta* tarjeta(){ return tarjeta_; };
    Fecha fecha() const{ return fecha_; };
    double total() const{ return total_; };
    int n_total_pedidos() const{ return cant_; };

private:
    int cant_ ;
    int num_ ;
    Tarjeta *tarjeta_ ;
    Fecha fecha_ ;
    double total_ ;
};

std::ostream &operator<<(std::ostream &os, Pedido &P);

#endif