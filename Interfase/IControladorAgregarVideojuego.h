/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORAGREGARVIDEOJUEGO_H
#define ICONTROLADORAGREGARVIDEOJUEGO_H

#include <string>
#include <list>
#include <map>
#include "../DataType/DtVideojuego.h"

using namespace std;

class IControladorAgregarVideojuego{
    public:
        virtual bool existeVJ(string)=0;
        virtual void datosVideojuego(string,string,int)=0;
        virtual list<DtCategoria*> listarCategorias()=0;
        virtual bool categoriaAdded(string,string)=0;
        virtual bool datosCategorias(string,string)=0;
        virtual map<DtCategoria*,Categoria*> getCategorias()=0;
        virtual DtVideojuego* mostrarVj()=0;
        virtual void agregarVideojuego()=0;
        virtual void cancelar()=0;
};
#endif