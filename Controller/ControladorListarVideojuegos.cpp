/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorListarVideojuegos.h"
#include "../Model/ManejadorVD.h"
#include "../Model/Videojuego.h"
#include <iostream>
#include <map>

using namespace std;

list<DtVideojuego*> ControladorListarVideojuegos::listarVideojuegosXTotalHP(){
	ManejadorVD* inst = ManejadorVD::getInstancia();
	map<string,Videojuego*> juegos=inst->getVideojuegos();
	list<DtVideojuego*> juegosD;
	list<int> duraciones;
	for (map<string,Videojuego*>::iterator it=juegos.begin(); it!=juegos.end(); ++it){
		int duracion= it->second->getTotalHP();
		duraciones.push_back(duracion);
	}
	duraciones.sort();
	for (list<int>::iterator it=duraciones.begin(); it!=duraciones.end(); ++it){
		map<string,Videojuego*>::iterator it2=juegos.begin();
		while(it2->second->getTotalHP()!=*it)
			++it2;
		DtVideojuego* dtVj= new DtVideojuego(it2->second->getNombre(),it2->second->getDescripcion(),it2->second->getCostoSus(),it2->second->getTotalHP(),it2->second->getPromPuntaje(),it2->second->getCategorias(),it2->second->getDesarrollador());
		juegosD.push_front(dtVj);
		juegos.erase(it2->second->getNombre());
	}
	return juegosD;
}

list<DtVideojuego*> ControladorListarVideojuegos::listarVideojuegosXpuntaje(){
	ManejadorVD* inst = ManejadorVD::getInstancia();
	map<string,Videojuego*> juegos=inst->getVideojuegos();
	list<float> promedios;
	list<DtVideojuego*> juegosP;
	for (map<string,Videojuego*>::iterator it=juegos.begin(); it!=juegos.end(); ++it){
		float promedio= it->second->getPromPuntaje();
		promedios.push_back(promedio);
	}
	promedios.sort();
	for (list<float>::iterator it=promedios.begin(); it!=promedios.end(); ++it){
		map<string,Videojuego*>::iterator it2=juegos.begin();
		while(it2->second->getPromPuntaje()!=*it)
			++it2;
		DtVideojuego* dtVj= new DtVideojuego(it2->second->getNombre(),it2->second->getDescripcion(),it2->second->getCostoSus(),it2->second->getTotalHP(),it2->second->getPromPuntaje(),it2->second->getCategorias(),it2->second->getDesarrollador());
		juegosP.push_front(dtVj);
		juegos.erase(it2->second->getNombre());
	}
	return juegosP;
}
