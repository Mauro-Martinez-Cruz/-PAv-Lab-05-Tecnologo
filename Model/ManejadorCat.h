/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef MANEJADORCAT_H
#define MANEJADORCAT_H

#include "Categoria.h"
#include "../DataType/DtCategoria.h"
#include <string.h>
#include <list>
#include <map>

using namespace std;

class ManejadorCat{
    private:
        static ManejadorCat* instancia;
        map<DtCategoria*,Categoria*> categorias;
        ManejadorCat();
    public:
        static ManejadorCat* getInstancia();
        map<DtCategoria*,Categoria*> getCategorias();
        Categoria* buscarCategoria(DtCategoria*);
        void agregarCat(Categoria*);
        bool existeCat(DtCategoria*);
        void eliminarCat(DtCategoria*);
        virtual ~ManejadorCat();
};
#endif