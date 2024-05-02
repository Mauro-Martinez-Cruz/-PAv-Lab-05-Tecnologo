/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef MANEJADORVD_H
#define MANEJADORVD_H

#include "Videojuego.h"
#include "../DataType/DtVideojuego.h"
#include <string.h>
#include <list>
#include <map>

using namespace std;

class ManejadorVD{
    private:
        static ManejadorVD* instancia;
        map<string,Videojuego*> videojuegos;
        ManejadorVD();
    public:
        static ManejadorVD* getInstancia();
        map<string,Videojuego*> getVideojuegos();
        Videojuego* buscarVideojuego(string);
        void agregarVD(Videojuego*);
        bool existeVD(string);
        void eliminarVD(string);
        virtual ~ManejadorVD();
};
#endif