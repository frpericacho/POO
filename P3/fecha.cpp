#include <iostream>
#include <cstring>
#include <ctime>
#include "fecha.hpp"
#define BISIESTO (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0)) && mes_ == 2

Fecha::Fecha(const char *f) : dia_(0), mes_(0), anno_(0)
{
    time_t tiempo_calendario = time(nullptr);
    tm *tiempo_descompuesto = localtime(&tiempo_calendario);

    if ((sscanf(f, "%d/%d/%d", &dia_, &mes_, &anno_)) != 3)
        throw Invalida("error en la fecha");

    if (dia_ == 0)
        dia_ = tiempo_descompuesto->tm_mday;
    if (Fecha::mes_ == 0)
        mes_ = tiempo_descompuesto->tm_mon + 1;
    if (Fecha::anno_ == 0)
        anno_ = tiempo_descompuesto->tm_year + 1900;

    correcto();
}

Fecha::Fecha(int d, int m, int a) : dia_(d), mes_(m), anno_(a)
{
    time_t tiempo_calendario = time(nullptr);
    tm *tiempo_descompuesto = localtime(&tiempo_calendario);
    if (d == 0)
        dia_ = tiempo_descompuesto->tm_mday;
    if (m == 0)
        mes_ = tiempo_descompuesto->tm_mon + 1;
    if (a == 0)
        anno_ = tiempo_descompuesto->tm_year + 1900;

    correcto();
}

void Fecha::correcto() const
{
    if (anno_ < Fecha::AnnoMinimo || anno_ > Fecha::AnnoMaximo)
    {
        throw Invalida("error por el año");
    }
    if (mes_ < 1 || mes_ > 12)
    {
        throw Invalida("error por el mes");
    }

    static const int DiaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dia_ < 1 || dia_ > (DiaMes[mes_] + static_cast<int>(BISIESTO)))
        throw Invalida("Dia Incorrecto");
}

Fecha &Fecha::operator+=(int n)
{
    if (n != 0)
    {
        std::tm *time_tm = new std::tm{
            0, 0, 0, (dia_ + n), (mes_ - 1), (anno_ - 1900), 0, 0, 0, 0, 0};

        std::mktime(time_tm);

        dia_ = time_tm->tm_mday;
        mes_ = time_tm->tm_mon + 1;
        anno_ = time_tm->tm_year + 1900;

        correcto();
    }

    return *this;
}

int Fecha::dia() const noexcept
{
    return dia_;
}

int Fecha::mes() const noexcept
{
    return mes_;
}

int Fecha::anno() const noexcept
{
    return anno_;
}

Fecha &Fecha::operator-=(int n)
{
    return *this += (-n);
}

Fecha Fecha::operator-(int n) const
{
    return Fecha(*this) += (-n);
}

Fecha Fecha::operator+(int n) const
{
    return Fecha(*this) += n;
}

Fecha &Fecha::operator--()
{
    return *this -= 1;
}

Fecha &Fecha::operator++()
{
    return *this += 1;
}

Fecha Fecha::operator--(int)
{
    Fecha tmp = *this;
    *this -= 1;
    return tmp;
}

Fecha Fecha::operator++(int)
{
    Fecha tmp = *this;
    *this += 1;
    return tmp;
}

bool operator==(const Fecha &f1, const Fecha &f2) noexcept
{
    if (f1.dia() == f2.dia() && f1.mes() == f2.mes() && f1.anno() == f2.anno())
        return true;
    else
        return false;
}

bool operator<(const Fecha &f1, const Fecha &f2) noexcept
{
    if (f1.anno() < f2.anno())
        return true;
    if (f1.anno() == f2.anno() && f1.mes() < f2.mes())
        return true;
    if (f1.anno() == f2.anno() && f1.mes() == f2.mes() && f1.dia() < f2.dia())
        return true;
    else
        return false;
}

bool operator!=(const Fecha &f1, const Fecha &f2) noexcept
{
    return !(f1 == f2);
}

bool operator>(const Fecha &f1, const Fecha &f2) noexcept
{
    return f2 < f1;
}

bool operator<=(const Fecha &f1, const Fecha &f2) noexcept
{ //mal
    return !(f2 < f1);
}

bool operator>=(const Fecha &f1, const Fecha &f2) noexcept
{ //mal
    return !(f1 < f2);
}

/*Fecha::operator const char*() const{
    char* s = new char[40];
    setlocale(LC_TIME, "");
    tm f = {};
    f.tm_mday = dia_;
    f.tm_mon = mes_ - 1;
    f.tm_year = anno_ - 1900;
    mktime(&f);
    strftime(s, 40, "%A %d de %B de %Y", &f);
    return s;
}*/

const char *Fecha::cadena() const
{
    char *s = new char[40];
    setlocale(LC_TIME, "");
    tm f = {};
    f.tm_mday = dia_;
    f.tm_mon = mes_ - 1;
    f.tm_year = anno_ - 1900;
    mktime(&f);
    strftime(s, 40, "%A %d de %B de %Y", &f);
    return s;
}

std::ostream &operator<<(ostream &out, const Fecha &f)
{
    out << f.cadena();
    return out;
}

std::istream &operator>>(istream &in, Fecha &f)
{
    char aux[11];
    in.getline(aux,11);
    try
    {
        f = Fecha(aux);
    }
    catch(const Fecha::Invalida &e)
    {
        in.setstate(std::ios_base::failbit);
        throw;
    }
    return in;
}