todo: main.o Categoria.o ControladorAgregarCategoria.o ControladorAgregarVideojuego.o ControladorAltaUsuario.o ControladorAsignarPuntajeVJ.o ControladorBuscarVJCat.o ControladorCancelarSuscripcion.o ControladorEliminarVideojuego.o ControladorInfoVideojuego.o ControladorIniCerrSesion.o ControladorIniciarPartida.o ControladorListarVideojuegos.o ControladorSuscVideojuego.o ControladorVerPartidasDeUnVJ.o Desarrollador.o DtCategoria.o DtDesarrollador.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtTipoDePago.o DtUsuario.o DtVideojuego.o Fabrica.o Jugador.o ManejadorCat.o ManejadorU.o ManejadorVD.o Partida.o PartidaIndividual.o PartidaMultijugador.o Puntaje.o Sesion.o Suscripcion.o Usuario.o Videojuego.o
	g++ main.o Categoria.o ControladorAgregarCategoria.o ControladorAgregarVideojuego.o ControladorAltaUsuario.o ControladorAsignarPuntajeVJ.o ControladorBuscarVJCat.o ControladorCancelarSuscripcion.o ControladorEliminarVideojuego.o ControladorInfoVideojuego.o ControladorIniCerrSesion.o ControladorIniciarPartida.o ControladorListarVideojuegos.o ControladorSuscVideojuego.o ControladorVerPartidasDeUnVJ.o Desarrollador.o DtCategoria.o DtDesarrollador.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtTipoDePago.o DtUsuario.o DtVideojuego.o Fabrica.o Jugador.o ManejadorCat.o ManejadorU.o ManejadorVD.o Partida.o PartidaIndividual.o PartidaMultijugador.o Puntaje.o Sesion.o Suscripcion.o Usuario.o Videojuego.o -g -o main
main.o: main.cpp
	g++ -g -c main.cpp
Categoria.o: Model/Categoria.cpp
	g++ -g -c Model/Categoria.cpp
ControladorAgregarCategoria.o: Controller/ControladorAgregarCategoria.cpp
	g++ -g -c Controller/ControladorAgregarCategoria.cpp
ControladorAgregarVideojuego.o: Controller/ControladorAgregarVideojuego.cpp
	g++ -g -c Controller/ControladorAgregarVideojuego.cpp
ControladorAltaUsuario.o: Controller/ControladorAltaUsuario.cpp
	g++ -g -c Controller/ControladorAltaUsuario.cpp
ControladorAsignarPuntajeVJ.o: Controller/ControladorAsignarPuntajeVJ.cpp
	g++ -g -c Controller/ControladorAsignarPuntajeVJ.cpp
ControladorBuscarVJCat.o: Controller/ControladorBuscarVJCat.cpp
	g++ -g -c Controller/ControladorBuscarVJCat.cpp
ControladorCancelarSuscripcion.o: Controller/ControladorCancelarSuscripcion.cpp
	g++ -g -c Controller/ControladorCancelarSuscripcion.cpp
ControladorEliminarVideojuego.o: Controller/ControladorEliminarVideojuego.cpp
	g++ -g -c Controller/ControladorEliminarVideojuego.cpp
ControladorInfoVideojuego.o: Controller/ControladorInfoVideojuego.cpp
	g++ -g -c Controller/ControladorInfoVideojuego.cpp
ControladorIniCerrSesion.o: Controller/ControladorIniCerrSesion.cpp
	g++ -g -c Controller/ControladorIniCerrSesion.cpp
ControladorIniciarPartida.o: Controller/ControladorIniciarPartida.cpp
	g++ -g -c Controller/ControladorIniciarPartida.cpp
ControladorListarVideojuegos.o: Controller/ControladorListarVideojuegos.cpp
	g++ -g -c Controller/ControladorListarVideojuegos.cpp
ControladorSuscVideojuego.o: Controller/ControladorSuscVideojuego.cpp
	g++ -g -c Controller/ControladorSuscVideojuego.cpp
ControladorVerPartidasDeUnVJ.o: Controller/ControladorVerPartidasDeUnVJ.cpp
	g++ -g -c Controller/ControladorVerPartidasDeUnVJ.cpp
Desarrollador.o: Model/Desarrollador.cpp
	g++ -g -c Model/Desarrollador.cpp
DtCategoria.o: DataType/DtCategoria.cpp
	g++ -g -c DataType/DtCategoria.cpp
DtDesarrollador.o: DataType/DtDesarrollador.cpp
	g++ -g -c DataType/DtDesarrollador.cpp
DtJugador.o: DataType/DtJugador.cpp
	g++ -g -c DataType/DtJugador.cpp
DtPartida.o: DataType/DtPartida.cpp
	g++ -g -c DataType/DtPartida.cpp
DtPartidaIndividual.o: DataType/DtPartidaIndividual.cpp
	g++ -g -c DataType/DtPartidaIndividual.cpp
DtPartidaMultijugador.o: DataType/DtPartidaMultijugador.cpp
	g++ -g -c DataType/DtPartidaMultijugador.cpp
DtTipoDePago.o: DataType/DtTipoDePago.cpp
	g++ -g -c DataType/DtTipoDePago.cpp
DtUsuario.o: DataType/DtUsuario.cpp
	g++ -g -c DataType/DtUsuario.cpp
DtVideojuego.o: DataType/DtVideojuego.cpp
	g++ -g -c DataType/DtVideojuego.cpp
Fabrica.o: Model/Fabrica.cpp
	g++ -g -c Model/Fabrica.cpp
Jugador.o: Model/Jugador.cpp
	g++ -g -c Model/Jugador.cpp
ManejadorCat.o: Model/ManejadorCat.cpp
	g++ -g -c Model/ManejadorCat.cpp
ManejadorU.o: Model/ManejadorU.cpp
	g++ -g -c Model/ManejadorU.cpp
ManejadorVD.o: Model/ManejadorVD.cpp
	g++ -g -c Model/ManejadorVD.cpp
Partida.o: Model/Partida.cpp
	g++ -g -c Model/Partida.cpp
PartidaIndividual.o: Model/PartidaIndividual.cpp
	g++ -g -c Model/PartidaIndividual.cpp
PartidaMultijugador.o: Model/PartidaMultijugador.cpp
	g++ -g -c Model/PartidaMultijugador.cpp
Puntaje.o: Model/Puntaje.cpp
	g++ -g -c Model/Puntaje.cpp
Sesion.o: Model/Sesion.cpp
	g++ -g -c Model/Sesion.cpp
Suscripcion.o: Model/Suscripcion.cpp
	g++ -g -c Model/Suscripcion.cpp
Usuario.o: Model/Usuario.cpp
	g++ -g -c Model/Usuario.cpp
Videojuego.o: Model/Videojuego.cpp
	g++ -g -c Model/Videojuego.cpp
clean:
	rm -f main
	rm -f *.o
run:
	./main