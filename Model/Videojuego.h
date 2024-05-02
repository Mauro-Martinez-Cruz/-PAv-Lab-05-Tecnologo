/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "Partida.h"
#include "Puntaje.h"
#include "Jugador.h"
#include "../DataType/DtCategoria.h"
#include "Categoria.h"
#include "Suscripcion.h"
#include "Desarrollador.h"
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Videojuego{
	protected:
		string nombre,descripcion;
        int costoSus,totalHP;
        float promPuntaje;
        map<DtCategoria*,Categoria*> categorias;
        map<Jugador*,Suscripcion*> suscripciones;
        list<Partida*> partidas;
        Desarrollador* desarrollador;
        map<Jugador*,Puntaje*> puntuaciones;
	public:
		Videojuego();
		Videojuego(string,string,int,int,float,map<DtCategoria*,Categoria*>,Desarrollador*,map<Jugador*,Puntaje*>);
        string getNombre();
        string getDescripcion();
        map<Jugador*,Suscripcion*> getSuscripciones();
        map<DtCategoria*,Categoria*> getCategorias();
        Desarrollador* getDesarrollador();
        bool existeSusc(Jugador*); 
        bool existeP(Jugador*);
        void agregarSusc(Suscripcion*);
        int getCostoSus();
        int getTotalHP();
        float getPromPuntaje();
        list<Partida*> getPartidas();
        
        void setNombre(string);
        void setDescripcion(string);
        void setCostoSus(int);
        void setTotalHP(int);
        void setPromPuntaje(float);
        void setPuntaje(int);

        void agregarSuscripcion(Suscripcion*);
        void agregarPartida(Partida*);
        void agregarPuntaje(Puntaje*);

        void eliminarSuscripciones();
        void eliminarPartidas();
        void eliminarPuntajes();
        void eliminarSusc(Jugador*);

		virtual ~Videojuego();
};

#endif