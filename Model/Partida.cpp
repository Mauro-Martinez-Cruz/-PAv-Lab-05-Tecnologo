/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Partida.h"
#include <iostream>
#include <string>

Partida::Partida(){}
Partida::Partida(tm* timeinfo,int duracion,Jugador* player){
    this->t=timeinfo;
    this->duracion=duracion;
    this->player=player;
}

tm* Partida::getTime(){
    return this->t;
}

int Partida::getDuracion(){
    return this->duracion;
}

Jugador* Partida::getJugador(){
    return this->player;
}

void Partida::setDuracion(int duracion){
    this->duracion=duracion;
}

Partida::~Partida(){}

