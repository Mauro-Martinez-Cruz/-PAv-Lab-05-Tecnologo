/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ManejadorCat.h"
#include <iostream>

using namespace std;

ManejadorCat* ManejadorCat::instancia = NULL;

ManejadorCat::ManejadorCat(){}

ManejadorCat* ManejadorCat::getInstancia(){
  if(instancia == NULL)
      instancia = new ManejadorCat();
  return instancia;
}

map<DtCategoria*,Categoria*> ManejadorCat::getCategorias(){
    map<DtCategoria*,Categoria*> lstCategorias;
    DtCategoria* cats;
    for (map<DtCategoria*,Categoria*>::iterator it=this->categorias.begin(); it!=categorias.end(); ++it){
        cats = new DtCategoria (it->second->getGenero(),it->second->getPlataforma());
        lstCategorias.emplace(cats,it->second);
    }
    return lstCategorias;
}

Categoria* ManejadorCat::buscarCategoria(DtCategoria* dtcat){
  map<DtCategoria*,Categoria*>::iterator it = this->categorias.find(dtcat);
  if(it==categorias.end())
    return NULL;
  else
    return it->second;
}

void ManejadorCat::agregarCat(Categoria* categoria){
  DtCategoria* clave = new DtCategoria(categoria->getGenero(),categoria->getPlataforma());
  categorias.emplace(clave,categoria);
}

bool ManejadorCat::existeCat(DtCategoria* dtcat){
  bool exist = false;
  for(map<DtCategoria*,Categoria*>::iterator it=categorias.begin(); it!=categorias.end(); ++it)
    if(it->second->getGenero() == dtcat->getGenero() and it->second->getPlataforma() == dtcat->getPlataforma())
      exist=true;
   return exist;
}

void ManejadorCat::eliminarCat(DtCategoria* dtcat){
	map<DtCategoria*,Categoria*>::iterator it = this->categorias.find(dtcat);
	this->categorias.erase(it);
}

ManejadorCat::~ManejadorCat(){}
