#include <iostream>
#include "usuario.hpp"

Usuario::Id_duplicado::Id_duplicado(const Cadena& cad):id_(cad){}

Cadena Usuario::Id_duplicado::idd() const{
    return id_;
}

Usuario::Usuario(const Cadena& id, const Cadena& nomb,const Cadena& apell,const Cadena& dir,const Clave& clv):
identificador_(id), nombre_(nomb), apellidos_(apell), dirección_(dir),clave_(clv){}