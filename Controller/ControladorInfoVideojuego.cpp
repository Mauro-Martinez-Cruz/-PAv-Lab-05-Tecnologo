/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorInfoVideojuego.h"
#include "../Model/ManejadorVD.h"
#include "../Model/Videojuego.h"
#include <iostream>

list<string> ControladorInfoVideojuego::listarNombreVj(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    map<string,Videojuego*> videojuegos= inst->getVideojuegos();
    list<string> listVideojuegos;
    for(map<string,Videojuego*>::iterator it=videojuegos.begin(); it!=videojuegos.end(); ++it)
        listVideojuegos.push_back(it->second->getNombre());
    return listVideojuegos;
}
DtVideojuego* ControladorInfoVideojuego::imprimirVideojuego(string nombre){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(nombre);
    if(game!=NULL){
        DtVideojuego* dtVj = new DtVideojuego (game->getNombre(),game->getDescripcion(),game->getCostoSus(),game->getTotalHP(),game->getPromPuntaje(),game->getCategorias(),game->getDesarrollador());
        return dtVj;
    }else
        return NULL;
}