#include <iostream>
#include <cstring>
#include "tarjeta.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include "usuario.hpp"

bool luhn(const Cadena &cad);

bool operator<(const Numero &A, const Numero &B)
{
    return strcmp(A, B) < 0;
}

Numero::operator const char *() const
{
    return cad_.c_str();
}

Numero::Numero(const Cadena &cad)
{
    Cadena aux(cad);
    //quitar espacios
    std::remove_if(aux.begin(), aux.end() + 1, [](char c) { return isspace(c); });
    //mirar tamaño
    if (aux.length() < 13 || aux.length() > 19 || aux.length() == 0)
        throw Incorrecto(Razon::LONGITUD);

    cad_ = aux;

    if (std::count_if(cad_.begin(), cad_.end(), static_cast<int (*)(int)>(std::isdigit)) != cad_.length())
        throw Incorrecto(Razon::DIGITOS);
    if (!luhn(cad_))
        throw Incorrecto(Razon::NO_VALIDO);
}

Tarjeta::Tarjeta(Numero num,Usuario &user, Fecha f): num_(num), user_(&user), caducidad_(f), estado_(true)
{
    if (Fecha() > caducidad_)
        throw Caducada(caducidad_);
    user.es_titular_de(*this);
    switch (num[0])
    {
    case '3':
        switch (num[1])
        {
        case '4':
        case '7':
            t_ = JCB;
            break;
        default:
            t_ = AmericanExpress;
            break;
        }
        break;
    case '4':
        t_ = VISA;
        break;
    case '5':
        t_ = Mastercard;
        break;
    case '6': t_ = Maestro;
        break;
        default:
        t_ = Otro;
        break;
    }

}