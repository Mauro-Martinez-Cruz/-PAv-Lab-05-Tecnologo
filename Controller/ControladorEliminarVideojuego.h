/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORELIMINARVIDEOJUEGO_H
#define CONTROLADORELIMINARVIDEOJUEGO_H

#include "../Interfase/IControladorEliminarVideojuego.h"
#include <list>

class ControladorEliminarVideojuego: public IControladorEliminarVideojuego{
    private:
        string videojuego;
    public:
        list<string> listarNombreVj();
        bool existeVJ(string);
        void seleccionarVideojuego(string);
        void eliminarVideojuego();
        void cancelar();
};

#endif 
