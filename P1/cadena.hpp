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
    size_t length() const;
    const char &at(size_t indice) const;
    char &at(size_t indice);
    //operator const char *() const;
    const char* c_str() const;
    const char &operator[](size_t indice) const;
    char &operator[](size_t indice);
    Cadena &operator=(const Cadena &cad);
    Cadena &operator+=(const Cadena &cad);
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