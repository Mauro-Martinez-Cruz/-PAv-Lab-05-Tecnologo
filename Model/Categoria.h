/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>

using namespace std;

class Categoria{
private:
    string genero;
    string plataforma;
    string descripcion;
public:
    Categoria();
    Categoria(string,string,string);

    string getGenero();
    string getPlataforma();
    string getDescripcion();
    
    void setGenero(string genero);
    void setPlataforma(string plataforma);
    void setDescripcion(string descripcion);

    friend ostream& operator << (ostream&, const Categoria&);

    virtual ~Categoria();
};
#endif