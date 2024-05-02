/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorAgregarVideojuego.h"
#include "../Model/ManejadorCat.h"
#include "../Model/Sesion.h"
#include "../Model/ManejadorVD.h"
#include <iostream>

using namespace std;

bool ControladorAgregarVideojuego::existeVJ(string videojuego){
    ManejadorVD* inst= ManejadorVD::getInstancia();
    return inst->existeVD(videojuego);
}

void ControladorAgregarVideojuego::datosVideojuego(string nombre,string descripcion,int costoSusc){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costoSusc=costoSusc;
}

list<DtCategoria*> ControladorAgregarVideojuego::listarCategorias(){
    ManejadorCat* inst = ManejadorCat::getInstancia();
    list<DtCategoria*> listCategorias;
    map<DtCategoria*,Categoria*> categorias= inst->getCategorias();
    for (map<DtCategoria*,Categoria*>::iterator it=categorias.begin(); it!=categorias.end(); ++it){
        DtCategoria* cat= new DtCategoria(it->second->getGenero(),it->second->getPlataforma());
        listCategorias.push_back(cat);
    }
    return listCategorias;
}

bool ControladorAgregarVideojuego::categoriaAdded(string gen,string plat){
    for(map<DtCategoria*,Categoria*>::iterator it=this->categorias.begin(); it!=this->categorias.end(); ++it){
        if(it->second->getGenero() == gen and it->second->getPlataforma() == plat){
            return true;
        }
    }
    return false;
}

bool ControladorAgregarVideojuego::datosCategorias(string gen,string plat){
    bool existe=false, existe2=false;
    ManejadorCat* inst= ManejadorCat::getInstancia();
    map<DtCategoria*,Categoria*> cats = inst->getCategorias();
    DtCategoria* dtCat=new DtCategoria(gen,plat);
    existe= inst->existeCat(dtCat);
    if(existe==true){
        for(map<DtCategoria*,Categoria*>::iterator it=cats.begin(); it!=cats.end(); ++it){
            if(it->second->getGenero() == dtCat->getGenero() and it->second->getPlataforma() == dtCat->getPlataforma()){
                this->categorias.emplace(dtCat,it->second);
                return true;
            }
        }
    }
    return false;
}

map<DtCategoria*,Categoria*> ControladorAgregarVideojuego::getCategorias(){
    map<DtCategoria*,Categoria*> lstCategorias;
    DtCategoria* cats;
    for (map<DtCategoria*,Categoria*>::iterator it=this->categorias.begin(); it!=categorias.end(); ++it){
        cats = new DtCategoria (it->second->getGenero(),it->second->getPlataforma());
        lstCategorias.emplace(cats,it->second);
    }
    return lstCategorias;
}

DtVideojuego* ControladorAgregarVideojuego::mostrarVj(){
    Sesion* sesion = Sesion::getInstancia();
    Desarrollador* des = dynamic_cast<Desarrollador*>(sesion->getUsuario());
    DtVideojuego* dtVj= new DtVideojuego (this->nombre,this->descripcion,this->costoSusc,0,0,this->categorias,des);
    return dtVj;
}

void ControladorAgregarVideojuego::agregarVideojuego(){
    ManejadorVD* inst = ManejadorVD::getInstancia();
    Sesion* sesion = Sesion::getInstancia();
    Desarrollador* des = dynamic_cast<Desarrollador*>(sesion->getUsuario());
    Videojuego* game=new Videojuego(this->nombre,this->descripcion,this->costoSusc,0,0,this->categorias,des,this->puntajes);
    inst->agregarVD(game);
    this->categorias.clear();
}

void ControladorAgregarVideojuego::cancelar(){}