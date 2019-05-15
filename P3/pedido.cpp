#include "pedido.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"
#include <iomanip>
 
Pedido::Pedido(Usuario_Pedido & up,Pedido_Articulo & pa,Usuario &user,const Tarjeta &tar,const Fecha f)
:num_(cant_+1), tarjeta_(&tar),fecha_(f) , total_(0){
    if(user.n_articulos() == 0) 
        throw Vacio(user);
    if(tar.titular() != &user)
        throw Impostor(user);
    if(!tar.activa())
        throw Tarjeta::Desactivada();
    if(f > tar.caducidad())
        throw Tarjeta::Caducada(tar.caducidad());
    bool pedido_vacio = true;

    for(auto &[articulo, cantidad]: user.compra()){
        if(articulo->stock() < cantidad){
            const_cast<Usuario::Articulos&>(user.compra()).clear();
            throw Pedido::SinStock(articulo);
        }
        articulo->stock() -= cantidad;
        pa.pedir(*this, *articulo,articulo->precio(),cantidad);
        total_ += articulo->precio()*cantidad;
        user.compra(*articulo, 0);
        pedido_vacio = false;
    }

    if(pedido_vacio)
        throw Vacio(user);

    up.asocia(user,*this);
    cant_++;
}

int Pedido::n_total_pedidos() noexcept{
    return cant_;
}

std::ostream &operator<<(std::ostream &os,const Pedido &P)
{
    return os <<  std::left << std::setw(13) << "Núm. pedido: " << P.numero() << std::endl <<
                std::left << std::setw(13) << "Fecha:" << P.fecha() << std::endl <<
                std::left << std::setw(13) << "Pagado con:" << P.tarjeta()->tipo() <<
                " n.º: " << P.tarjeta()->numero() << std::endl << 
                std::left << std::setw(13) << "Importe:" <<
                std::fixed << std::setprecision(2) << P.total() << " €" << std::endl;
}