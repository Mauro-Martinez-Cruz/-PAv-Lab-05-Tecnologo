/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTJUGADOR_H
#define DTJUGADOR_H

#include "../Model/Usuario.h"

#include <iostream>
#include <string>

using namespace std;

class DtJugador : public Usuario{
	private:
		string nickname, desc;
	public:
		DtJugador();
		DtJugador(string, string, string, string);
		
		string getNickname();
		string getDesc();

		~DtJugador();
};

#endif