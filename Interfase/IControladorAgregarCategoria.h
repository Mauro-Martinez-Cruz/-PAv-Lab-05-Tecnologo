/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORAGREGARCATEGORIA_H
#define ICONTROLADORAGREGARCATEGORIA_H

#include <string>
#include <list>
#include "../DataType/DtCategoria.h"

using namespace std;

class IControladorAgregarCategoria{
    public:        
        virtual list<DtCategoria*> listarCategorias()=0;
		virtual bool existeC(string,string)=0;
		virtual void datosCategorias(string,string,string)=0;
		virtual void agregarCate()=0;
		virtual void cancelar()=0;
};
#endif