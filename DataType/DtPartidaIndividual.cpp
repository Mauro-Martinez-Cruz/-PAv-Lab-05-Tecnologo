/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtPartidaIndividual.h"
#include <iostream>
#include <string>

DtPartidaIndividual::DtPartidaIndividual(){}
DtPartidaIndividual::DtPartidaIndividual(tm* timeinfo,int duracion,Jugador* player,bool contiParAnt){
    this->t=timeinfo;
	this->duracion=duracion;
	this->player=player;
    this->contiParAnt=contiParAnt;
}
bool DtPartidaIndividual::getContiParAnt(){
    return this->contiParAnt;
}

ostream& operator << (ostream& salida, DtPartidaIndividual& dtpartidaI){
	if(dtpartidaI.contiParAnt){
		cout << (DtPartida) dtpartidaI;
		cout << "Partida Continuada" << endl;
	}else{
		cout << (DtPartida) dtpartidaI;
		cout << "Partida NO Continuada" << endl;
	}
	return salida;
}
DtPartidaIndividual::~DtPartidaIndividual(){}