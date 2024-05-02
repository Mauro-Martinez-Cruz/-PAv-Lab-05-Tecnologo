/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtPartidaMultijugador.h"
#include <iostream>
#include <string>

DtPartidaMultijugador::DtPartidaMultijugador(){}
DtPartidaMultijugador::DtPartidaMultijugador(tm* timeinfo,int duracion,Jugador* player,int cantJugadores,bool transEnVivo){
    this->t=timeinfo;
    this->duracion=duracion;
    this->player=player;
    this->cantJugadores=cantJugadores;
    this->transEnVivo=transEnVivo;
}

int DtPartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;
}
bool DtPartidaMultijugador::getTransEnVivo(){
    return this->transEnVivo;
}

ostream& operator << (ostream& salida, DtPartidaMultijugador& dtpartidaM){
	if(dtpartidaM.transEnVivo){
		cout << (DtPartida) dtpartidaM;
        cout << "Cant. Jugadores: " << dtpartidaM.cantJugadores << endl;
        cout << "Partida Transmitido En Vivo" << endl;
    }else{
		cout << (DtPartida) dtpartidaM;
        cout << "Cant. Jugadores: " << dtpartidaM.cantJugadores << endl;
        cout << "Partida Sin Transmision En Vivo" << endl;
    }
	return salida;
}

DtPartidaMultijugador::~DtPartidaMultijugador(){}
