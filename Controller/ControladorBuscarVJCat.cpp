/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorBuscarVJCat.h"
#include "../Model/ManejadorVD.h"
#include "../Model/ManejadorCat.h"

list<DtCategoria*> ControladorBuscarVJCat::listarCategorias(){
	ManejadorCat* inst = ManejadorCat::getInstancia();
	map<DtCategoria*,Categoria*> categorias = inst->getCategorias();
	list<DtCategoria*> listCategorias;
	for (map<DtCategoria*,Categoria*>::iterator it = categorias.begin(); it != categorias.end(); ++it){
		DtCategoria* dtCat = new DtCategoria(it->second->getGenero(), it->second->getPlataforma());
		listCategorias.push_back(dtCat);
	}
	return listCategorias;
}

bool ControladorBuscarVJCat::existeC(string genero,string plataforma){
	ManejadorCat* inst = ManejadorCat::getInstancia();
	DtCategoria* dtCat = new DtCategoria(genero, plataforma);
	return inst->existeCat(dtCat);
}

list<DtVideojuego*> ControladorBuscarVJCat::buscarVJCat(string genero,string plataforma){
	ManejadorVD* mVJ = ManejadorVD::getInstancia();
	map<string,Videojuego*> juegos=mVJ->getVideojuegos();
	list<DtVideojuego*> listjuegos;
	map<DtCategoria*,Categoria*> listCat;
	DtVideojuego* dtVj;
	for(map<string,Videojuego*>::iterator it=juegos.begin(); it!=juegos.end(); ++it){
		listCat=it->second->getCategorias();
		for(map<DtCategoria*,Categoria*>::iterator it2=listCat.begin(); it2!=listCat.end(); ++it2)
			if(it2->second->getGenero().compare(genero) == 0 and it2->second->getPlataforma().compare(plataforma)== 0){
				dtVj=new DtVideojuego (it->second->getNombre(),it->second->getDescripcion(),it->second->getCostoSus(),it->second->getTotalHP(),it->second->getPromPuntaje(),it->second->getCategorias(),it->second->getDesarrollador());
				listjuegos.emplace_back(dtVj);
			}
	}
    return listjuegos;
}

