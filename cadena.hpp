#ifndef CADENA_HPP
#define CADENA_HPP
#include<iostream>

using namespace std;

class Cadena{
    public:
    Cadena():tam_(0){}
    Cadena(int , char* );
    Cadena(int );
    Cadena(const Cadena&);
    Cadena(const char*);

    private:
    char *s_;
    int tam_;
};


#endif