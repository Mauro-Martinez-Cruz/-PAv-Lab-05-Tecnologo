/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORINICIARPARTIDA_H
#define ICONTROLADORINICIARPARTIDA_H

#include "../DataType/DtVideojuego.h"
#include <string>

using namespace std;

class IControladorIniciarPartida{
    public:
        virtual list<DtVideojuego*> listarVjSuscActiva()=0;
        virtual bool existeVJ(string)=0;
        virtual void cualVideojuego(string)=0;
        virtual void datosPartidaI(bool)=0;
        virtual void datosPartidaM(bool, int)=0;
        virtual void datosPartida(int)=0;
        virtual void setTipoPartida(string)=0;
        virtual void iniciarPartida()=0;
        virtual void cancelar()=0;
};

#endif