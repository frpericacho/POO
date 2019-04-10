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
                Razon razon() const;
        };
        
        Cadena clave() const;
        bool verifica(const char* );
    private:
        Cadena clave_;
};

#endif