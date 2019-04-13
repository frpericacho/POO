#ifndef CLAVE_HPP
#define CLAVE_HPP
#include <iostream>
#include "cadena.hpp"

class Clave{
    public:
        Clave(const char* );
        enum Razon{CORTA,ERROR_CRYPT};
        
        class Incorrecta{
            public:
                Incorrecta(Razon r):r_(r){}
                Razon razon() const{
                    return r_;
                }
            private:
                Razon r_;
        };
        
        Cadena clave() const;
        bool verifica(const char* ) const;
    private:
        Cadena clave_;
};

#endif