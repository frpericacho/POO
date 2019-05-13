#include <pedido_articulo.hpp>
#include <iomanip>

std::ostream &operator<<(std::ostream &os, LineaPedido &lp)
{
    os << std::fixed << std::setprecision(2) << lp.precio_venta() << " €    " << lp.cantidad();
    return os;
}

void Pedido_Articulo::pedir(Pedido &ped, Articulo &art, double pr, int cant = 1){
    PA[&ped].insert(std::make_pair(&art,LineaPedido(pr, cant)));
    AP[&art].insert(std::make_pair(&ped,LineaPedido(pr, cant)));
}

void Pedido_Articulo::pedir(Articulo &art, Pedido &ped, double pr, int cant = 1){
    	pedir(ped,art,pr,cant);
}

ItemsPedido& Pedido_Articulo::detalle(Pedido &ped){
    
    return nullptr;
}

Pedidos Pedido_Articulo::ventas(Articulo &art){
    
}
