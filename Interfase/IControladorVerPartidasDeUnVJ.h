/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORVERPARTIDASDEUNVJ_H
#define ICONTROLADORVERPARTIDASDEUNVJ_H

#include <string>
#include "../DataType/DtVideojuego.h"
#include <list>
#include "../DataType/DtPartidaIndividual.h"
#include "../DataType/DtPartidaMultijugador.h"

class IControladorVerPartidasDeUnVJ{
    private:

    public:
        virtual list<DtVideojuego*> listarVJ()=0;
        virtual bool existeVJ(string)=0;
        virtual list<DtPartidaIndividual*> verPartidasVjI(string)=0;
        virtual list<DtPartidaMultijugador*> verPartidasVjM(string)=0;
};

#endif
