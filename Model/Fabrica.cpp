/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Fabrica.h"
#include "../Controller/ControladorAgregarCategoria.h"
#include "../Controller/ControladorAltaUsuario.h"
#include "../Controller/ControladorAgregarVideojuego.h"
#include "../Controller/ControladorInfoVideojuego.h"
#include "../Controller/ControladorIniCerrSesion.h"
#include "../Controller/ControladorIniciarPartida.h"
#include "../Controller/ControladorSuscVideojuego.h"
#include "../Controller/ControladorEliminarVideojuego.h"
#include "../Controller/ControladorAsignarPuntajeVJ.h"
#include "../Controller/ControladorBuscarVJCat.h"
#include "../Controller/ControladorCancelarSuscripcion.h"
#include "../Controller/ControladorListarVideojuegos.h"
#include "../Controller/ControladorVerPartidasDeUnVJ.h"

#include <iostream>
#include <list>

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstancia(){
  if (instancia == NULL)
    instancia = new Fabrica();
  return instancia;
}

IControladorAgregarVideojuego* Fabrica::getIControladorAgregarVideojuego(){
  return new ControladorAgregarVideojuego();
}
IControladorAgregarCategoria* Fabrica::getIControladorAgregarCategoria(){
  return new ControladorAgregarCategoria();
}
IControladorAltaUsuario* Fabrica::getIControladorAltaUsuario(){
  return new ControladorAltaUsuario();
}
IControladorInfoVideojuego* Fabrica::getIControladorInfoVideojuego(){
  return new ControladorInfoVideojuego();
}
IControladorIniCerrSesion* Fabrica::getIControladorIniCerrSesion(){
  return new ControladorIniCerrSesion();
}
IControladorIniciarPartida* Fabrica::getIControladorIniciarPartida(){
  return new ControladorIniciarPartida();
}
IControladorSuscVideojuego* Fabrica::getIControladorSuscVideojuego(){
  return new ControladorSuscVideojuego();
}
IControladorEliminarVideojuego* Fabrica::getIControladorEliminarVideojuego(){
  return new ControladorEliminarVideojuego();
}
IControladorAsignarPuntajeVJ* Fabrica::getIControladorAsignarPuntajeVJ(){
  return new ControladorAsignarPuntajeVJ();
}
IControladorBuscarVJCat* Fabrica::getIControladorBuscarVJCat(){
  return new ControladorBuscarVJCat();
}
IControladorCancelarSuscripcion* Fabrica::getIControladorCancelarSuscripcion(){
  return new ControladorCancelarSuscripcion();
}
IControladorListarVideojuegos* Fabrica::getIControladorListarVideojuegos(){
  return new ControladorListarVideojuegos();
}
IControladorVerPartidasDeUnVJ* Fabrica::getIControladorVerPartidasDeUnVJ(){
  return new ControladorVerPartidasDeUnVJ();
}
Fabrica::Fabrica(){}



