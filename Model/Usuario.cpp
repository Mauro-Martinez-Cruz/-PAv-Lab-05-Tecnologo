/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

Usuario::Usuario(){}
Usuario::Usuario(string email,string password){
    this->email=email;
    this->password=password;
}

string Usuario::getEmail(){
    return this->email;
}

string Usuario::getPassword(){
    return this->password;
}

void Usuario::setEmail(string email){
    this->email=email;
}

void Usuario::setPassword(string password){
    this->password=password;
}
Usuario::~Usuario(){}