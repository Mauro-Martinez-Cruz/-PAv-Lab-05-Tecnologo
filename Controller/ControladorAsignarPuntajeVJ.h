/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORASIGNARPUNTAJEVJ_H
#define CONTROLADORASIGNARPUNTAJEVJ_H

#include "../Interfase/IControladorAsignarPuntajeVJ.h"
#include <string>
#include <list>

class ControladorAsignarPuntajeVJ: public IControladorAsignarPuntajeVJ{
    public:
        bool existeVJ(string);
        bool existePunt(string);
        map<string,DtVideojuego*> listarDatosVJ();
        void asigPuntVideojuego1(string,int);
        void asigPuntVideojuego2(string,int);
};

#endif