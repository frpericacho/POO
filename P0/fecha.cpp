#include <iostream>
#include <cstring>
#include <ctime>
#include "fecha.hpp"

Fecha::Fecha(const char* f)
{   
    time_t tiempo_calendario = time(nullptr);
    tm *tiempo_descompuesto = localtime(&tiempo_calendario);                                                
    
    sscanf(f,"%d/%d/%d", &dia_,&mes_,&anno_);
    
    if(dia_ == 0)
        dia_ = tiempo_descompuesto->tm_mday;
    if(Fecha::mes_ == 0)
        mes_ = tiempo_descompuesto->tm_mon + 1;
    if(Fecha::anno_ == 0)
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

void Fecha::correcto(){
    int DIA_S[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(anno_ < AnnoMinimo || anno_ > AnnoMaximo){
        throw Invalida("error por el año");
    }
    if(mes_ <= 0 || mes_ >= 13){
        throw Invalida("error por el mes");
    }
    if(anno_ % 4 == 0 && (anno_ % 100 != 0 || anno_ % 400 == 0)){
        if(dia_ <= 0 || dia_ >= 30 ){
            throw Invalida("error por el dia");
        }
    }else{
        if(dia_ <= 0 || dia_ >= DIA_S[mes_]){
            throw Invalida("error por el dia");
        }
    }
}

Fecha::Invalida::Invalida(const char *f):cad(f){}

const char *Fecha::Invalida::por_que() const{
    return cad;
}

Fecha& Fecha::operator+=(int n){
    if(n!=0){
        std::tm *time_tm = new std::tm{
            .tm_mday = (dia_ + n), .tm_mon = (mes_ -1), .tm_year = (anno_ - 1900)
        };
        
        dia_ = time_tm->tm_mday;
        mes_ = time_tm->tm_mon;
        anno_ = time_tm->tm_year;

        correcto();
    }

    return *this;
}

int Fecha::dia() const noexcept{
    return dia_;
}

int Fecha::mes() const noexcept{
    return mes_;
}

int Fecha::anno() const noexcept{
    return anno_;
}

Fecha& Fecha::operator-=(int n){
    return *this += (-n);
}

Fecha Fecha::operator-(int n) const{
    return Fecha(*this) += (-n);
}

Fecha Fecha::operator+(int n) const{
    return Fecha(*this) += n;
}

Fecha& Fecha::operator--(){
    return *this -= 1;
}

Fecha& Fecha::operator++(){
    return *this += 1;
}

Fecha& Fecha::operator--(int) {
    Fecha tmp = *this;
    *this -= 1;
    return tmp;
}

Fecha& Fecha::operator++(int) {
    Fecha tmp = *this;
    *this += 1;
    return tmp;
}

std::ostream &operator<<(std::ostream &out, const Fecha &f) noexcept{
    out << f.fecha_cadena();
    return out;
}

bool operator==(const Fecha &f1, const Fecha &f2) noexcept{
    if(f1.dia() == f2.dia() && f1.mes() == f2.mes() && f1.anno() == f2.anno())
        return true;
    else
        return false;
}

bool operator<(const Fecha &f1, const Fecha &f2) noexcept{
    if(f1.anno() < f2.anno())
        return true;
    if(f1.anno() == f2.anno() && f1.mes() < f2.mes())
        return true;
    if(f1.anno() == f2.anno() && f1.mes() == f2.mes() && f1.dia() < f2.dia())
        return true;
    else 
        return false;
}

bool operator!=(const Fecha &f1, const Fecha &f2) noexcept{
    return !(f1 == f2);
}

bool operator>(const Fecha &f1, const Fecha &f2) noexcept{
    return f2 < f1;
}

bool operator<=(const Fecha &f1, const Fecha &f2) noexcept{
    return !(f1 < f2);
}

bool operator>=(const Fecha &f1, const Fecha &f2) noexcept{
    return !(f2 < f1);
}

const char *Fecha::fecha_cadena() const{
    struct tm * timeinfo{0};
    timeinfo->tm_year = this->anno() - 1900;
    timeinfo->tm_mon = this->mes() - 1;
    timeinfo->tm_mday = this->dia();

    std::setlocale(LC_TIME, "es_ES.UTF-8");
    
    mktime(timeinfo);
    char cadena[40];

    std::strftime(cadena, 40, "%A %d de %B de %Y",timeinfo); // ES CORRECTA?
    
    return cadena;
}

Fecha::operator const char*() const{
    return fecha_cadena();
}
