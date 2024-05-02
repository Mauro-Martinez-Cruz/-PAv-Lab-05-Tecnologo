/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "DtTipoDePago.h"
#include <iostream>
#include <string>

using namespace std;

DtTipoDePago::DtTipoDePago(){}
DtTipoDePago::DtTipoDePago(TipoDePago* pago){
	this->pago=pago;
}

TipoDePago* DtTipoDePago::getPago(){
	return this->pago;
}

DtTipoDePago::~DtTipoDePago(){}