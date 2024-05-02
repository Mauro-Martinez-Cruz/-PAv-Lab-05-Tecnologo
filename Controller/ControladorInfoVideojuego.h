/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORINFOVIDEOJUEGO_H
#define CONTROLADORINFOVIDEOJUEGO_H

#include "../Interfase/IControladorInfoVideojuego.h"
#include "../DataType/DtVideojuego.h"
#include <list>

class ControladorInfoVideojuego: public IControladorInfoVideojuego{
	public:
		list<string> listarNombreVj();
		DtVideojuego* imprimirVideojuego(string);
};
#endif
