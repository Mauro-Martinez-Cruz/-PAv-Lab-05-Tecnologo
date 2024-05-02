/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorIniciarPartida.h"
#include "../Model/Sesion.h"
#include "../Model/Usuario.h"
#include "../Model/ManejadorVD.h"
#include "../Model/Videojuego.h"
#include "../DataType/DtVideojuego.h"
#include "../Model/Partida.h"
#include "../Model/PartidaIndividual.h"
#include "../Model/PartidaMultijugador.h"

list<DtVideojuego*> ControladorIniciarPartida::listarVjSuscActiva(){
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

bool ControladorIniciarPartida::existeVJ(string videojuego){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Jugador* player=dynamic_cast<Jugador*>(user);
    if(inst->existeVD(videojuego)==true){
        Videojuego* game = inst->buscarVideojuego(videojuego);
        if(game->existeSusc(player)==true)
            return true;
    }
    return false;
}

void ControladorIniciarPartida::cualVideojuego(string nombre){
    this->nombre=nombre;
}

void ControladorIniciarPartida::datosPartidaI(bool partContinuada){
    this->partContinuada=partContinuada;
}

void ControladorIniciarPartida::datosPartidaM(bool transEnVivo, int cantJugadores){
    this->transEnVivo=transEnVivo;
    this->cantJugadores=cantJugadores;
}

void ControladorIniciarPartida::datosPartida(int duracion){

    this->duracion=duracion;
}

void ControladorIniciarPartida::setTipoPartida(string tipoPartida){
    this->tipoPartida=tipoPartida;
}

void ControladorIniciarPartida::iniciarPartida(){
    Partida* p;
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* juego=inst->buscarVideojuego(this->nombre);
    Jugador* player=dynamic_cast<Jugador*>(user);
    juego->existeSusc(player);
    time_t rawtime;
    tm* timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    if(this->tipoPartida=="I" or this->tipoPartida=="i")
        p = new PartidaIndividual(timeinfo,this->duracion,player,this->partContinuada);
    else if(this->tipoPartida=="M" or this->tipoPartida=="m")
        p=new PartidaMultijugador(timeinfo,this->duracion,player,this->transEnVivo,this->cantJugadores);
    juego->agregarPartida(p);
}

void ControladorIniciarPartida::cancelar(){}