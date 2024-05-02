/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef SESION_H
#define SESION_H

#include "Usuario.h"

class Sesion{
    private:
        static Sesion* instancia;
        Usuario* user;
        Sesion();
    public:
        static Sesion* getInstancia();
        Usuario* getUsuario();
        void setUsuario(Usuario*);
        void deletear();
};
#endif
