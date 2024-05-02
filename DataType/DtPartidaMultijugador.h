/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTPARTIDAMULTIJUGADOR_H
#define DTPARTIDAMULTIJUGADOR_H

#include "DtPartida.h"
#include <iostream>
#include <string>

using namespace std;

class DtPartidaMultijugador : public DtPartida{
	protected:
		int cantJugadores;
        bool transEnVivo;
	public:
		DtPartidaMultijugador();
		DtPartidaMultijugador(tm*,int,Jugador*,int,bool);

        int getCantJugadores();
        bool getTransEnVivo();

		friend ostream& operator << (ostream&, DtPartidaMultijugador&);

		virtual ~DtPartidaMultijugador();
};

#endif