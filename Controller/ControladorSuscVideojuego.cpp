/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorSuscVideojuego.h"
#include "../Model/ManejadorVD.h"
#include "../Model/Sesion.h"
#include "../Model/Suscripcion.h"
#include <iostream>

using namespace std;

list<DtVideojuego*> ControladorSuscVideojuego::listarVjSuscActiva(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    ManejadorVD* inst = ManejadorVD::getInstancia();
    map<string,Videojuego*> videojuegos= inst->getVideojuegos();
    list<DtVideojuego*> listVideojuegos;
    Jugador* player=dynamic_cast<Jugador*>(user);
    for(map<string,Videojuego*>::iterator it=videojuegos.begin(); it!=videojuegos.end(); ++it){
        map<Jugador*,Suscripcion*> suscripciones= it->second->getSuscripciones();
        if(it->second->existeSusc(player)==true){
            DtVideojuego* dtVj= new DtVideojuego(it->second->getNombre(),it->second->getDescripcion(),it->second->getCostoSus(),it->second->getTotalHP(),it->second->getPromPuntaje(),it->second->getCategorias(),it->second->getDesarrollador());
            listVideojuegos.push_back(dtVj);
        }
    }
   return listVideojuegos;
}
list<DtVideojuego*> ControladorSuscVideojuego::listarVjSuscNoActiva(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    ManejadorVD* inst = ManejadorVD::getInstancia();
    map<string,Videojuego*> videojuegos= inst->getVideojuegos();
    list<DtVideojuego*> listVideojuegos;
    Jugador* player=dynamic_cast<Jugador*>(user);
    for(map<string,Videojuego*>::iterator it=videojuegos.begin(); it!=videojuegos.end(); ++it){
        map<Jugador*,Suscripcion*> suscripciones= it->second->getSuscripciones();
        if(it->second->existeSusc(player)==false){
            DtVideojuego* dtVj= new DtVideojuego(it->second->getNombre(),it->second->getDescripcion(),it->second->getCostoSus(),it->second->getTotalHP(),it->second->getPromPuntaje(),it->second->getCategorias(),it->second->getDesarrollador());
            listVideojuegos.push_back(dtVj);
        }
    }
   return listVideojuegos;
}
bool ControladorSuscVideojuego::existeVj(string videojuego){
    ManejadorVD* inst= ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}

bool ControladorSuscVideojuego::buscarSusVideoJuego(string videojuego){
    bool existe=false;
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(videojuego);
    Sesion* sesion = Sesion::getInstancia();
    Jugador* player = dynamic_cast <Jugador*> (sesion->getUsuario());
    existe=game->existeSusc(player);
    if(existe==false)
        setVj(videojuego);
    return existe;
}
void ControladorSuscVideojuego::setVj(string videojuego){
    this->videojuego=videojuego;
}
void ControladorSuscVideojuego::datosCompra(TipoDePago metodoDePago){
    this->metodoDePago=metodoDePago;
}
void ControladorSuscVideojuego::suscVideojuego(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(this->videojuego);
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    Jugador* player=dynamic_cast<Jugador*>(user);
    Suscripcion* susc = new Suscripcion(this->metodoDePago,game->getCostoSus(),player);
    game->agregarSuscripcion(susc);
}
void ControladorSuscVideojuego::cancelar(){}