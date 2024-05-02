/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ManejadorVD.h"
#include "iostream"

using namespace std;

ManejadorVD* ManejadorVD::instancia = NULL;

ManejadorVD::ManejadorVD(){}

ManejadorVD* ManejadorVD::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorVD();
    return instancia;
}

map<string,Videojuego*> ManejadorVD::getVideojuegos(){
    map<string,Videojuego*> lstVideojuegos;
    for (map<string,Videojuego*>::iterator it=this->videojuegos.begin(); it!=videojuegos.end(); ++it)
        lstVideojuegos.emplace(it->second->getNombre(),it->second);
    return lstVideojuegos;
}

Videojuego* ManejadorVD::buscarVideojuego(string DtV){
  map<string,Videojuego*>::iterator it = this->videojuegos.find(DtV);
  if(it != this->videojuegos.end())
    return it->second;
  else
    return NULL;
}

void ManejadorVD::agregarVD(Videojuego* game){
    videojuegos.emplace(game->getNombre(),game);
}

bool ManejadorVD::existeVD(string nombre){ 
  map<string,Videojuego*>::iterator it = this->videojuegos.find(nombre);
  return (it != this->videojuegos.end());
}

void ManejadorVD::eliminarVD(string nombre){
  map<string,Videojuego*>::iterator it = this->videojuegos.find(nombre);
  this->videojuegos.erase(it);
}

ManejadorVD::~ManejadorVD(){}