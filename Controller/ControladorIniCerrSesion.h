/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORINICERRSESION_H
#define CONTROLADORINICERRSESION_H

#include "../Interfase/IControladorIniCerrSesion.h"
#include <string>

using namespace std;

class ControladorIniCerrSesion: public IControladorIniCerrSesion{
    private:
        string email;
        string password;
    public:
        bool existeUsus();
        bool existeEmail(string);
        bool ingData(string,string);
        void cancelar();
        void cerrarSesion();
        string queEs();
};

#endif
