/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;

Jugador::Jugador(){}
Jugador::Jugador(string email,string password,string nickname,string desc){
    this->email=email;
    this->password=password;
    this->nickname=nickname;
    this->desc=desc;
}

string Jugador::getNickname(){
    return this->nickname;
}

string Jugador::getDesc(){
    return this->desc;
}

void Jugador::setNickname(string nickname){
    this->nickname=nickname;
}

void Jugador::setDesc(string desc){
    this->desc=desc;
}

bool operator == (const Jugador& player1,const Jugador& player2){
    return player1.nickname == player2.nickname;  
}
Jugador::~Jugador(){}