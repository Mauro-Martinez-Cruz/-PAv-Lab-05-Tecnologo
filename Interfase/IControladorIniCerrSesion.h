/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORINICERRSESION_H
#define ICONTROLADORINICERRSESION_H

#include <string>

using namespace std;

class IControladorIniCerrSesion{
    public:
        virtual bool existeUsus()=0;
        virtual bool existeEmail(string)=0;
        virtual bool ingData(string,string)=0;
        virtual void cancelar()=0;
        virtual void cerrarSesion()=0;
        virtual string queEs()=0;
};

#endif