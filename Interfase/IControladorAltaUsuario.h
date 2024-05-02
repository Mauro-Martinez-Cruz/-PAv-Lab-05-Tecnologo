/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORALTAUSUARIO_H
#define ICONTROLADORALTAUSUARIO_H

#include <string>

using namespace std;

class IControladorAltaUsuario{
    public:
        virtual void setTipoDeUsuario(string)=0;
        virtual bool existeEmailC(string)=0;
        virtual void datosComunes(string,string)=0;
        virtual void datosEmpresa(string)=0;
        virtual bool datosJugadorN(string)=0;
        virtual void datosJugadorD(string)=0;
        virtual void altaUsuario()=0;
        virtual void cancelar()=0;
};
#endif