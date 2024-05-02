/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DtVideojuego_H
#define DtVideojuego_H

#include <iostream>
#include <string>
#include "../Model/Categoria.h"
#include "DtCategoria.h"
#include "../Model/Desarrollador.h"
#include <list>
#include <map>

using namespace std;

class DtVideojuego{
	protected:
		string nombre,descripcion;
        int costoSus,totalHP;
        float promPuntaje;
        map<DtCategoria*,Categoria*> categorias;
        Desarrollador* desarrollador;
	public:
		DtVideojuego();
		DtVideojuego(string,string,int,int,float,map<DtCategoria*,Categoria*>,Desarrollador*);
        string getNombre();
        string getDescripcion();
        int getCostoSus();
        int getTotalHP();
        float getPromPuntaje();
        Desarrollador* getDesarrollador();
        map<DtCategoria*,Categoria*> getCategorias();
		
		virtual ~DtVideojuego();
};

#endif