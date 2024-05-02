/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorCancelarSuscripcion.h"
#include "../Model/Sesion.h"
#include "../Model/Jugador.h"
#include "../Model/Videojuego.h"
#include "../Model/ManejadorVD.h"

list<DtVideojuego*> ControladorCancelarSuscripcion::listarVjSuscActiva(){
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

bool ControladorCancelarSuscripcion::existeVj(string videojuego){
    ManejadorVD* inst= ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}

bool ControladorCancelarSuscripcion::existeSusc(string videojuego){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(videojuego);
    map<Jugador*,Suscripcion*> suscripciones = game->getSuscripciones();
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    Jugador* player=dynamic_cast<Jugador*>(user);
    for(map<Jugador*,Suscripcion*>::iterator it=suscripciones.begin(); it!=suscripciones.end(); ++it)
        if(it->second->getJugador()==player)
            return true;
    return false;
}

void ControladorCancelarSuscripcion::cancelarSuscripcion(string nom){
	ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* juego=inst->buscarVideojuego(nom);
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    Jugador* player=dynamic_cast<Jugador*>(user);
    if(player!=NULL)
    	juego->eliminarSusc(player);
}