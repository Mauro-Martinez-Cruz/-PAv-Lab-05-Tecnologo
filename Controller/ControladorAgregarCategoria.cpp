/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorAgregarCategoria.h"
#include "../Model/ManejadorCat.h"
#include <iostream>

list<DtCategoria*> ControladorAgregarCategoria::listarCategorias(){
	ManejadorCat* inst = ManejadorCat::getInstancia();
	map<DtCategoria*,Categoria*> categorias = inst->getCategorias();
	list<DtCategoria*> listCategorias;
	for (map<DtCategoria*,Categoria*>::iterator it = categorias.begin(); it != categorias.end(); ++it){
		DtCategoria* dtCat = new DtCategoria(it->second->getGenero(), it->second->getPlataforma());
		listCategorias.push_back(dtCat);
	}
	return listCategorias;
}

bool ControladorAgregarCategoria::existeC(string gen, string plat){
	ManejadorCat* inst = ManejadorCat::getInstancia();
	DtCategoria* dtCat = new DtCategoria(gen, plat);
	return inst->existeCat(dtCat);
}

void ControladorAgregarCategoria::datosCategorias(string gen, string plat, string desc){
	this->gen=gen;
	this->plat=plat;
	this->desc=desc;
}

void ControladorAgregarCategoria::agregarCate(){
	ManejadorCat* inst = ManejadorCat::getInstancia();
	Categoria* cat = new Categoria(this->gen, this->plat, this->desc);
	inst->agregarCat(cat);
}

void ControladorAgregarCategoria::cancelar() {}