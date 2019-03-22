#ifndef FECHA_HPP
#define FECHA_HPP
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Fecha{
    public:
        Fecha(const Fecha& f) = default;
        explicit Fecha(int d = 0,int m = 0,int a = 0);
        Fecha(const char* f);
        static const int AnnoMaximo = 1902, AnnoMinimo = 2037;
        class Invalida{
            public:
                Invalida(const char* f);
                const char* por_que(const char* f);
            private:
                const char* cad;
        };
        int dia() const;
        int mes() const;
        int anno() const;
        operator const char*() const;
        Fecha &operator=(const Fecha &) = default;
        Fecha& operator+=(int );
        Fecha& operator-=(int );
        Fecha operator-(int ) const;
        Fecha operator+(int ) const;
        Fecha& operator--(int );
        Fecha& operator++(int );
        Fecha& operator--() ;
        Fecha& operator++();
        const char *fecha_cadena(Fecha );

    private:
        void correcto();
        int dia_,mes_,anno_;
};

    bool operator<(const Fecha &,const Fecha &) noexcept;
    bool operator==(const Fecha &,const Fecha &) noexcept;
    bool operator!=(const Fecha &,const Fecha &) noexcept;
    bool operator>(const Fecha &,const Fecha &) noexcept;
    bool operator<=(const Fecha &,const Fecha &) noexcept;
    bool operator>=(const Fecha &,const Fecha &) noexcept;
#endif