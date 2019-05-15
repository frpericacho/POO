#include <pedido_articulo.hpp>
#include <iomanip>

std::ostream &operator<<(std::ostream &os, LineaPedido &lp)
{
    os << std::fixed << std::setprecision(2) << lp.precio_venta() << " €    " << lp.cantidad();
    return os;
}

void Pedido_Articulo::pedir(Pedido &ped, Articulo &art, double pr, int cant = 1)
{
    PA[&ped].insert(std::make_pair(&art, LineaPedido(pr, cant)));
    AP[&art].insert(std::make_pair(&ped, LineaPedido(pr, cant)));
}

void Pedido_Articulo::pedir(Articulo &art, Pedido &ped, double pr, int cant = 1)
{
    pedir(ped, art, pr, cant);
}

Pedido_Articulo::ItemsPedido &Pedido_Articulo::detalle(Pedido &ped)
{
    return PA[&ped];
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo &art)
{
    return AP[&art];
}

std::ostream &operator<<(std::ostream &os, const Pedido_Articulo::Pedidos &ped)
{
}

std::ostream &operator<<(std::ostream &os, const Pedido_Articulo::ItemsPedido &item)
{
}

std::ostream &Pedido_Articulo::mostrarDetallePedidos(std::ostream &os)
{
    double total = 0.0;

    for (const auto &i : PA)
    {
        os << "Pedido núm. " << i.first->numero()
           << "\nCliente: " << i.first->tarjeta()->titular()->nombre()
           << "\tFecha: " << i.first->fecha() << i.second;
        total += i.first->total();
    }

    return os << std::fixed << "\nTOTAL VENTAS:\t" << std::setprecision(2)
              << total << " €" << std::endl;
}

std::ostream &Pedido_Articulo::mostrarVentasArticulos(std::ostream &)
{
}