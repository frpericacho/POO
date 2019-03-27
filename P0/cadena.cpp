/*#include <iostream>
#include <cstring>
#include "cadena.hpp"

Cadena::Cadena(size_t tam,char s):tam_(tam){
    s_ = new char[tam+1];
    for(size_t i = 0; i < tam; i++){
        s_[i] = s;
    }
    s_[tam_]='\0';
}

Cadena::Cadena(const char* cad):tam_(strlen(cad)){
    s_ = new char[tam_+1];
    strcpy(s_,cad);
}

Cadena::Cadena(Cadena &&cad):s_(cad.s_), tam_(cad.tam_){
    cad.tam_ = 0;
    cad.s_ = nullptr;
}

Cadena::~Cadena(){delete[] s_;}

const char *Cadena::c_str() const{
    return s_;
}

size_t Cadena::length() const{
    return tam_;
}

Cadena::operator const char*() const{
    return s_;
}


bool operator==(const Cadena &cad1, const Cadena &cad2){
    return (strcmp(cad1.c_str(),cad2.c_str()) == 0);
}

bool operator!=(const Cadena &cad1, const Cadena &cad2){
    return !(cad1==cad2);
}

bool operator>(const Cadena &cad1, const Cadena &cad2){
    return cad2 < cad1;
}

bool operator<(const Cadena &cad1, const Cadena &cad2){
    return (strcmp(cad1.c_str(),cad2.c_str()) < 0);
}

bool operator>=(const Cadena &cad1, const Cadena &cad2){
    return cad1.c_str() == cad2.c_str() || cad2.c_str() < cad1.c_str();
}

bool operator<=(const Cadena &cad1, const Cadena &cad2){
    return cad1.c_str() == cad2.c_str() || cad1.c_str() < cad2.c_str();
}

const char& Cadena::at(size_t index) const{
    if(index < 0 || index >= tam_)
        throw std::out_of_range("fuera de rango");
    return s_[index];
}

char& Cadena::at(size_t index){
    if(index < 0 || index >= tam_)
        throw std::out_of_range("fuera de rango");
    return s_[index];
}

Cadena Cadena::substr(size_t index, size_t b) const
{
    if (index >= this->length() || index + b > this->length() ||
        index + b < index)
        throw std::out_of_range("Error de rango");

    char *tmp = new char[b + 1];
    std::strncpy(tmp, s_ + index, b);
    tmp[b] = '\0';
    Cadena ctmp(tmp);
    delete[] tmp;
    return ctmp;
}*/

#include "cadena.hpp"
#include <cstring>
#include <stdexcept>
using namespace std;

// Constructor Cadena: tamanno, relleno
Cadena::Cadena(size_t n, char c) : tam_(n)
{
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = c;
    s_[tam_] = '\0';
}
// Constructor Cadena: Vacía
Cadena::Cadena() : tam_(0)
{
    s_ = new char[1];
    s_[0] = '\0';
}
// Constructor Cadena: Copia
Cadena::Cadena(const Cadena &cad) : tam_(cad.tam_)
{
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
}
// Constructor Cadena: const char*
Cadena::Cadena(const char *s) : tam_(strlen(s))
{
    s_ = new char[tam_ + 1];
    strcpy(s_, s);
}
// Constructor Cadena: const char*, tamanno
Cadena::Cadena(const char *s, size_t n) : tam_(n)
{
    if (n > strlen(s))
        tam_ = strlen(s);
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = s[i];
    s_[tam_] = '\0';
}

// Constructor Cadena: Cadena, inicial, tamanno
Cadena::Cadena(const Cadena &cad, size_t indice, size_t n) : tam_(n)
{
    if (indice > cad.tam_ - 1)
        throw out_of_range("Error: Indice fuera de rango...");
    if (n == Cadena::npos || n > cad.tam_ - indice)
        tam_ = cad.tam_ - indice;
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = cad.s_[i + indice];
    s_[tam_] = '\0';
}
// Destructor
Cadena::~Cadena() { delete[] s_; }
// Operador =
Cadena &Cadena::operator=(const Cadena &cad)
{
    tam_ = cad.tam_;
    delete[] s_;
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
    return *this;
}
// Conversion a const char*
Cadena::operator const char *() const { return s_; }
//Observador
size_t Cadena::length() const { return tam_; }
// Operador +=
Cadena &Cadena::operator+=(const Cadena &cad)
{
    char *tmp = new char[tam_ + 1];
    strcpy(tmp, s_);
    delete[] s_;
    tam_ += cad.tam_;
    s_ = new char[tam_ + 1];
    strcpy(s_, tmp);
    strcat(s_, cad.s_);
    return *this;
}
// Operador +
Cadena operator+(const Cadena &a, const Cadena &b)
{
    Cadena tmp(a);
    tmp += b;
    return tmp;
}

// Operador <
bool operator<(const Cadena &a, const Cadena &b) { return strcmp(a, b) < 0; }
// Operador >
bool operator>(const Cadena &a, const Cadena &b) { return b < a; }
// Operador ==
bool operator==(const Cadena &a, const Cadena &b) { return strcmp(a, b) == 0; }
// Operador !=
bool operator!=(const Cadena &a, const Cadena &b) { return !(a == b); }
// Operador <=
bool operator<=(const Cadena &a, const Cadena &b) { return a == b || a < b; }
// Operador >=
bool operator>=(const Cadena &a, const Cadena &b) { return a == b || b < a; }
// Operador at lectura
const char &Cadena::at(size_t indice) const
{
    if (indice < 0 || indice >= tam_)
        throw out_of_range("Error: Indice fuera de rango...");
    return s_[indice];
}
// Operador at escritura
char &Cadena::at(size_t indice)
{
    if (indice < 0 || indice >= tam_)
        throw out_of_range("Error: Indice fuera de rango...");
    return s_[indice];
}
// Operador [] lectura
const char &Cadena::operator[](size_t indice) const { return s_[indice]; }
// Operador [] escritura
char &Cadena::operator[](size_t indice) { return s_[indice]; }
// substr
Cadena Cadena::substr(size_t indice, size_t n) const
{
    if (indice >= tam_ || n > tam_ - indice)
        throw out_of_range("Error: Indice fuera de rango...");
    return Cadena(*this, indice, n);
}

