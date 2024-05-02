/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtCategoria.h"
#include <iostream>

DtCategoria::DtCategoria(){}
DtCategoria::DtCategoria(string genero,string plataforma){
    this->genero=genero;
    this->plataforma=plataforma;
}

string DtCategoria::getGenero(){
    return this->genero;
}

string DtCategoria::getPlataforma(){
    return this->plataforma;
}

bool operator == (const DtCategoria& dtcat1,const DtCategoria& dtcat2){
    return dtcat1.genero == dtcat2.genero and dtcat1.plataforma == dtcat2.plataforma;  
}
ostream& operator << (ostream& salida, const DtCategoria& category){
	return cout << category.genero << " - " << category.plataforma <<endl;
}

DtCategoria::~DtCategoria(){}