/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORAGREGARCATEGORIA_H
#define CONTROLADORAGREGARCATEGORIA_H

#include "../Interfase/IControladorAgregarCategoria.h"
#include <list>

class ControladorAgregarCategoria: public IControladorAgregarCategoria{
	private:
		string gen;
		string plat;
		string desc;
	public:
		list<DtCategoria*> listarCategorias();
		bool existeC(string,string);
		void datosCategorias(string,string,string);
		void agregarCate();
		void cancelar();
};
#endif
