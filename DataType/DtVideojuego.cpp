/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtVideojuego.h"
#include <iostream>
#include <string>

DtVideojuego::DtVideojuego(){}
DtVideojuego::DtVideojuego(string nombre, string descripcion,int costoSus,int totalHP,float promPuntaje,map<DtCategoria*,Categoria*> categorias,Desarrollador* desarrollador){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costoSus=costoSus;
    this->totalHP=totalHP;
    this->promPuntaje=promPuntaje;
    this->categorias=categorias;
    this->desarrollador=desarrollador;
}

string DtVideojuego::getNombre(){
    return this->nombre;
}
string DtVideojuego::getDescripcion(){
    return this->descripcion;
}
int DtVideojuego::getCostoSus(){
    return this->costoSus;
}
int DtVideojuego::getTotalHP(){
    return this->totalHP;
}
float DtVideojuego::getPromPuntaje(){
    return this->promPuntaje;
}
Desarrollador* DtVideojuego::getDesarrollador(){
    return this->desarrollador;
}
map<DtCategoria*,Categoria*> DtVideojuego::getCategorias(){
    map<DtCategoria*,Categoria*> cats;
    DtCategoria* dtcat;
    for (map<DtCategoria*,Categoria*>::iterator it=this->categorias.begin(); it!=this->categorias.end(); ++it){
        dtcat = new DtCategoria (it->second->getGenero(),it->second->getPlataforma());
        cats.emplace(dtcat,it->second);
    }
    return cats;
}

DtVideojuego::~DtVideojuego(){}