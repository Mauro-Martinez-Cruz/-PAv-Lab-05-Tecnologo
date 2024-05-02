/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtJugador.h"
#include <iostream>
#include <string>

using namespace std;

DtJugador::DtJugador(){}
DtJugador::DtJugador(string email,string password,string nickname,string desc){
    this->email=email;
    this->password=password;
    this->nickname=nickname;
    this->desc=desc;
}

string DtJugador::getNickname(){
    return this->nickname;
}

string DtJugador::getDesc(){
    return this->desc;
}

DtJugador::~DtJugador(){}