/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ControladorAltaUsuario.h"
#include <iostream>

#include "../Model/Usuario.h"
#include "../Model/Desarrollador.h"
#include "../Model/Jugador.h"
#include "../Model/ManejadorU.h"

using namespace std;

void ControladorAltaUsuario::setTipoDeUsuario(string tipoDeUsuario){
    this->tipoDeUsuario=tipoDeUsuario;
}

bool ControladorAltaUsuario::existeEmailC(string email){
    ManejadorU* inst= ManejadorU::getInstancia();
    bool existe= inst->existeU(email);
    return existe;
}
void ControladorAltaUsuario::datosComunes(string email,string password){
    this->email=email;
    this->password=password;
}
void ControladorAltaUsuario::datosEmpresa(string nombEmp){
    this->nombEmp=nombEmp;
}
bool ControladorAltaUsuario::datosJugadorN(string nickname){
    ManejadorU* inst= ManejadorU::getInstancia();
    bool existe= inst->existeJ(nickname);
    if(existe==false){
        this->nickname=nickname;
    }
    return existe;
}
void ControladorAltaUsuario::datosJugadorD(string desc){
    this->desc=desc;
}
void ControladorAltaUsuario::altaUsuario(){
    ManejadorU* inst= ManejadorU::getInstancia();
    Usuario* nUser;
    if(tipoDeUsuario=="J" or tipoDeUsuario=="j")
        nUser = new Jugador (this->email,this->password,this->nickname,this->desc);
    else if(tipoDeUsuario=="D" or tipoDeUsuario=="d")
        nUser = new Desarrollador (this->email,this->password,this->nombEmp);
    inst->agregarU(nUser);
}

void ControladorAltaUsuario::cancelar(){}
