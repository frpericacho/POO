#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iostream>
class Cadena
{
  public:
    explicit Cadena(size_t , char c = ' ');
    Cadena();
    Cadena(const Cadena &);
    Cadena(Cadena &&);
    Cadena(const char *);
    Cadena(const char *, size_t );
    static const size_t npos = -1;
    size_t length() const;
    const char &at(size_t ) const;
    char &at(size_t );
    //operator const char *() const;
    const char* c_str() const;
    const char &operator[](size_t ) const;
    char &operator[](size_t );
    Cadena &operator=(const Cadena &);
    Cadena &operator=(Cadena &&);
    Cadena &operator+=(const Cadena &);
    Cadena substr(size_t begindex, size_t len) const;
    ~Cadena();
  private:
    char *s_;
    size_t tam_;
};

std::ostream& operator<<(ostream&, const Cadena &);
std::istream& operator>>(istream&, Cadena &);
Cadena operator+(const Cadena &, const Cadena &);
bool operator<(const Cadena &, const Cadena &);
bool operator>(const Cadena &, const Cadena &);
bool operator==(const Cadena &, const Cadena &);
bool operator!=(const Cadena &, const Cadena &);
bool operator<=(const Cadena &, const Cadena &);
bool operator>=(const Cadena &, const Cadena &);

#endif 