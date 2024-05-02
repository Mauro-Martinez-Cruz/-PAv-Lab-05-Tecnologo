/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

class Jugador : public Usuario{
	private:
		string nickname, desc;
	public:
		Jugador();
		Jugador(string,string,string,string);
		
		string getNickname();
		string getDesc();
		void setNickname(string nickname);
		void setDesc(string password);

		friend bool operator == (const Jugador&,const Jugador&);

		~Jugador();
};

#endif