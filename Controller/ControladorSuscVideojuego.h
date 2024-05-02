/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORSUSCVIDEOJUEGO_H
#define CONTROLADORSUSCVIDEOJUEGO_H

#include "../Interfase/IControladorSuscVideojuego.h"
#include <string>
#include <list>
#include "../DataType/DtVideojuego.h"

class ControladorSuscVideojuego: public IControladorSuscVideojuego{
    private:
        TipoDePago metodoDePago;
        string videojuego;
    public:
        list<DtVideojuego*> listarVjSuscActiva();
        list<DtVideojuego*> listarVjSuscNoActiva();
        bool existeVj(string);
        bool buscarSusVideoJuego(string);
        void datosCompra(TipoDePago);
        void suscVideojuego();
        void setVj(string);
        void cancelar();
};

#endif