/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Puntaje.h"

Puntaje::Puntaje(){}
Puntaje::Puntaje(int puntaje,Jugador* player){
    this->puntaje=puntaje;
    this->player=player;
}

int Puntaje::getPuntaje(){
    return puntaje;
}
Jugador* Puntaje::getJugador(){
    return player;
}

void Puntaje::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}
void Puntaje::setJugador(Jugador* player){
    this->player=player;
}

Puntaje::~Puntaje(){}