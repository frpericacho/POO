#include "pedido.hpp"


Pedido::Pedido(Usuario user, Tarjeta &tar, Fecha f){

}

std::ostream &operator<<(std::ostream &os, Pedido &P)
{
    return os   << "Num. pedido: " << P.numero() << std::endl
                << "Fecha: " << P.fecha() << std::endl
                << "Pagado con: " << P.tarjeta() << std::endl
                << "Importe: " << P.total() << std::endl;
}