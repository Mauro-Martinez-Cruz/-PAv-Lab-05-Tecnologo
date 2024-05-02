/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef PARTIDAINDIVIDUAL_H
#define PARTIDAINDIVIDUAL_H
#include "Partida.h"
#include <iostream>
#include <string>

using namespace std;

class PartidaIndividual : public Partida{
	protected:
		bool contiParAnt;
	public:
		PartidaIndividual();
		PartidaIndividual(tm*,int,Jugador*,bool);

        bool getContiParAnt();
        void setContiParAnt(bool contiParAnt);

		virtual ~PartidaIndividual();
};

#endif