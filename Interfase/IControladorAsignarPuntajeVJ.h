/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORASIGNARPUNTAJEVJ_H
#define ICONTROLADORASIGNARPUNTAJEVJ_H

#include "../DataType/DtVideojuego.h"
#include <string>
#include <list>

using namespace std;

class IControladorAsignarPuntajeVJ{
    public:
        virtual bool existeVJ(string)=0;
        virtual bool existePunt(string)=0;
        virtual map<string,DtVideojuego*> listarDatosVJ()=0;
        virtual void asigPuntVideojuego1(string,int)=0;
        virtual void asigPuntVideojuego2(string,int)=0;
};

#endif