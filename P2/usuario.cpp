#include <iostream>
#include "usuario.hpp"
#include "cadena.hpp"
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <crypt.h>
#include <iomanip>

Clave::Clave(const char *cad)
{
    if (strlen(cad) < 5)
        Incorrecta(Clave::CORTA);
    const char *c = "abcdefg";
    char salt[2];
    salt[0] = c[rand() % 7];
    salt[1] = c[rand() % 7];
    if (crypt(cad, salt) == nullptr)
        throw Incorrecta(Clave::ERROR_CRYPT);
    clave_ = crypt(cad, salt);
}

const Cadena &Clave::clave() const
{
    return clave_;
}

bool Clave::verifica(const char *cad) const
{
    return clave_ == crypt(cad, clave_.c_str());
}

Usuario::Usuario(const Cadena &id, const Cadena &nomb, const Cadena &apell, const Cadena &dir, const Clave &clv) : identificador_(id), nombre_(nomb), apellidos_(apell), direccion_(dir), clave_(clv)
{
    if (!user_.insert(id).second)
        throw Id_duplicado(identificador_);
}

void Usuario::es_titular_de(Tarjeta &t)
{
    if (this == t.titular())
    {
        t_.insert(std::make_pair(t.numero(), &t));
    }
}

void Usuario::no_es_titular_de(Tarjeta &t)
{
    t.anula_titular();
    t_.erase(t.numero());
}

void Usuario::compra(Articulo &art, unsigned cant)
{
    if (cant == 0)
        art_.erase(&art);
    else
        art_[&art] = cant;
}

Cadena Usuario::id() const
{
    return identificador_;
}

Cadena Usuario::nombre() const
{
    return nombre_;
}

Cadena Usuario::apellidos() const
{
    return apellidos_;
}

Cadena Usuario::direccion() const
{
    return direccion_;
}

size_t Usuario::n_articulos() const
{
}

Usuario::~Usuario()
{
    for (auto i = t_.begin; i != t_.end(); i++)
    {
        i->second->anula_titular();
    }
    user_.erase(identificador_);
}

std::ostream &operator<<(std::ostream &os, const Usuario &user)
{
    os << user.identificador_ << "[" << user.clave_.clave().c_str() << "]" << user.nombre_ << user.apellidos_ << "\n"
       << user.direccion_ << std::endl;
    os << "Tarjetas:";
    for (auto i = user.tarjetas().begin(); i != user.tarjetas().end(); i++)
    {
        os << *i->second << std::endl;
    }

    return os;
}

std::ostream &mostrar_carro(std::ostream &os, const Usuario &user)
{
    os << "Carrito de compra de " << user.id() << "[Articulos: " << user.n_articulos() << "]"
       << "\n"
       << "Cant.Articulo" << std::endl
       << std::setw(95) << std::setfill('=') << "\n"
       << std::setfill(' ');

    int cant = user.n_articulos();

    while (cant > 0)
    {
        for (auto i = user.compra().begin(); i != user.compra().end(); i++)
        {
            os << std::setw(4) << i->second << "    "
               << " [" << (*i->first).referencia() << "] "
               << "\""
               << (*i->first).titulo() << "\", " << (*i->first).f_publi().anno()
               << ". " << std::fixed << std::setprecision(2) << (*i->first).precio() << " €" << std::endl;
            --cant;
        }
    }
    return os;
}

/*
ostream &mostrar_carro(ostream &os, const Usuario &user)
{
    os << "Carritodecomprade" << user.id() << "[Artículos:" << user.n_articulos() << "]" << endl;
    os << "Cant.Artículo" << endl;
    os << "==================================================" << endl;
    Usuario::Articulos::const_iterator iter = user.compra().begin();
    while (iter != user.compra().end())
    {
        os << "" << iter->second << "" << *iter->first << endl;
        iter++;
    }
    return os;
}*/
