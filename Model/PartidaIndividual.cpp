/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "PartidaIndividual.h"
#include <iostream>
#include <string>

PartidaIndividual::PartidaIndividual(){}
PartidaIndividual::PartidaIndividual(tm* timeinfo,int duracion,Jugador* player,bool contiParAnt){
    this->t=timeinfo;
    this->duracion=duracion;
    this->player=player;
    this->contiParAnt=contiParAnt;
}
bool PartidaIndividual::getContiParAnt(){
    return this->contiParAnt;
}
void PartidaIndividual::setContiParAnt(bool contiParAnt){
    this->contiParAnt=contiParAnt;
}
PartidaIndividual::~PartidaIndividual(){}