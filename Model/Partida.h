/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef PARTIDA_H
#define PARTIDA_H

#include "Jugador.h"
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class Partida{
	protected:
		tm* t;
        int duracion;
		Jugador* player;
	public:
		Partida();
		Partida(tm*,int,Jugador*);

        tm* getTime();
        int getDuracion();
		Jugador* getJugador();

        void setDuracion(int duracion);

		virtual ~Partida();
};

#endif