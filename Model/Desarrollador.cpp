/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Desarrollador.h"
#include <iostream>
#include <string>

using namespace std;

Desarrollador::Desarrollador(){}
Desarrollador::Desarrollador(string email,string password,string trabajaEn){
    this->email=email;
    this->password=password;
    this->trabajaEn=trabajaEn;
}

string Desarrollador::getTrabajaEn(){
    return this->trabajaEn;
}

void Desarrollador::setTrabajaEn(string trabajaEn){
    this->trabajaEn=trabajaEn;
}

bool operator == (const Desarrollador& des1,const Desarrollador& des2){
    return des1.email == des2.email and des1.password == des2.password and des1.trabajaEn==des2.trabajaEn;  
}

Desarrollador::~Desarrollador(){}
