/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORBUSCARVJCAT_H
#define ICONTROLADORBUSCARVJCAT_H

#include "../DataType/DtVideojuego.h"
#include "../DataType/DtCategoria.h"
#include <list>

class IControladorBuscarVJCat{
    public:
        virtual list<DtCategoria*> listarCategorias()=0;
        virtual bool existeC(string,string)=0;
    	virtual list<DtVideojuego*> buscarVJCat(string,string)=0;
};

#endif