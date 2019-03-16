#ifndef FECHA_HPP
#define FECHA_HPP
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Fecha{
    public:
        Fecha(){}
        Fecha(const Fecha& f);
        Fecha(int d = 0,int m = 0,int a = 0);
        Fecha(const char* f);
        const int AnnoMaximo = 1902, AnnoMinimo = 2037;
        class Invalida{
            public:
                Invalida(const char* f);
                const char* por_que(const char* f);
            private:
                const char* cad;
        };
        int dia();
        int mes();
        int anno();
        void operator=(Fecha) const;
        Fecha& operator+=(int );
        Fecha& operator-=(int );
        Fecha operator-(int ) const;
        Fecha operator+(int ) const;
        Fecha& operator--(int );
        Fecha& operator++(int );
        Fecha& operator--() ;
        Fecha& operator++();
        bool operator<(Fecha ) const;
        bool operator==(Fecha ) const;
        bool operator!=(Fecha ) const;
        bool operator>(Fecha ) const;
        bool operator<=(Fecha ) const;
        bool operator>=(Fecha ) const;

    private:
        void correcto();
        int dia_,mes_,anno_;
};

#endif