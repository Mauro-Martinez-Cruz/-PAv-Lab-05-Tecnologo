/*
Alumnos:
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#ifndef CONTROLADORINICIARPARTIDA_H
#define CONTROLADORINICIARPARTIDA_H

#include "../Interfase/IControladorIniciarPartida.h"
#include <time.h>

class ControladorIniciarPartida: public IControladorIniciarPartida{
    private:
        string nombre;
        bool partContinuada,transEnVivo;
        int cantJugadores,duracion;
        string tipoPartida;
    public:
        list<DtVideojuego*> listarVjSuscActiva();
        bool existeVJ(string);
        void cualVideojuego(string);
        void datosPartidaI(bool);
        void datosPartidaM(bool,int);
        void datosPartida(int);
        void setTipoPartida(string);
        void iniciarPartida();
        void cancelar();
};

#endif