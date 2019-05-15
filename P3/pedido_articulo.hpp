#ifndef PEDIDO_ARTICULO_HPP
#define PEDIDO_ARTICULO_cPP
#include <ostream>
#include "articulo.hpp"
#include "pedido.hpp"

class LineaPedido
{
public:
    explicit LineaPedido(double &p, int c = 1) : precvent_(p), cant_(c) {}
    double precio_venta() const { return precvent_; }
    int cantidad() const { return cant_; }

private:
    double precvent_;
    int cant_;
};

struct OrdenaPedidos
{
    bool operator()(const Pedido *ped1, const Pedido *ped2) const
    {
        return (ped1->numero() < ped2->numero());
    }
};

struct OrdenaArticulos
{
    bool operator()(const Articulo *art1, const Articulo *art2) const
    {
        return (art1->referencia() < art2->referencia());
    }
};

class Pedido_Articulo
{
public:
    typedef std::map<Articulo *, LineaPedido, OrdenaArticulos> ItemsPedido;
    typedef std::map<Pedido *, LineaPedido, OrdenaPedidos> Pedidos;
    void pedir(Pedido &ped, Articulo &art, double pr, int cant = 1);
    void pedir(Articulo &art, Pedido &ped, double pr, int cant = 1);
    ItemsPedido &detalle(Pedido &ped);
    Pedidos ventas(Articulo &art);
    std::ostream &mostrarDetallePedidos(std::ostream &);
    std::ostream &mostrarVentasArticulos(std::ostream &);
    //ME FALTA EL PRIMER OSTREAM Y HACER LOS OrdenaArticulos Y OrdenaPedidos

private:
    std::map<Pedido *, ItemsPedido, OrdenaPedidos> PA;
    std::map<Articulo *, Pedidos, OrdenaArticulos> AP;
};

std::ostream &operator<<(std::ostream &os, LineaPedido &lp);
std::ostream &operator<<(std::ostream &os, const Pedido_Articulo::Pedidos &ped);
std::ostream &operator<<(std::ostream &os, const Pedido_Articulo::ItemsPedido &item);
#endif