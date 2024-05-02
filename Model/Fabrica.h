/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include "../Interfase/IControladorAgregarCategoria.h"
#include "../Interfase/IControladorAltaUsuario.h"
#include "../Interfase/IControladorAgregarVideojuego.h"
#include "../Interfase/IControladorInfoVideojuego.h"
#include "../Interfase/IControladorIniCerrSesion.h"
#include "../Interfase/IControladorIniciarPartida.h"
#include "../Interfase/IControladorSuscVideojuego.h"
#include "../Interfase/IControladorEliminarVideojuego.h"
#include "../Interfase/IControladorAsignarPuntajeVJ.h"
#include "../Interfase/IControladorBuscarVJCat.h"
#include "../Interfase/IControladorCancelarSuscripcion.h"
#include "../Interfase/IControladorListarVideojuegos.h"
#include "../Interfase/IControladorVerPartidasDeUnVJ.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorAgregarCategoria* getIControladorAgregarCategoria();
        IControladorAltaUsuario* getIControladorAltaUsuario();
        IControladorAgregarVideojuego* getIControladorAgregarVideojuego();
        IControladorInfoVideojuego* getIControladorInfoVideojuego();
        IControladorIniCerrSesion* getIControladorIniCerrSesion();
        IControladorIniciarPartida* getIControladorIniciarPartida();
        IControladorSuscVideojuego* getIControladorSuscVideojuego();
        IControladorEliminarVideojuego* getIControladorEliminarVideojuego();
        IControladorAsignarPuntajeVJ* getIControladorAsignarPuntajeVJ();
        IControladorBuscarVJCat* getIControladorBuscarVJCat();
        IControladorCancelarSuscripcion* getIControladorCancelarSuscripcion();
        IControladorListarVideojuegos* getIControladorListarVideojuegos();
        IControladorVerPartidasDeUnVJ* getIControladorVerPartidasDeUnVJ();
        ~Fabrica();
};
#endif