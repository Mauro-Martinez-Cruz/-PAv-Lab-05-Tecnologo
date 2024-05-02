/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "ManejadorU.h"
#include "Jugador.h"
#include "iostream"

using namespace std;

ManejadorU* ManejadorU::instancia = NULL;

ManejadorU::ManejadorU(){}

ManejadorU* ManejadorU::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorU();
    return instancia;
}

map<string,Usuario*> ManejadorU::getUsuarios(){
    return this->usuarios;
}

Usuario* ManejadorU::buscarUsuario(string usuario){
    map<string,Usuario*>::iterator it = this->usuarios.find(usuario);
    if(it!=usuarios.end())
        return it->second;
    else
        return NULL;
}

void ManejadorU::agregarU(Usuario* user){
    this->usuarios.emplace(pair<string,Usuario*>(user->getEmail(),user));
}

bool ManejadorU::existeJ(string nickname){
    Jugador* player;
    string nick;
    for(map<string,Usuario*>::iterator it=this->usuarios.begin(); it!=this->usuarios.end(); ++it){
        player=dynamic_cast<Jugador*>(it->second);
        if(player!=NULL){
            nick= player->getNickname();
            if(nickname.compare(nick)==0)
                return true;
        }
    }
        return false;
}

bool ManejadorU::existeU(string email){
    map<string,Usuario*>::iterator it=this->usuarios.find(email);
    if(it != this->usuarios.end())
        return true;
    else
        return false;
}

ManejadorU::~ManejadorU(){}