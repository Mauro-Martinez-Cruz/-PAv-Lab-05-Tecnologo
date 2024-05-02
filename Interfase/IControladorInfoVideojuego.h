/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORINFOVIDEOJUEGO_H
#define ICONTROLADORINFOVIDEOJUEGO_H

#include <list>
#include <string>
#include "../DataType/DtVideojuego.h"

using namespace std;

class IControladorInfoVideojuego{
    public:
    	virtual list<string> listarNombreVj()=0;
		virtual DtVideojuego* imprimirVideojuego(string)=0;
};
#endif