/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorEliminarVideojuego.h"
#include "../Model/ManejadorU.h"
#include "../Model/ManejadorVD.h"
#include "../Model/Sesion.h"
#include "../Model/Videojuego.h"
#include <map>

list<string> ControladorEliminarVideojuego::listarNombreVj(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    map<string,Videojuego*> videojuegos= inst->getVideojuegos();
    Sesion* sesion = Sesion::getInstancia();
    Usuario* user=sesion->getUsuario();
    list<string> listVideojuegos;
    Desarrollador* des = dynamic_cast<Desarrollador*>(sesion->getUsuario());
    for(map<string,Videojuego*>::iterator it=videojuegos.begin(); it!=videojuegos.end(); ++it)
        if(it->second->getDesarrollador()==des)
            listVideojuegos.push_back(it->second->getNombre());
    return listVideojuegos;
}

bool ControladorEliminarVideojuego::existeVJ(string videojuego){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}

void ControladorEliminarVideojuego::seleccionarVideojuego(string videojuego){
    this->videojuego=videojuego;
}

void ControladorEliminarVideojuego::eliminarVideojuego(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(this->videojuego);
    inst->eliminarVD(game->getNombre());
}
void ControladorEliminarVideojuego::cancelar(){}