/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorVerPartidasDeUnVJ.h"
#include "../Model/ManejadorVD.h"
#include "../Model/PartidaIndividual.h"
#include "../Model/PartidaMultijugador.h"

list<DtVideojuego*> ControladorVerPartidasDeUnVJ::listarVJ(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    map<string,Videojuego*> videojuegos= inst->getVideojuegos();
    list<DtVideojuego*> listVideojuegos;
    for(map<string,Videojuego*>::iterator it=videojuegos.begin(); it!=videojuegos.end(); ++it){
        DtVideojuego* dtVj= new DtVideojuego(it->second->getNombre(),it->second->getDescripcion(),it->second->getCostoSus(),it->second->getTotalHP(),it->second->getPromPuntaje(),it->second->getCategorias(),it->second->getDesarrollador());
        listVideojuegos.push_back(dtVj);
    }
   return listVideojuegos;
}

bool ControladorVerPartidasDeUnVJ::existeVJ(string videojuego){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}

list<DtPartidaIndividual*> ControladorVerPartidasDeUnVJ::verPartidasVjI(string videojuego){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(videojuego);
    list<Partida*>partidas = game->getPartidas();
    list<DtPartidaIndividual*>partidasI;
    PartidaIndividual* partidaI;
    DtPartidaIndividual* dtPI;
    for(list<Partida*>::iterator it=partidas.begin(); it!=partidas.end(); ++it){
        partidaI=dynamic_cast<PartidaIndividual*>(*it);
        if(partidaI!=NULL){
            dtPI= new DtPartidaIndividual(partidaI->getTime(),partidaI->getDuracion(),partidaI->getJugador(),partidaI->getContiParAnt());
            partidasI.emplace_back(dtPI);
        }
    }
    return partidasI;
}

list<DtPartidaMultijugador*> ControladorVerPartidasDeUnVJ::verPartidasVjM(string videojuego){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Videojuego* game = inst->buscarVideojuego(videojuego);
    list<Partida*>partidas = game->getPartidas();
    list<DtPartidaMultijugador*>partidasM;
    PartidaMultijugador* partidaM;
    DtPartidaMultijugador* dtPM;
    for(list<Partida*>::iterator it=partidas.begin(); it!=partidas.end(); ++it){
        partidaM=dynamic_cast<PartidaMultijugador*>(*it);
        if(partidaM!=NULL){
            dtPM= new DtPartidaMultijugador(partidaM->getTime(),partidaM->getDuracion(),partidaM->getJugador(),partidaM->getCantJugadores(),partidaM->getTransEnVivo());
            partidasM.emplace_back(dtPM);
        }
    }
    return partidasM;
}
