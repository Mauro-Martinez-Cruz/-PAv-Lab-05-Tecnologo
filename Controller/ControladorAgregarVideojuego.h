/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORAGREGARVIDEOJUEGO_H
#define CONTROLADORAGREGARVIDEOJUEGO_H

#include <string>
#include <map>
#include "../DataType/DtCategoria.h"
#include "../Model/Puntaje.h"
#include "../Model/Categoria.h"
#include "../DataType/DtVideojuego.h"
#include "../Model/Jugador.h"
#include "../Interfase/IControladorAgregarVideojuego.h"

using namespace std;

class ControladorAgregarVideojuego: public IControladorAgregarVideojuego{
    private:
        string nombre;
        string descripcion;
        int costoSusc;
        map<DtCategoria*,Categoria*> categorias;
        map<Jugador*,Puntaje*> puntajes;
    public:
        bool existeVJ(string);
        void datosVideojuego(string,string,int);
        list<DtCategoria*> listarCategorias();
        bool categoriaAdded(string,string);
        bool datosCategorias(string,string);
        map<DtCategoria*,Categoria*> getCategorias();
        DtVideojuego* mostrarVj();
        void agregarVideojuego();
        void cancelar();
};
#endif