/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTDESARROLLADOR_H
#define DTDESARROLLADOR_H

#include "../Model/Usuario.h"

#include <iostream>
#include <string>

using namespace std;

class DtDesarrollador : public Usuario{
	private:
		string trabajaEn;
	public:
		DtDesarrollador();
		DtDesarrollador(string,string,string);
		
		string getTrabajaEn();
		void setTrabajaEn(string trabajaEn);

		~DtDesarrollador();
};

#endif