/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

#include "Jugador.h"
#include "TipoDePago.h"

class Suscripcion{
    private:
        tm* timeinfo;
        TipoDePago tipoPago;
        int costo;
        Jugador* player;
    public:
        Suscripcion();
		Suscripcion(TipoDePago,int,Jugador*);

        tm* getTime();
        TipoDePago getTipoDePago();
        int getCosto();
        Jugador* getJugador();

        void setTipoDePago(TipoDePago tipoPago);
        void setCosto(int costo);
        void setJugador(Jugador* player);

		~Suscripcion();
};

#endif