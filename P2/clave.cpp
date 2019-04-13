#include "clave.hpp"
#include "cadena.hpp"
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <crypt.h>

Clave::Clave(const char* cad){
    if(strlen(cad) < 5)
        Incorrecta(Clave::CORTA);
    const char* c ="abcdefg";
    char salt[2];
    salt[0] = c[rand() % 7];
    salt[1] = c[rand() % 7];
    if(crypt(cad,salt) == nullptr)
        throw Incorrecta(Clave::ERROR_CRYPT);
    clave_ = crypt(cad,salt);
}

Cadena Clave::clave() const{
    return clave_;
} 

bool Clave::verifica(const char* cad) const{
    return clave_ == crypt(cad, clave_.c_str());
}