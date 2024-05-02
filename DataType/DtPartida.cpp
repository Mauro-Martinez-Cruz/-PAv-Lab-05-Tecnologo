/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtPartida.h"
#include <iostream>
#include <string>

DtPartida::DtPartida(){}
DtPartida::DtPartida(tm* timeinfo,int duracion,Jugador* player){
    this->t=timeinfo;
    this->duracion=duracion;
    this->player=player;
};

tm* DtPartida::getTime(){
    return this->t;
}

int DtPartida::getDuracion(){
    return this->duracion;
}

Jugador* DtPartida::getJugador(){
    return this->player;
}

ostream& operator << (ostream& salida, const DtPartida& dtpartida){
    cout << "Partida del Jugador: " << dtpartida.player->getNickname() << endl;
	cout << "Fecha de Creación: " << asctime(dtpartida.t);
    cout << "Duración: " << dtpartida.duracion << endl;
	return salida;
}

DtPartida::~DtPartida(){}
