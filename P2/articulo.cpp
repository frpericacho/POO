#include "articulo.hpp"
#include "cadena.hpp"
#include "fecha.hpp"

articulo::articulo(Cadena ref,Cadena til,Fecha publi,double precio,unsigned stck):referencia_(ref), 
        titulo_(til),f_publi_(publi),precio_(precio),stock_(stck){}

Cadena articulo::referencia() const{
    return referencia_;
}

Cadena articulo::titulo() const{
    return titulo_;
}

Fecha articulo::f_publi() const{
    return f_publi_;
}

unsigned articulo::stock() const{
    return stock_;
}

unsigned& articulo::stock(){
    return stock_;
}

double articulo::precio() const{
    return precio_;
}

double& articulo::precio(){
    return precio_;
}

std::ostream &operator<<(std::ostream &os, const articulo &art){
    os << "[" << art.referencia() << "] " <<  art.titulo() << " , " 
        << art.f_publi() << " , " << art.precio(); 
    return os;
}