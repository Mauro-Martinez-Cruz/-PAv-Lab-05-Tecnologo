/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorIniCerrSesion.h"
#include "../Model/Sesion.h"
#include "../Model/Jugador.h"
#include "../Model/Desarrollador.h"
#include "../Model/ManejadorU.h"

bool ControladorIniCerrSesion::existeUsus(){
    ManejadorU* inst = ManejadorU::getInstancia();
    map<string,Usuario*> usuarios = inst->getUsuarios();
    return usuarios.empty();
}

bool ControladorIniCerrSesion::existeEmail(string email){
    ManejadorU* inst = ManejadorU::getInstancia();
    Usuario* user = inst->buscarUsuario(email);
    if(user==NULL)
        return false;
    else
        return true;
}

bool ControladorIniCerrSesion::ingData(string email,string password){
    ManejadorU* inst = ManejadorU::getInstancia();
    Usuario* user = inst->buscarUsuario(email);
    if(password==user->getPassword()){
        Sesion* sesion = Sesion::getInstancia();
        sesion->setUsuario(user);
        return true;
    }
    return false;
}

void ControladorIniCerrSesion::cancelar(){}

void ControladorIniCerrSesion::cerrarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    sesion->deletear();
}

string ControladorIniCerrSesion::queEs(){
    Sesion* sesion = Sesion::getInstancia();
    Jugador* jug = dynamic_cast<Jugador*>(sesion->getUsuario());
    if(jug!=NULL)
        return "J";
    else
        return "D";
}

