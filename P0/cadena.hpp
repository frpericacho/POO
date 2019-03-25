#ifndef CADENA_HPP
#define CADENA_HPP
#include<iostream>

class Cadena{
    public:
    Cadena(int , char* );
    Cadena(int );
    Cadena(const Cadena&);
    Cadena(const char*);

    private:
    char *s_;
    int tam_;
};


#endif