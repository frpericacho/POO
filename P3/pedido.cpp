#include "pedido.hpp"


Pedido::Pedido(Usuario_Pedido & up,Pedido_Articulo & pa,Usuario user, Tarjeta &tar, Fecha f)
:num_(cant_+1), tarjeta_(&tar){
    if(user.n_articulos() == 0) 
        throw Vacia(user);
    if(tar.titular() != &user)
        throw Impostor(user);
    if(f > tar.caducidad())
        throw Tarjeta::Caducada(tar.caducidad());
    for(auto i = user.compra().begin();i != user.compra().end(); i++){
        if(i->second > i->first->stock()){
            const_cast<Usuario::Articulos&>(user.compra()).clear();
            throw SinStock(i->first);
        }
    }
}

std::ostream &operator<<(std::ostream &os, Pedido &P)
{
    return os   << "Num. pedido: " << P.numero() << std::endl
                << "Fecha: " << P.fecha() << std::endl
                << "Pagado con: " << P.tarjeta() << std::endl
                << "Importe: " << P.total() << " €" << std::endl;
}