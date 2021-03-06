#include "articulo.hpp"
#include "cadena.hpp"
#include "fecha.hpp"
#include <iomanip>

Articulo::Articulo(const Cadena &ref,const Cadena &til,const Fecha &publi,double precio,unsigned stck):referencia_(ref), 
        titulo_(til),f_publi_(publi),precio_(precio),stock_(stck){}

const Cadena Articulo::referencia() const{
    return referencia_;
}

const Cadena Articulo::titulo() const{
    return titulo_;
}

const Fecha Articulo::f_publi() const{
    return f_publi_;
}

unsigned Articulo::stock() const{
    return stock_;
}

unsigned& Articulo::stock(){
    return stock_;
}

double Articulo::precio() const{
    return precio_;
}

double& Articulo::precio(){
    return precio_;
}

std::ostream &operator<<(std::ostream &os, const Articulo &art){
    os << "[" << art.referencia() << "] " <<  art.titulo() << " , " 
        << art.f_publi() << " , " << art.precio(); 
    return os;
}