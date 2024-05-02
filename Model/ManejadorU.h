/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef MANEJADORU_H
#define MANEJADORU_H

#include "Usuario.h"
#include <string>
#include <list>
#include <map>

using namespace std;

class ManejadorU{
    private:
        static ManejadorU* instancia;
        map<string,Usuario*> usuarios;
        ManejadorU();
    public:
        static ManejadorU* getInstancia();
        map<string,Usuario*> getUsuarios();
        Usuario* buscarUsuario(string);
        void agregarU(Usuario*);
        bool existeJ(string);
        bool existeU(string);
        virtual ~ManejadorU();
};
#endif