/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTPARTIDA_H
#define DTPARTIDA_H

#include <time.h>
#include <iostream>
#include <string>
#include "../Model/Jugador.h"

using namespace std;

class DtPartida{
	protected:
		tm* t;
        int duracion;
		Jugador* player;
	public:
		DtPartida();
		DtPartida(tm*,int,Jugador*);

		tm* getTime();
        int getDuracion();
		Jugador* getJugador();

		virtual ~DtPartida();

		friend ostream& operator << (ostream&, const DtPartida&);
};

#endif