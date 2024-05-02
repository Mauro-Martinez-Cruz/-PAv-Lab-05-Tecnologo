/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include <string>

using namespace std;

class DtUsuario{
	protected:
		string email, password;
	public:
		DtUsuario();
		DtUsuario(string, string);
		
		string getEmail();
		string getPassword();

		virtual ~DtUsuario();
};

#endif