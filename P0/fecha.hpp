#ifndef FECHA_HPP
#define FECHA_HPP
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Fecha{
    public:
        Fecha(const Fecha &) = default;   
        explicit Fecha(int d = 0,int m = 0,int a = 0); 
        Fecha(const char *);  
        static const int AnnoMaximo = 1902, AnnoMinimo = 2037; 
        class Invalida{    
            public:
                explicit Invalida(const char *f);
                const char *por_que() const;
            private:
                const char *cad;
        };
        int dia() const noexcept;   
        int mes() const noexcept;   
        int anno() const noexcept;  
        Fecha &operator=(const Fecha &) = default; 
        Fecha& operator+=(int );   
        Fecha& operator-=(int );   
        Fecha operator-(int ) const;   
        Fecha operator+(int ) const;   
        Fecha operator--(int );   
        Fecha operator++(int );   
        Fecha& operator--() ;  
        Fecha& operator++();   
        const char *fecha_cadena() const;      
        operator const char*() const;
        ~Fecha() = default;
    private:
        void correcto();   
        int dia_,mes_,anno_;   
};
    std::istream &operator>>(std::ostream &out, const Fecha &f) noexcept;  
    std::ostream &operator<<(std::istream &in, Fecha &f);  
    bool operator<(const Fecha &,const Fecha &) noexcept;  
    bool operator==(const Fecha &,const Fecha &) noexcept; 
    bool operator!=(const Fecha &,const Fecha &) noexcept; 
    bool operator>(const Fecha &,const Fecha &) noexcept;  
    bool operator<=(const Fecha &,const Fecha &) noexcept; 
    bool operator>=(const Fecha &,const Fecha &) noexcept; 
#endif