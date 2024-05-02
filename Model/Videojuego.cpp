/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Videojuego.h"
#include "Sesion.h"
#include <iostream>
#include <string>

Videojuego::Videojuego(){}
Videojuego::Videojuego(string nombre, string descripcion,int costoSus,int totalHP,float promPuntaje,map<DtCategoria*,Categoria*> categorias, Desarrollador* desarrollador,map<Jugador*,Puntaje*> puntuaciones){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costoSus=costoSus;
    this->totalHP=totalHP;
    this->promPuntaje=promPuntaje;
    this->categorias=categorias;
    this->desarrollador=desarrollador;
    this->puntuaciones=puntuaciones;
}

string Videojuego::getNombre(){
    return this->nombre;
}
string Videojuego::getDescripcion(){
    return this->descripcion;
}
int Videojuego::getCostoSus(){
    return this->costoSus;
}
int Videojuego::getTotalHP(){
    return this->totalHP;
}
float Videojuego::getPromPuntaje(){
    return this->promPuntaje;
}
map<Jugador*,Suscripcion*> Videojuego::getSuscripciones(){
    map<Jugador*,Suscripcion*> suscris;
    for (map<Jugador*,Suscripcion*>::iterator it=this->suscripciones.begin(); it!=this->suscripciones.end(); ++it)
        suscris.emplace(it->second->getJugador(),it->second);
    return suscris;
}
map<DtCategoria*,Categoria*> Videojuego::getCategorias(){
    map<DtCategoria*,Categoria*> cats;
    DtCategoria* dtcat;
    for (map<DtCategoria*,Categoria*>::iterator it=this->categorias.begin(); it!=this->categorias.end(); ++it){
        dtcat = new DtCategoria (it->second->getGenero(),it->second->getPlataforma());
        cats.emplace(dtcat,it->second);
    }
    return cats;
}
Desarrollador* Videojuego::getDesarrollador(){
    return this->desarrollador;
}
bool Videojuego::existeSusc(Jugador* player){
    map<Jugador*,Suscripcion*>::iterator it = this->suscripciones.find(player);
	return (it != this->suscripciones.end());
} 
bool Videojuego::existeP(Jugador* player){
    map<Jugador*,Puntaje*>::iterator it = this->puntuaciones.find(player);
	return (it != this->puntuaciones.end());
}
void Videojuego::setNombre(string nombre){
    this->nombre=nombre;
}
void Videojuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
void Videojuego::setCostoSus(int costoSus){
    this->costoSus=costoSus;
}
void Videojuego::setTotalHP(int totalHP){
    this->totalHP=this->totalHP+totalHP;
}
void Videojuego::setPromPuntaje(float promPuntaje){
    this->promPuntaje=promPuntaje;
}
list<Partida*> Videojuego::getPartidas(){
    return this->partidas;
}
void Videojuego::setPuntaje(int p){
    Sesion* inst=Sesion::getInstancia();
    Usuario* user=inst->getUsuario();
    Jugador* player=dynamic_cast<Jugador*>(user);
    map<Jugador*,Puntaje*>:: iterator it = this->puntuaciones.find(player);
    it->second->setPuntaje(p);
    int puntajeTotal=0;
    for(map<Jugador*,Puntaje*>::iterator it=this->puntuaciones.begin(); it!=puntuaciones.end(); ++it)
        puntajeTotal=puntajeTotal+it->second->getPuntaje();
    setPromPuntaje((float)puntajeTotal/(float)(this->puntuaciones.size()));
}
void Videojuego::agregarSuscripcion(Suscripcion* s){
    this->suscripciones.emplace(s->getJugador(),s);
}
void Videojuego::agregarPartida(Partida* p){
    this->partidas.emplace_back(p);
    setTotalHP(p->getDuracion());
}
void Videojuego::agregarPuntaje(Puntaje* p){
    this->puntuaciones.emplace(p->getJugador(),p);
    int puntajeTotal=0;
    for (map<Jugador*,Puntaje*>::iterator it=this->puntuaciones.begin(); it!=puntuaciones.end(); ++it)
        puntajeTotal=puntajeTotal+it->second->getPuntaje();
    setPromPuntaje((float)puntajeTotal/(float)(this->puntuaciones.size()));
}
void Videojuego::eliminarSuscripciones(){
    this->suscripciones.clear();
}
void Videojuego::eliminarPartidas(){
    this->partidas.clear();
}
void Videojuego::eliminarPuntajes(){
    this->puntuaciones.clear();
}
void Videojuego::eliminarSusc(Jugador* jugador){
    this->suscripciones.erase(jugador);
}
list<Partida*> getPartidas();
Videojuego::~Videojuego(){
    eliminarSuscripciones();
    eliminarPartidas();
    eliminarPuntajes();
}