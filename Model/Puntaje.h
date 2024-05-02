/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "Jugador.h"

class Puntaje{
    private:
        int puntaje;
        Jugador* player;
    public:
        Puntaje();
		Puntaje(int,Jugador*);

        int getPuntaje();
        Jugador* getJugador();

        void setPuntaje(int puntaje);
        void setJugador(Jugador* player);

		~Puntaje();
};

#endif