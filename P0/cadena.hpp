/*#ifndef CADENA_HPP
#define CADENA_HPP
#include<iostream>

class Cadena{
    public:
        explicit Cadena(size_t tam = 0, char s = ' '); //
        Cadena(const Cadena&) = default; //
        Cadena(const char*); //
        Cadena(Cadena &&);
        const char* c_str() const;
        const char& at(size_t ) const;
        char& at(size_t );
        Cadena substr(size_t ,size_t ) const;
        size_t length() const;
        operator const char*() const;
        ~Cadena();
    private:
        char *s_;
        size_t tam_;
};

bool operator==(const Cadena &cad1, const Cadena &cad2);
bool operator!=(const Cadena &cad1, const Cadena &cad2);
bool operator>(const Cadena &cad1, const Cadena &cad2);
bool operator<(const Cadena &cad1, const Cadena &cad2);
bool operator>=(const Cadena &cad1, const Cadena &cad2);
bool operator<=(const Cadena &cad1, const Cadena &cad2);

#endif*/
#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iostream>
class Cadena
{
  public:
    explicit Cadena(size_t n, char c = ' ');
    Cadena();
    Cadena(const Cadena &cad);
    Cadena(const char *s);
    Cadena(const char *s, size_t n);
    Cadena(const Cadena &cad, size_t indice, size_t n = npos);
    static const size_t npos = -1;
    Cadena &operator=(const Cadena &cad);
    operator const char *() const;
    size_t length() const;
    Cadena &operator+=(const Cadena &cad);
    const char &at(size_t indice) const;
    char &at(size_t indice);
    const char &operator[](size_t indice) const;
    char &operator[](size_t indice);
    Cadena substr(size_t indice, size_t n) const;

    ~Cadena();
  private:
    char *s_;
    size_t tam_;
};

Cadena operator+(const Cadena &a, const Cadena &b);
bool operator<(const Cadena &a, const Cadena &b);
bool operator>(const Cadena &a, const Cadena &b);
bool operator==(const Cadena &a, const Cadena &b);
bool operator!=(const Cadena &a, const Cadena &b);
bool operator<=(const Cadena &a, const Cadena &b);
bool operator>=(const Cadena &a, const Cadena &b);

#endif 