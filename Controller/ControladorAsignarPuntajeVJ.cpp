/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorAsignarPuntajeVJ.h"
#include "../Model/Sesion.h"
#include "../Model/ManejadorVD.h"

bool ControladorAsignarPuntajeVJ::existeVJ(string videojuego){
    ManejadorVD* inst= ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}
bool ControladorAsignarPuntajeVJ::existePunt(string videojuego){
    ManejadorVD* inst= ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(videojuego);
    Sesion* sesion = Sesion::getInstancia();
    Jugador* player = dynamic_cast<Jugador*>(sesion->getUsuario());
    return game->existeP(player);
}
map<string,DtVideojuego*> ControladorAsignarPuntajeVJ::listarDatosVJ(){
    ManejadorVD* inst=ManejadorVD::getInstancia();
    map<string,Videojuego*> juegos=inst->getVideojuegos();
    map<string,DtVideojuego*> games;
    for(map<string,Videojuego*>::iterator it=juegos.begin(); it!=juegos.end(); ++it){
        DtVideojuego* juego=new DtVideojuego(it->second->getNombre(),it->second->getDescripcion(),it->second->getCostoSus(),it->second->getTotalHP(),it->second->getPromPuntaje(),it->second->getCategorias(),it->second->getDesarrollador());
        games.emplace(it->second->getNombre(),juego);
    }
    return games;
}
void ControladorAsignarPuntajeVJ::asigPuntVideojuego1(string game,int p){
    ManejadorVD* inst=ManejadorVD::getInstancia();
    Videojuego* juego=inst->buscarVideojuego(game);
    Sesion* inst2=Sesion::getInstancia();
    Usuario* user=inst2->getUsuario();
    Jugador* player=dynamic_cast<Jugador*>(user);
    Puntaje* puntaje=new Puntaje(p, player);
    juego->agregarPuntaje(puntaje);
}

void ControladorAsignarPuntajeVJ::asigPuntVideojuego2(string game,int p){
    ManejadorVD* inst=ManejadorVD::getInstancia();
    Videojuego* juego=inst->buscarVideojuego(game);
    juego->setPuntaje(p);
}