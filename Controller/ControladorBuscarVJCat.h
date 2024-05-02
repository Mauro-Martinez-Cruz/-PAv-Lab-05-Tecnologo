/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORBUSCARVJCAT_H
#define CONTROLADORBUSCARVJCAT_H

#include "../Interfase/IControladorBuscarVJCat.h"
#include "../DataType/DtCategoria.h"
#include "../DataType/DtVideojuego.h"
#include <list>
#include <map>

class ControladorBuscarVJCat: public IControladorBuscarVJCat{
    public:
        list<DtCategoria*> listarCategorias();
        bool existeC(string,string);
    	list<DtVideojuego*> buscarVJCat(string,string);
};

#endif