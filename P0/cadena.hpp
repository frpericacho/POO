#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iostream>

class Cadena{
  public:
    explicit Cadena(size_t , char c = ' ');
    Cadena();
    Cadena(const Cadena &);
    Cadena(const char *);
    Cadena(const char *, size_t );
    Cadena(const Cadena &, size_t , size_t n = npos);
    static const size_t npos = -1;
    Cadena &operator=(const Cadena &);
    operator const char *() const;
    size_t length() const;
    Cadena &operator+=(const Cadena &);
    const char &at(size_t ) const;
    char &at(size_t );
    const char &operator[](size_t ) const;
    char &operator[](size_t );
    Cadena substr(size_t , size_t ) const;

    ~Cadena();
  private:
    char *s_;
    size_t tam_;
};

Cadena operator+(const Cadena &, const Cadena &);
bool operator<(const Cadena &, const Cadena &);
bool operator>(const Cadena &, const Cadena &);
bool operator==(const Cadena &, const Cadena &);
bool operator!=(const Cadena &, const Cadena &);
bool operator<=(const Cadena &, const Cadena &);
bool operator>=(const Cadena &, const Cadena &);

#endif 