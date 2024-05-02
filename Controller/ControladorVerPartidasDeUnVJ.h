/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORVERPARTIDASDEUNVJ_H
#define CONTROLADORVERPARTIDASDEUNVJ_H

#include "../Interfase/IControladorVerPartidasDeUnVJ.h"

class ControladorVerPartidasDeUnVJ: public IControladorVerPartidasDeUnVJ{
    private:

    public:
        list<DtVideojuego*> listarVJ();
        bool existeVJ(string);
        list<DtPartidaIndividual*> verPartidasVjI(string);
        list<DtPartidaMultijugador*> verPartidasVjM(string);
};

#endif
