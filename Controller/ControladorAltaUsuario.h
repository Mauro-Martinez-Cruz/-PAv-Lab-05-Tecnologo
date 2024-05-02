/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORALTAUSUARIO_H
#define CONTROLADORALTAUSUARIO_H

#include <string>
#include <list>
#include "../Interfase/IControladorAltaUsuario.h"

using namespace std;

class ControladorAltaUsuario: public IControladorAltaUsuario{
    private:
        string email;
        string password;
        string nombEmp;
        string nickname;
        string desc;
        string tipoDeUsuario;
    public:
        void setTipoDeUsuario(string);
        bool existeEmailC(string);
        void datosComunes(string,string);
        void datosEmpresa(string);
        bool datosJugadorN(string);
        void datosJugadorD(string);
        void altaUsuario();
        void cancelar();
};
#endif