/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORSUSCVIDEOJUEGO_H
#define ICONTROLADORSUSCVIDEOJUEGO_H

#include "../Model/TipoDePago.h"
#include "../DataType/DtVideojuego.h"
#include <string>
#include <list>

using namespace std;

class IControladorSuscVideojuego{
    public:
        virtual list<DtVideojuego*> listarVjSuscActiva()=0;
        virtual list<DtVideojuego*> listarVjSuscNoActiva()=0;
        virtual bool existeVj(string)=0;
        virtual bool buscarSusVideoJuego(string)=0;
        virtual void datosCompra(TipoDePago)=0;
        virtual void suscVideojuego()=0;
        virtual void cancelar()=0;
};

#endif