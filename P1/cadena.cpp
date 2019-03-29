#include "cadena.hpp"
#include <cstring>
#include <stdexcept>
using namespace std;

Cadena::Cadena(size_t n, char c) : tam_(n){
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = c;
    s_[tam_] = '\0';
}

Cadena::Cadena() : tam_(0){
    s_ = new char[1];
    s_[0] = '\0';
}

Cadena::Cadena(const Cadena &cad) : tam_(cad.tam_){
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
}

Cadena::Cadena(const char *s) : tam_(strlen(s)){
    s_ = new char[tam_ + 1];
    strcpy(s_, s);
}

Cadena::Cadena(const char *s, size_t n) : tam_(n){
    if (n > strlen(s))
        tam_ = strlen(s);
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = s[i];
    s_[tam_] = '\0';
}

Cadena::Cadena(const Cadena &cad, size_t indice, size_t n) : tam_(n){
    if (indice > cad.tam_ - 1)
        throw out_of_range("Error: Indice fuera de rango...");
    if (n == Cadena::npos || n > cad.tam_ - indice)
        tam_ = cad.tam_ - indice;
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = cad.s_[i + indice];
    s_[tam_] = '\0';
}

Cadena::~Cadena(){ 
    delete[] s_; 
}

Cadena &Cadena::operator=(const Cadena &cad){
    tam_ = cad.tam_;
    delete[] s_;
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
    return *this;
}

/*Cadena::operator const char *() const{ 
    return s_; 
}*/

const char* Cadena::c_str() const{
    return s_;
}

size_t Cadena::length() const{ 
    return tam_; 
}

Cadena &Cadena::operator+=(const Cadena &cad){
    char *tmp = new char[tam_ + 1];
    strcpy(tmp, s_);
    delete[] s_;
    tam_ += cad.tam_;
    s_ = new char[tam_ + 1];
    strcpy(s_, tmp);
    strcat(s_, cad.s_);
    return *this;
}

Cadena operator+(const Cadena &a, const Cadena &b){
    Cadena tmp(a);
    tmp += b;
    return tmp;
}

bool operator<(const Cadena &a, const Cadena &b){
    return strcmp(a.c_str(), b.c_str()) < 0;
}

bool operator>(const Cadena &a, const Cadena &b){ 
    return b < a; 
}

bool operator==(const Cadena &a, const Cadena &b){ 
    return strcmp(a.c_str(), b.c_str()) == 0; 
}

bool operator!=(const Cadena &a, const Cadena &b){ 
    return !(a == b); 
}

bool operator<=(const Cadena &a, const Cadena &b){ 
    return a == b || a < b; 
}

bool operator>=(const Cadena &a, const Cadena &b){ 
    return a == b || b < a; 
}

const char &Cadena::at(size_t indice) const{
    if (indice < 0 || indice >= tam_)
        throw out_of_range("Error: Indice fuera de rango...");
    return s_[indice];
}

char &Cadena::at(size_t indice){
    if (indice < 0 || indice >= tam_)
        throw out_of_range("Error: Indice fuera de rango...");
    return s_[indice];
}

const char &Cadena::operator[](size_t indice) const{ 
    return s_[indice]; 
}

char &Cadena::operator[](size_t indice){
    return s_[indice]; 
}

Cadena Cadena::substr(size_t indice, size_t n) const{
    if (indice >= tam_ || n > tam_ - indice)
        throw out_of_range("Error: Indice fuera de rango...");
    return Cadena(*this, indice, n);
}

