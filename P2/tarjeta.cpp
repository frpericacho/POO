#include <iostream>
#include <cstring>
#include "tarjeta.hpp"

bool operator <(const Numero &A, const Numero &B){
    return strcmp(A,B) < 0;
}

Numero::operator const char *() const{
    return cad_.c_str();
}