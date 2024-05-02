/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef DTTIPODEPAGO_H
#define DTTIPODEPAGO_H

#include <iostream>
#include <string>

using namespace std;

enum TipoDePago{DEBITO,CREDITO};

class DtTipoDePago{
	private:
		TipoDePago* pago;
	public:
		DtTipoDePago();
		DtTipoDePago(TipoDePago*);
		
		TipoDePago* getPago();
		
		~DtTipoDePago();
};

#endif