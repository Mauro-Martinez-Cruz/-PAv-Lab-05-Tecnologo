/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTPARTIDAINDIVIDUAL_H
#define DTPARTIDAINDIVIDUAL_H

#include "DtPartida.h"
#include <iostream>
#include <string>

using namespace std;

class DtPartidaIndividual : public DtPartida{
	protected:
		bool contiParAnt;
	public:
		DtPartidaIndividual();
		DtPartidaIndividual(tm*,int,Jugador*,bool);

        bool getContiParAnt();

		virtual ~DtPartidaIndividual();

		friend ostream& operator << (ostream&, DtPartidaIndividual&);
};

#endif