/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORCANCELARSUSCRIPCION_H
#define CONTROLADORCANCELARSUSCRIPCION_H

#include "../Interfase/IControladorCancelarSuscripcion.h"
#include <string>

class ControladorCancelarSuscripcion: public IControladorCancelarSuscripcion{
    public:
        list<DtVideojuego*> listarVjSuscActiva();
        bool existeVj(string);
        bool existeSusc(string);
    	void cancelarSuscripcion(string);
};

#endif