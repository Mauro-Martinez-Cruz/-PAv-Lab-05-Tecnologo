/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef PARTIDAMULTIJUGADOR_H
#define PARTIDAMULTIJUGADOR_H
#include "Partida.h"
#include <iostream>
#include <string>

using namespace std;

class PartidaMultijugador : public Partida{
	protected:
		int cantJugadores;
        bool transEnVivo;
	public:
		PartidaMultijugador();
		PartidaMultijugador(tm*,int,Jugador*,int,bool);

        int getCantJugadores();
        bool getTransEnVivo();

        void setCantJugadores(int cantJugadores);
        void setTransEnVivo(bool transEnVivo);

		virtual ~PartidaMultijugador();
};

#endif