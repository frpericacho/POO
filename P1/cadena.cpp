#include "cadena.hpp"
#include <cstring>
#include <stdexcept>
using namespace std;

Cadena::Cadena(size_t n, char c) : tam_(n)
{
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = c;
    s_[tam_] = '\0';
}

Cadena::Cadena() : tam_(0)
{
    s_ = new char[1];
    s_[0] = '\0';
}

Cadena::Cadena(const Cadena &cad) : tam_(cad.tam_)
{
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
}

Cadena::Cadena(Cadena &&cad): tam_{cad.tam_}, s_{cad.s_}
{
    cad.s_ = nullptr;
    tam_ = 0;
}

Cadena::Cadena(const char *s) : tam_(strlen(s))
{
    s_ = new char[tam_ + 1];
    strcpy(s_, s);
}

Cadena::Cadena(const char *s, size_t n) : tam_(n)
{
    if (n > strlen(s))
        tam_ = strlen(s);
    s_ = new char[tam_ + 1];
    for (size_t i = 0; i < tam_; i++)
        s_[i] = s[i];
    s_[tam_] = '\0';
}

Cadena::~Cadena()
{
    delete[] s_;
}

Cadena& Cadena::operator=(const Cadena &cad)
{
    tam_ = cad.tam_;
    delete[] s_;
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
    return *this;
}

Cadena& Cadena::operator=(Cadena &&cad)
{
    if(this != &cad){
        delete[] s_;
        s_ = cad.s_;
        tam_ = cad.tam_;
        cad.s_ = nullptr;
        cad.tam_ = 0;
    }
    return *this;
}

/*Cadena::operator const char *() const{ 
    return s_; 
}*/

const char *Cadena::c_str() const
{
    return s_;
}

size_t Cadena::length() const
{
    return tam_;
}

Cadena& Cadena::operator+=(const Cadena &cad)
{
    char *aux = new char[tam_ + 1];
    strcpy(aux, s_);
    delete[] s_;
    tam_ += cad.tam_;
    s_ = new char[tam_ + 1];
    strcpy(s_, aux);
    strcat(s_, cad.s_);
    return *this;
}

Cadena operator+(const Cadena &cad1, const Cadena &cad2)
{
    Cadena aux(cad1);
    aux += cad2;
    return aux;
}

bool operator<(const Cadena &cad1, const Cadena &cad2)
{
    return strcmp(cad1.c_str(), cad2.c_str()) < 0;
}

bool operator>(const Cadena &cad1, const Cadena &cad2)
{
    return cad2 < cad1;
}

bool operator==(const Cadena &cad1, const Cadena &cad2)
{
    return strcmp(cad1.c_str(), cad2.c_str()) == 0;
}

bool operator!=(const Cadena &cad1, const Cadena &cad2)
{
    return !(cad1 == cad2);
}

bool operator<=(const Cadena &cad1, const Cadena &cad2)
{
    return cad1 == cad2 || cad1 < cad2;
}

bool operator>=(const Cadena &cad1, const Cadena &cad2)
{
    return cad1 == cad2 || cad2 < cad1;
}

const char &Cadena::at(size_t index) const
{
    if (index < 0 || index >= tam_)
        throw std::out_of_range("fuera de rango");
    return s_[index];
}

char &Cadena::at(size_t index)
{
    if (index < 0 || index >= tam_)
        throw std::out_of_range("fuera de rango");
    return s_[index];
}

const char &Cadena::operator[](size_t index) const
{
    return s_[index];
}

char &Cadena::operator[](size_t index)
{
    return s_[index];
}

Cadena Cadena::substr(size_t index, size_t n) const
{
    if (index >= this->length() || index + n > this->length() || index + n < index)
        throw std::out_of_range("fuera de rango");

    char *aux = new char[n + 1];
    std::strncpy(aux, s_ + index, n);
    aux[n] = '\0';

    Cadena cad(aux);
    delete[] aux;

    return cad;
}

std::ostream &operator<<(ostream &out, const Cadena &cad)
{
    out << cad.c_str();
    return out;
}

std::istream &operator>>(istream &in, Cadena &cad)
{
    char *aux = new char[32];
    size_t cont = 0;
    char a;
    
    while(in.good() && isspace(in.get()));
    in.unget();

    while(in.good() && !isspace(in.peek()) && cont < 31){
        a = in.get();
        if(in.good())
            aux[cont++] = a;
    }
    aux[cont] = '\0';

    if(in.good() && in.peek() != ' ')
        in.ignore();
    
    cad = Cadena(aux);
    return in;
}