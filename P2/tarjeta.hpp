#ifndef TARJETA_HPP
#define TARJETA_HPP
#include <iostream>
#include "cadena.hpp"
#include "usuario.hpp"
#include "fecha.hpp"

class Numero
{
public:
    Numero(const Cadena &cad);
    operator const char *() const;
    enum Razon
    {
        LONGITUD,
        DIGITOS,
        NO_VALIDO
    };
    friend bool operator<(const Numero &A, const Numero &B);

    class Incorrecto
    {
    public:
        Incorrecto(Razon r) : r_(r) {}
        const Razon &razon() const { return r_; }

    private:
        Razon r_;
    };

private:
    Cadena cad_;
};

class Tarjeta
{
public:
    Tarjeta(Numero, Usuario &, Fecha);
    Tarjeta(const Tarjeta &) = delete;
    Tarjeta &operator=(const Tarjeta &) = delete;

    enum Tipo
    {
        Otro,
        VISA,
        Mastercard,
        Maestro,
        JCB,
        AmericanExpress
    };

    class Caducada
    {
    public:
        Caducada(const Fecha &f) : f_(f) {}
        Fecha cuando() const { return f_; }
    private:
        Fecha f_;
    };

    class Num_duplicado{
        public:
            Num_duplicado(const Numero &num):n_(num){}
            Numero duplicado() const { return n_; }
        private:
            Numero n_;
    };

    Tipo tipo() const;
    Numero numero() const;
    const Usuario *titular() const;
    Fecha caducidad() const;
    bool activa() const;

    bool activa(bool = true);
    void anula_titular();

    ~Tarjeta();
private:
    Tipo t_;
    Numero num_;
    const Usuario *user_;
    Fecha caducidad_;
    bool estado_;
};

#endif