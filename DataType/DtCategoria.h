/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTCATEGORIA_H
#define DTCATEGORIA_H

#include <iostream>

using namespace std;

class DtCategoria{
private:
    string genero;
    string plataforma;
public:
    DtCategoria();
    DtCategoria(string,string);

    string getGenero();
    string getPlataforma();

    friend bool operator == (const DtCategoria&,const DtCategoria&);
    friend ostream& operator << (ostream&, const DtCategoria&);

    virtual ~DtCategoria();
};
#endif