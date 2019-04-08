#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iostream>
#include <iterator>
class Cadena
{
public:
  explicit Cadena(size_t, char c = ' ');
  Cadena();
  Cadena(const Cadena &);
  Cadena(Cadena &&);
  Cadena(const char *);
  Cadena(const char *, size_t);

  static const size_t npos = -1;
  size_t length() const;
  const char &at(size_t) const;
  char &at(size_t);
  //operator const char *() const;
  const char *c_str() const;

  const char &operator[](size_t) const;
  char &operator[](size_t);
  Cadena &operator=(const Cadena &);
  Cadena &operator=(Cadena &&);
  Cadena &operator+=(const Cadena &);
  Cadena substr(size_t begindex, size_t len) const;

  using iterator = char *;
  using const_iterator = const char *;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  iterator begin(){ 
    return s_; 
  }
  iterator end(){ 
    return s_ + tam_; 
  }
  const_iterator begin() const{ 
    return s_; 
  }
  const_iterator end() const{ 
    return s_ + tam_; 
  }
  const_iterator cbegin() const{ 
    return s_; 
  }
  const_iterator cend() const{ 
    return s_ + tam_; 
  }
  reverse_iterator rbegin(){ 
    return reverse_iterator(end()); 
  }
  reverse_iterator rend(){ 
    return reverse_iterator(begin()); 
  }
  const_reverse_iterator rend() const{ 
    return const_reverse_iterator(begin()); 
  }
  const_reverse_iterator rbegin() const{ 
    return const_reverse_iterator(end()); 
  }
  const_reverse_iterator crbegin() const{ 
    return const_reverse_iterator(end()); 
  }
  const_reverse_iterator crend() const{ 
    return const_reverse_iterator(begin()); 
  }

  ~Cadena();

private:
  char *s_;
  size_t tam_;
};

std::ostream &operator<<(std::ostream &, const Cadena &);
std::istream &operator>>(std::istream &, Cadena &);
Cadena operator+(const Cadena &, const Cadena &);
bool operator<(const Cadena &, const Cadena &);
bool operator>(const Cadena &, const Cadena &);
bool operator==(const Cadena &, const Cadena &);
bool operator!=(const Cadena &, const Cadena &);
bool operator<=(const Cadena &, const Cadena &);
bool operator>=(const Cadena &, const Cadena &);

#endif