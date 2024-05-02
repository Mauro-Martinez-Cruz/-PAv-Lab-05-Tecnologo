/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtDesarrollador.h"
#include <iostream>
#include <string>

using namespace std;

DtDesarrollador::DtDesarrollador(){}
DtDesarrollador::DtDesarrollador(string email,string password,string trabajaEn){
    this->email=email;
    this->password=password;
    this->trabajaEn=trabajaEn;
}

string DtDesarrollador::getTrabajaEn(){
    return this->trabajaEn;
}
DtDesarrollador::~DtDesarrollador(){}
