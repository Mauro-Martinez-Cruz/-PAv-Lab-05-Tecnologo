/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "PartidaMultijugador.h"
#include <iostream>
#include <string>

PartidaMultijugador::PartidaMultijugador(){}
PartidaMultijugador::PartidaMultijugador(tm* timeinfo,int duracion,Jugador* player,int cantJugadores,bool transEnVivo){
    this->t=timeinfo;
    this->duracion=duracion;
    this->player=player;
    this->cantJugadores=cantJugadores;
    this->transEnVivo=transEnVivo;
}

int PartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;
}
bool PartidaMultijugador::getTransEnVivo(){
    return this->transEnVivo;
}

void PartidaMultijugador::setCantJugadores(int cantJugadores){
    this->cantJugadores=cantJugadores;
}
void PartidaMultijugador::setTransEnVivo(bool transEnVivo){
    this->transEnVivo=transEnVivo;
}
PartidaMultijugador::~PartidaMultijugador(){}
