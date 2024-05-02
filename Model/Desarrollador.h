/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

class Desarrollador : public Usuario{
	private:
		string trabajaEn;
	public:
		Desarrollador();
		Desarrollador(string,string,string);
		
		string getTrabajaEn();
		void setTrabajaEn(string trabajaEn);

		friend bool operator == (const Desarrollador&,const Desarrollador&);

		~Desarrollador();
};

#endif