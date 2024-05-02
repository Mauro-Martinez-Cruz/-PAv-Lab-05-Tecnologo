/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORLISTARVIDEOJUEGOS_H
#define ICONTROLADORLISTARVIDEOJUEGOS_H

#include <list>
#include "../DataType/DtVideojuego.h"

using namespace std;

class IControladorListarVideojuegos{
    public:
		virtual list<DtVideojuego*> listarVideojuegosXTotalHP()=0;
		virtual list<DtVideojuego*> listarVideojuegosXpuntaje()=0;
};

#endif