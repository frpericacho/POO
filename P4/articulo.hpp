#ifndef ARTICULO_HPP
#define ARTICULO_HPP
#include <iostream>
#include "cadena.hpp"
#include "fecha.hpp"

class Articulo
{
public:
    Articulo(Autores, const Cadena &, const Cadena &, const Fecha &, double);

    const Cadena referencia() const;
    const Cadena titulo() const;
    const Fecha f_publi() const;
    unsigned stock() const;
    unsigned &stock();
    double precio() const;
    double &precio();

    void impresion_especifica(std::ostream &);

    class Autores_vacios
    {
    public:
        Autores_vacios(Autores &autr) : aut_(&autr) {}
        Autores &autores() const;

    private:
        Autores *aut_;
    };

private:
    Cadena referencia_, titulo_;
    Fecha f_publi_;
    double precio_;
    Autores autor_;
};

std::ostream &operator<<(std::ostream &, const Articulo &);

class ArticuloAlmacenable : public Articulo
{
public:
    ArticuloAlmacenable(Autores, const Cadena &, const Cadena &, const Fecha &, double, unsigned stock = 0);
    unsigned stock() const { return stock_; }
    unsigned &stock() { return stock_; }

protected:
    unsigned stock_;
};

class Libro : public ArticuloAlmacenable
{
public:
    Libro(Autores, const Cadena &, const Cadena &, const Fecha &, double, int, unsigned stock = 0);
    int n_pag() const { return paginas_; }

private:
    const int paginas_;
};

class Cederron : public ArticuloAlmacenable
{
public:
    Cederron(Autores, const Cadena &, const Cadena &, const Fecha &, double, double, unsigned stock = 0);
    double tam() const { return tam_; }

private:
    const double tam_;
};

class LibroDigital : public Articulo
{
public:
    LibroDigital(Autores, const Cadena &, const Cadena &, const Fecha &, double, const Fecha &);
    const Fecha &f_expir() const { return f_; }

private:
    Fecha f_;
};

class Autores
{
public:
    Autores(const Cadena &, const Cadena &, const Cadena &);
    Cadena nombre() const;
    Cadena apellido() const;
    Cadena direccion() const;

private:
    Cadena nombre_, apellido_, direccion_;
};

#endif