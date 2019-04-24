#include <iostream>
#include "usuario.hpp"

Usuario::Id_duplicado::Id_duplicado(const Cadena &cad) : id_(cad) {}

Cadena Usuario::Id_duplicado::idd() const
{
    return id_;
}

Usuario::Usuario(const Cadena &id, const Cadena &nomb, const Cadena &apell, const Cadena &dir, const Clave &clv) : identificador_(id), nombre_(nomb), apellidos_(apell), dirección_(dir), clave_(clv) {}

void Usuario::es_titular_de(Tarjeta &){

}
void Usuario::no_es_titular_de(Tarjeta &){

}

Cadena Usuario::id() const{
    return identificador_;
}

Cadena Usuario::nombre() const{
    return nombre_;
}

Cadena Usuario::apellidos() const{
    return apellidos_;
}

Cadena Usuario::direccion() const{
    return dirección_;
}

//const Tarjeta &tarjetas() const{          HAY QUE PONER LAS TARJETAS
//  return t_;
//}          
void Usuario::compra(Articulo &, unsigned){

}

const Articulo &Usuario::compra() const{

}

size_t Usuario::n_articulos() const{

}