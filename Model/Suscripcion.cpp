/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Suscripcion.h"
#include <iostream>

using namespace std;

Suscripcion::Suscripcion(){}
Suscripcion::Suscripcion(TipoDePago tipoPago,int costo,Jugador* player){
    time_t rawtime;
    tm* timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    this->timeinfo=timeinfo;
    this->tipoPago=tipoPago;
    this->costo=costo;
    this->player=player;
}

tm* Suscripcion::getTime(){
    return this->timeinfo;
}
TipoDePago Suscripcion::getTipoDePago(){
    return this->tipoPago;
}
int Suscripcion::getCosto(){
    return this->costo;
}
Jugador* Suscripcion::getJugador(){
    return this->player;
}
void Suscripcion::setTipoDePago(TipoDePago tipoPago){
    this->tipoPago=tipoPago;
}
void Suscripcion::setCosto(int costo){
    this->costo=costo;
}
void Suscripcion::setJugador(Jugador* player){
    this->player=player;
}

Suscripcion::~Suscripcion(){}