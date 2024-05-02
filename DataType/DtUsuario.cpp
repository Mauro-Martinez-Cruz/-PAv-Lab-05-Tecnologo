/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtUsuario.h"
#include <iostream>
#include <string>

using namespace std;

DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(string email,string password){
    this->email=email;
    this->password=password;
}

string DtUsuario::getEmail(){
    return this->email;
}

string DtUsuario::getPassword(){
    return this->password;
}

DtUsuario::~DtUsuario(){}