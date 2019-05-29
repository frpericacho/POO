#ifndef ARTICULO_HPP
#define ARTICULO_HPP
#include <set>
#include "cadena.hpp"
#include "fecha.hpp"

class Autor {
 public:
  Autor(const Cadena &nom, const Cadena &apell, const Cadena &dir)
      : nombre_(nom), apellido_(apell), direccion_(dir) {}
  const Cadena &nombre() const { return nombre_; }
  const Cadena &apellidos() const { return apellido_; }
  const Cadena &direccion() const { return direccion_; }

 private:
  Cadena nombre_, apellido_, direccion_;
};

class Articulo {
 public:
  typedef std::set<Autor *> Autores;
  class Autores_vacios {};
  Articulo(Autores, const Cadena &, const Cadena &, const Fecha &, double);

  const Cadena &referencia() const;
  const Cadena &titulo() const;
  const Fecha &f_publi() const;
  double precio() const { return precio_; }
  double &precio() { return precio_; }
  const Autores &autores() const;

  virtual void impresion_especifica(std::ostream &) const = 0;

  virtual ~Articulo() {}

 private:
  const Autores autor_;
  Cadena referencia_, titulo_;
  Fecha f_publi_;
  double precio_;
};

std::ostream &operator<<(std::ostream &, const Articulo &);

class ArticuloAlmacenable : public Articulo {
 public:
  ArticuloAlmacenable(Autores autr, const Cadena &ref, const Cadena &tit, const Fecha &f,
                      double pr, unsigned stock = 0):
                      Articulo(autr,ref,tit,f,pr), stock_(stock){} 
  unsigned stock() const { return stock_; }
  unsigned &stock() { return stock_; }

  virtual ~ArticuloAlmacenable() {}

 protected:
  unsigned stock_;
};

class Libro : public ArticuloAlmacenable {
 public:
  Libro(Autores autr, const Cadena &ref, const Cadena &tit, const Fecha &f, double pr,
        unsigned pag, unsigned stock = 0):
        ArticuloAlmacenable(autr,ref,tit,f,pr,stock), paginas_(pag){} 
  unsigned n_pag() const { return paginas_; }

  virtual void impresion_especifica(std::ostream &os) const {
    os << paginas_ << " págs., " << stock_ << " unidades.";
  }

 private:
  const unsigned paginas_;
};

class Cederron : public ArticuloAlmacenable {
 public:
  Cederron(Autores autr, const Cadena &ref, const Cadena &tit, const Fecha &f, double pr,
           unsigned tam, unsigned stock = 0):
           ArticuloAlmacenable(autr,ref,tit,f,pr,stock), tam_(tam){} 
  unsigned tam() const { return tam_; }

  virtual void impresion_especifica(std::ostream &os) const {
    os << tam_ << " MB, " << stock_ << " unidades.";
  }

 private:
  const unsigned tam_;
};

class LibroDigital : public Articulo {
 public:
  LibroDigital(Autores autr, const Cadena & ref, const Cadena & tit, const Fecha & f, double pr,
               const Fecha &fexp):
               Articulo(autr,ref,tit,f,pr), f_(fexp){} 
  const Fecha &f_expir() const { return f_; }

  virtual void impresion_especifica(std::ostream &os) const {
    os << "A la venta hasta el " << f_ << '.';
  }

 private:
  Fecha f_;
};

#endif