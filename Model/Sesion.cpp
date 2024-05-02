/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
    if (instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

Usuario* Sesion::getUsuario(){
    return this->user;
}

void Sesion::setUsuario(Usuario* user){
    this->user=user;
}

void Sesion::deletear(){
    this->user=NULL;
}