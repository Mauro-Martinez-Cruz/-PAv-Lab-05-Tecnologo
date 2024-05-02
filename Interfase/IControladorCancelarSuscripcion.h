/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORCANCELARSUSCRIPCION_H
#define ICONTROLADORCANCELARSUSCRIPCION_H

#include <string>
#include <list>
#include "../DataType/DtVideojuego.h"

using namespace std;

class IControladorCancelarSuscripcion{
    public:
        virtual list<DtVideojuego*> listarVjSuscActiva()=0;
        virtual bool existeVj(string)=0;
        virtual bool existeSusc(string)=0;
    	virtual void cancelarSuscripcion(string)=0;
};

#endif