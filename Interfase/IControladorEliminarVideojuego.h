/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef ICONTROLADORELIMINARVIDEOJUEGO_H
#define ICONTROLADORELIMINARVIDEOJUEGO_H

#include <string>
#include <list>

using namespace std;

class IControladorEliminarVideojuego{
    public:
        virtual list<string> listarNombreVj()=0;
        virtual bool existeVJ(string)=0;
        virtual void seleccionarVideojuego(string)=0;
        virtual void eliminarVideojuego()=0;
        virtual void cancelar()=0;
};

#endif
