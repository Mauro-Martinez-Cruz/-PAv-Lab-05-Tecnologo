/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORLISTARVIDEOJUGOS_H
#define CONTROLADORLISTARVIDEOJUGOS_H

#include "../Interfase/IControladorListarVideojuegos.h"
#include <list>

using namespace std;

class ControladorListarVideojuegos: public IControladorListarVideojuegos{
    public:
		list<DtVideojuego*> listarVideojuegosXTotalHP();
		list<DtVideojuego*> listarVideojuegosXpuntaje();
};

#endif