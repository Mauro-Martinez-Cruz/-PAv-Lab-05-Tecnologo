/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario{
	protected:
		string email, password;
	public:
		Usuario();
		Usuario(string, string);
		
		string getEmail();
		string getPassword();
		void setEmail(string);
		void setPassword(string);

		virtual ~Usuario();
};

#endif