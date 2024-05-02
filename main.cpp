/*
Anna Torres
Jonatan Marroco
Mateo Di Lauro
Mauro Martinez
*/

#include "Model/Fabrica.h"
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <list>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <termios.h>

using namespace std;

Fabrica* fabrica;
IControladorIniCerrSesion* iControladorIniCerrSesion;
IControladorAltaUsuario* iControladorAltaUsuario;
IControladorAgregarVideojuego* iControladorAgregarVideojuego;
IControladorEliminarVideojuego* iControladorEliminarVideojuego;
IControladorAgregarCategoria* iControladorAgregarCategoria;
IControladorIniciarPartida* iControladorIniciarPartida;
IControladorSuscVideojuego* iControladorSuscVideojuego;
IControladorInfoVideojuego* iControladorInfoVideojuego;
IControladorAsignarPuntajeVJ* iControladorAsignarPuntajeVJ;
IControladorCancelarSuscripcion* iControladorCancelarSuscripcion;
IControladorBuscarVJCat* iControladorBuscarVJCat;
IControladorListarVideojuegos* iControladorListarVideojuegos;
IControladorVerPartidasDeUnVJ* iControladorVerPartidasDeUnVJ;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[34m"
#define RESET "\x1b[0m"

void leerStr(string &aux){
    cin >> ws;
    getline(cin, aux);
}

string passStrMayus(string cadena){
    transform(cadena.begin(), cadena.end(), cadena.begin(),[](unsigned char c){ return toupper(c); });
    return cadena;
}

void continuar(){
    cout << "Presione ENTER para continuar..."<<endl;
    system("read X");
}

void estrellasPuntaje(float puntaje){
    double parteDecimal,parteEntera;
    int algo;

    parteDecimal=modf(puntaje,&parteEntera);
    algo=parteEntera;
    cout << "Puntuacion Promedio: " << puntaje << " ";
    for(int i=0;i<algo;i++)
        cout << "★";
    if(parteDecimal!=0)
        cout << "✯";
    else if(parteDecimal==0 and algo!=5)
        cout << "☆";
    if(algo+1<5)
        for(int t=algo+1;t<5;t++)
            cout << "☆";
    cout<<endl;
}
 
string ocultarClave(){
    string mostrarClave;
    string clave;
    bool fin=false;
    while(fin==false){
        cout<<"(M)ostrar o (O)cultar la clave ➤ ";
        leerStr(mostrarClave);cout<<endl;
        if(mostrarClave=="O" or mostrarClave=="o"){
            cout<<"Ingrese su Clave (Clave Oculta) ➤ ";
            char g;
            struct termios oldattr, newattr;
            tcgetattr(STDIN_FILENO, &oldattr);
            newattr = oldattr;
            newattr.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
            while(g != '\n'){
                cin.get(g);
                if(isalnum(g) or ispunct(g)){
                    cout << '*';
                    clave.push_back(g);
                }
            }
            tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
            cout<<endl;
            fin=true;
        }else if(mostrarClave=="M" or mostrarClave=="m"){
            cout<<"Ingrese su Clave (Clave Visible) ➤ ";
            leerStr(clave);
            fin=true;
        }else{
            cout<<RED"No existe esa opción..."<<RESET<<endl;
            cout<<endl;
        }
    }
    return clave;
}

void menuPrecargaDeDatos(){

    //Se precarga un Desarrollador
    iControladorAltaUsuario->setTipoDeUsuario("D");
    iControladorAltaUsuario->datosComunes("emaild1","1234");
    iControladorAltaUsuario->datosEmpresa("Electronic Arts");
    iControladorAltaUsuario->altaUsuario();

    //Se inicia sesion como Desarrollador
    iControladorIniCerrSesion->ingData("emaild1","1234");

    //Categorias de PC 
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","PC","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","PC","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","PC","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","PC","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Categorias de SWITCH
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","SWITCH","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","SWITCH","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","SWITCH","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","SWITCH","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Categorias de PS4
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","PS4","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","PS4","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","PS4","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","PS4","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Categorias de XBOX ONE
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","XBOX ONE","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","XBOX ONE","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","XBOX ONE","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","XBOX ONE","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Categorias de XBOX X
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","XBOX X","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","XBOX X","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","XBOX X","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","XBOX X","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Categorias de PS5
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ACCION","PS5","Pegar tiros pa todos lados");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("AVENTURA","PS5","Mirar cosas y eso, onda Animal Planet");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("ESTRATEGIA","PS5","El mejor para mi... que queres q te diga");
	iControladorAgregarCategoria->agregarCate();
    //Se precarga una Categoria
    iControladorAgregarCategoria->datosCategorias("DEPORTE","PS5","El deporte es toda aquella actividad física que involucra una serie de reglas o normas a desempeñar dentro de un espacio o área determinada.");
	iControladorAgregarCategoria->agregarCate();

    //Se precarga un Videojuego
    iControladorAgregarVideojuego->datosVideojuego("NBA","Es un videojuego de simulación de baloncesto",1595);
    iControladorAgregarVideojuego->listarCategorias();
    iControladorAgregarVideojuego->datosCategorias("DEPORTE","PC");
    iControladorAgregarVideojuego->agregarVideojuego();

    //Se precarga un Videojuego
    iControladorAgregarVideojuego->datosVideojuego("Carlos Duti","Matar a los enemigos de estados unidos del momento, actualmente Rusia",3268);
    iControladorAgregarVideojuego->listarCategorias();
    iControladorAgregarVideojuego->datosCategorias("ACCION","PS4");
    iControladorAgregarVideojuego->datosCategorias("ACCION","PC");
    iControladorAgregarVideojuego->datosCategorias("ACCION","PS5");
    iControladorAgregarVideojuego->datosCategorias("ACCION","SWITCH");
    iControladorAgregarVideojuego->agregarVideojuego();

    //Se cierra sesion como Desarrollador
    iControladorIniCerrSesion->cerrarSesion();

    //Se precarga un Jugador
    iControladorAltaUsuario->setTipoDeUsuario("J");
    iControladorAltaUsuario->datosComunes("emailj1","1234");
    iControladorAltaUsuario->datosJugadorN("Nickname1");
    iControladorAltaUsuario->datosJugadorD("Que onda broder, me gusta jugar a los jueguitos de shuter, genio");
    iControladorAltaUsuario->altaUsuario();

    //Se inicia sesion como Jugador
    iControladorIniCerrSesion->ingData("emailj1","1234");

    //Crear Suscripcion a Videojuego
    iControladorSuscVideojuego->buscarSusVideoJuego("NBA");
    iControladorSuscVideojuego->datosCompra(DEBITO);
    iControladorSuscVideojuego->suscVideojuego();

    //Iniciar Partida
    iControladorIniciarPartida->cualVideojuego("NBA");
    iControladorIniciarPartida->setTipoPartida("I");
    iControladorIniciarPartida->datosPartidaI(false);
    iControladorIniciarPartida->datosPartida(3);
    iControladorIniciarPartida->iniciarPartida();

    //Se cierra sesion como Jugador
    iControladorIniCerrSesion->cerrarSesion();
}

//Iniciar Sesión
bool menuIniciarSesion(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                    "<<YELLOW"Iniciar Sesión"<<CYAN"                    │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;

    string email, password, opt;
    bool sesIni=false, existe=false, fin=false;

    if(iControladorIniCerrSesion->existeUsus()==false){
        while(fin==false){
            cout<<endl;
            cout<<"Ingrese su Email ➤ ";
            leerStr(email);cout<<endl;
            existe= iControladorIniCerrSesion->existeEmail(email);
            if(existe==false){
                cout<<RED"Ese Email no existe..."<<RESET""<<endl;
                return false;
            }else{
                password=ocultarClave();cout<<endl;
                sesIni=iControladorIniCerrSesion->ingData(email,password);
                if(sesIni==true){
                    cout<<GREEN"Sesión iniciada con exito..."<<RESET""<<endl;
                    return true;
                }else if(sesIni==false){
                    cout<<RED"Datos de usuario incorrectos..."<<RESET""<<endl;
                    cout<<endl;
                    cout<<"(R)eintentar o (C)ancelar? ➤ ";
                    leerStr(opt);cout<<endl;
                    if(opt=="C" or opt=="c"){
                        iControladorIniCerrSesion->cancelar();
                        cout<<GREEN"Se ha cancelado el inicio de sesión..."<<RESET""<<endl;
                        return false;
                    }else if(opt!="R" and opt!="r"){
                        cout<<RED"No existe esa opción..."<<RESET""<<endl;
                        return false;
                    }
                }
            }
        }
    }else{
        cout<<endl;
        cout<<RED"No hay usuarios registrados..."<<RESET""<<endl;
    }
    return false;
}

//Cerrar Sesión
void menuCerrarSesion(){
    iControladorIniCerrSesion->cerrarSesion();
    cout<<GREEN"Se ha cerrado la sesión..."<<RESET""<<endl;
}

//Alta Usuario
void menuAltaUsuario(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                     "<<YELLOW"Alta Usuario"<<CYAN"                     │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string email, password, usuario, trabajaEn, nickname, descripcion, opt, opc;
        bool existe=true, fin=false, salir=false;

        cout<<"Ingrese un email ➤ ";
        while(existe==true){
            cin>>email;cout<<endl;
            existe= iControladorAltaUsuario->existeEmailC(email);
            if(existe==true){
                cout<<RED"Este email ya esta en uso..."<<RESET""<<endl;
                cout<<endl;
                cout<<"Ingrese otro email ➤ ";
            }
        }
        cout<<"Ingrese su Clave ➤ ";
        leerStr(password);cout<<endl;
        iControladorAltaUsuario->datosComunes(email,password);

        cout<<"Cuenta de (D)esarrollador o de (J)ugador? ➤ ";
        leerStr(usuario);cout<<endl;
        if(usuario=="D" or usuario=="d")
            salir=true;
        else if(usuario=="J" or usuario=="j")
            salir=true;
        while(salir==false){
            cout<<RED"Tipo de usuario no encontrado..."<<RESET""<<endl;
            cout<<endl;
            cout<<"Cuenta de (D)esarrollador o de (J)ugador? ➤ ";
            leerStr(usuario);cout<<endl;
            if(usuario=="D" or usuario=="d")
                salir=true;
            else if(usuario=="J" or usuario=="j")
                salir=true;
        }
        iControladorAltaUsuario->setTipoDeUsuario(usuario);
        if(usuario=="D" or usuario=="d"){
            cout<< "Ingrese la empresa para la cual trabaja ➤ ";
            leerStr(trabajaEn);cout<<endl;
            iControladorAltaUsuario->datosEmpresa(trabajaEn);
        }else if(usuario=="J" or usuario=="j"){
            cout<< "Ingrese un Nickname ➤ ";
            leerStr(nickname);cout<<endl;
            existe= iControladorAltaUsuario->datosJugadorN(nickname);
            if(existe==true){
                while(fin==false){
                    cout<<RED"Ya existe un jugador con ese Nickname..."<<RESET""<<endl;
                    cout<<endl;
                    cout<<"(R)eintentar o (C)ancelar? ➤ ";
                    leerStr(opc);cout<<endl;
                    if(opc=="R" or opc=="r"){
                        cout<< "Ingrese otro Nickname ➤ ";
                        leerStr(nickname);cout<<endl;
                        existe= iControladorAltaUsuario->datosJugadorN(nickname);
                        if(existe==false)
                            fin=true;
                    }else if(opc=="C" or opc=="c"){
                        fin=true;
                    }else
                        throw invalid_argument("No existe esa opcion...");
                }
            }
        }
        if((usuario=="J" or usuario=="j") and (opc=="C" or opc=="c")){
            iControladorAltaUsuario->cancelar();
            cout<<GREEN"Se ha cancelado el registro del usuario..."<<RESET""<<endl;
        }else{
            if(usuario=="J" or usuario=="j"){
                cout<<"Ingrese una breve descripcion ➤ ";
                leerStr(descripcion);cout<<endl;
                iControladorAltaUsuario->datosJugadorD(descripcion);
            }
            while(fin==false){
                cout<< "(C)onfirmar o (F)inalizar ➤ ";
                leerStr(opt);cout<<endl;
                if(opt=="C" or opt=="c"){
                    iControladorAltaUsuario->altaUsuario();
                    cout<<GREEN"Se ha registrado al usuario exitosamente..."<<RESET""<<endl;
                    fin=true;
                }else if(opt=="F" or opt=="f"){
                    iControladorAltaUsuario->cancelar();
                    cout<<GREEN"Se ha cancelado el registro del usuario..."<<RESET""<<endl;
                    fin=true;
                }else{
                    cout<<RED"No existe esa opción..."<<endl;
                    cout<<RESET""<<endl;
                }
            }
        }
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Agregar Videojuego
void menuAgregarVideojuego(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                 "<<YELLOW"Agregar un Videojuego"<<CYAN"                │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string nom, desc, opc, opc2;
        int costo;
        bool fin=false, existe=false;
        string gen, plat;

        list<DtCategoria*> listCates= iControladorAgregarVideojuego->listarCategorias();
        if(listCates.empty())
            throw invalid_argument("No hay categorías en el sistema...");
        else{
            cout<<"Ingrese los datos del videojuego:"<<endl;
            cout<<endl;
            cout<<"Nombre ➤ ";
            leerStr(nom);cout<<endl;
            if(iControladorAgregarVideojuego->existeVJ(nom)==true)
                throw invalid_argument("Ya existe ese videojuego...");
            cout<<"Descripcion ➤ ";
            leerStr(desc);cout<<endl;
            cout<<"Costo de suscripcion ➤ ";
            cin>>costo;cout<<endl;
            iControladorAgregarVideojuego->datosVideojuego(nom,desc,costo);

            cout<<"Estas son las todas las categorias: "<<endl<<endl;
            for(list<DtCategoria*>::iterator it = listCates.begin();it !=listCates.end();it++)
                cout << **it << endl;
            
            while(fin==false){
                cout<<"Escriba la categoria..."<<endl;
                cout<<endl;
                cout<<"Genero ➤ ";
                leerStr(gen);cout<<endl;
                gen=passStrMayus(gen);
                cout<<"Plataforma ➤ ";
                leerStr(plat);cout<<endl;
                plat=passStrMayus(plat);

                if((iControladorAgregarVideojuego->categoriaAdded(gen,plat))==true){
                    cout<<RED"Ya fue agregada esta categoria..."<<RESET""<<endl;
                    cout<<endl;
                }else{
                    existe= iControladorAgregarVideojuego->datosCategorias(gen,plat);
                    if(existe==false){
                        cout<<RED"Los datos ingresados son incorrectos..."<<RESET""<<endl;
                        cout<<endl;
                    }
                }
                cout<<"Quiere elegir otra categoria? (S)i/(N)o ➤ ";
                leerStr(opc);cout<<endl;
                if(opc=="N" or opc=="n"){
                    if(((iControladorAgregarVideojuego->getCategorias()).empty())==true){
                        cout<<RED"Tenes que elegir al menos una categoria..."<<RESET""<<endl;
                        cout<<endl;
                    }else
                        fin=true;
                }else if(opc=="S" or opc=="s"){
                    cout<<"Ya puedes elegir nuevamente..."<<endl;
                    cout<<endl;
                }else
                    throw invalid_argument("No existe esa opcion...");
            }
            DtVideojuego* dtVj= iControladorAgregarVideojuego->mostrarVj();
            cout<<"Nombre: "<<dtVj->getNombre()<<endl<<"Descripcion: "<<dtVj->getDescripcion()<<endl<<"Costo de Suscripcion: "<<dtVj->getCostoSus()<<endl<<"Desarrollador: "<<dtVj->getDesarrollador()->getEmail()<<endl;
            cout<<"Lista de Categorias: "<<endl;
            map<DtCategoria*,Categoria*> listCate=dtVj->getCategorias();
            for(map<DtCategoria*,Categoria*> ::iterator it=listCate.begin();it!=listCate.end();it++)
                cout<<it->second->getGenero()<< " - " <<it->second->getPlataforma()<<endl;
            cout<<endl;
            cout<<"(C)onfirmar / (F)inalizar) ➤ ";
            leerStr(opc2);cout<<endl;
            if(opc2=="C" or opc2=="c"){
                iControladorAgregarVideojuego->agregarVideojuego();
                cout<<GREEN"Se ha dado de dado de alta el videojuego exitosamente..."<<RESET""<<endl;
            }else if(opc2=="F" or opc2=="f"){
                iControladorAgregarVideojuego->cancelar();
                cout<<GREEN"Se ha cancelado el alta del videojuego..."<<RESET""<<endl;
            }else
                throw invalid_argument("No existe esa opcion...");
        }
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Iniciar Partida
void menuIniciarPartida(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                    "<<YELLOW"Iniciar Partida"<<CYAN"                   │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string videojuego, tipoPartida, opt, opc;
        bool partContinuada, transEnVivo;
        int cantJugadores,duracion;

        list<DtVideojuego*> listVideojuego = iControladorIniciarPartida->listarVjSuscActiva();
        cout<<"Lista de suscripciones activas:"<<endl;
        for(list<DtVideojuego*>::iterator it = listVideojuego.begin();it !=listVideojuego.end();it++)
            cout << (*it)->getNombre() << endl;
        cout<<endl;

        cout<<"Seleccione un Videojuego ➤ ";
        leerStr(videojuego);cout<<endl;
        if((iControladorIniciarPartida->existeVJ(videojuego))==true){
            iControladorIniciarPartida->cualVideojuego(videojuego);
            cout<<"Partida (I)ndividual o (M)ultijugador? ➤ ";
            leerStr(tipoPartida);cout<<endl;
            iControladorIniciarPartida->setTipoPartida(tipoPartida);
            if(tipoPartida=="I" or tipoPartida=="i"){
                cout<<"Es una partida continuada? (S)i/(N)o ➤ ";
                leerStr(opt);cout<<endl;
                if(opt=="S" or opt=="s")
                    partContinuada=true;
                else if(opt=="N" or opt=="n")
                    partContinuada=false;
                else
                    throw invalid_argument("No existe esa opción...");
                iControladorIniciarPartida->datosPartidaI(partContinuada);
            }else if(tipoPartida=="M" or tipoPartida=="m"){
                cout<<"Es una partida transmitida en vivo? (S)i/(N)o ➤ ";
                leerStr(opt);cout<<endl;
                if(opt=="S" or opt=="s")
                    transEnVivo=true;
                else if(opt=="N" or opt=="n")
                    transEnVivo=false;
                else
                    throw invalid_argument("No existe esa opción...");
                cout<<"Cuantos Jugadores? ➤ ";
                cin>>cantJugadores;cout<<endl;
                iControladorIniciarPartida->datosPartidaM(transEnVivo,cantJugadores);
            }else
                throw invalid_argument("No existe esa opción...");
            cout<<"Ingrese la duración de la partida ➤ ";
            cin>>duracion;cout<<endl;
            iControladorIniciarPartida->datosPartida(duracion);
            cout<<"(C)onfirmar / (F)inalizar) ➤ ";
            leerStr(opc);cout<<endl;
            if(opc=="C" or opc=="c"){
                iControladorIniciarPartida->iniciarPartida();
                cout<<GREEN"Se ha iniciado una partida de " << videojuego <<"..."<<RESET""<<endl; 
            }else if(opc=="F" or opc=="f"){
                iControladorIniciarPartida->cancelar();
                cout<<GREEN"Se ha cancelado el inicio de la partida de " << videojuego << "..."<<RESET""<<endl;
            }else
                throw invalid_argument("No existe esa opción...");
        }else
            throw invalid_argument("No existe ese Videojuego...");
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Suscribirse a un Videojuego
void menuSuscVideojuego(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│             "<<YELLOW"Suscribirse a un Videojuego"<<CYAN"              │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;
    
    try{
        string videojuego, tipoPago, opt;
        bool tiene=false, fin=false;
        TipoDePago metodoDePago;

        list<DtVideojuego*> listSuscAct = iControladorSuscVideojuego->listarVjSuscActiva();
        cout<<"Lista de suscripciones activas:"<<endl;
        if(listSuscAct.empty()){
            cout<<RED"No tienes ninguna suscripción activa..."<<RESET""<<endl;
            cout<<endl;
        }else{
            for(list<DtVideojuego*>::iterator it = listSuscAct.begin();it !=listSuscAct.end();it++)
                cout << "Nombre: " << (*it)->getNombre() << ", Costo de la Suscripción: " << (*it)->getCostoSus() << endl;
            cout<<endl;
        }

        list<DtVideojuego*> listSuscNoAct = iControladorSuscVideojuego->listarVjSuscNoActiva();
        cout<<"Lista de suscripciones no activas:"<<endl;
        if(listSuscNoAct.empty()){
            throw invalid_argument("Ya estás suscripto a todos los videojuegos...");
        }else{
            for(list<DtVideojuego*>::iterator it2 = listSuscNoAct.begin();it2 !=listSuscNoAct.end();it2++)
                cout << "Nombre: " << (*it2)->getNombre() << ", Costo de la Suscripción: " << (*it2)->getCostoSus() << endl;
            cout<<endl;
        }
        while(fin==false){
            cout<<"Seleccione un Videojuego➤ ";
            leerStr(videojuego);cout<<endl;
            
            if((iControladorSuscVideojuego->existeVj(videojuego))==true){
                tiene = iControladorSuscVideojuego->buscarSusVideoJuego(videojuego);
                if(tiene==true){
                    throw invalid_argument("Ya cuenta con una sucripcion activa de ese videojuego...");
                }
                else if(tiene==false){
                    cout<<"Ingrese el medio de pago [(D)ebito/(C)redito] ➤ ";
                    leerStr(tipoPago);cout<<endl;
                    if(tipoPago=="D" or tipoPago=="d")
                        metodoDePago=DEBITO;
                    else if(tipoPago=="C" or tipoPago=="c")
                        metodoDePago=CREDITO;
                    else
                        throw invalid_argument("No existe ese tipo...");
                    iControladorSuscVideojuego->datosCompra(metodoDePago);
                }
                cout<<"(C)onfirmar / (F)inalizar) ➤ ";
                leerStr(opt);cout<<endl;
                if(opt=="C" or opt=="c"){
                    iControladorSuscVideojuego->suscVideojuego();
                    cout<<GREEN"Suscripcion de " << videojuego << " adquirida con exito" <<"..."<<RESET""<<endl; 
                }else if(opt=="F" or opt=="f"){
                    iControladorSuscVideojuego->cancelar();
                    cout<<GREEN"Se ha cancelado la suscripcion a " << videojuego << "..."<<RESET""<<endl;
                }else
                    throw invalid_argument("No existe esa opcion...");
                fin=true;
            }else
                throw invalid_argument("Ese Videojuego no existe...");
        }
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}


//Ver informacion de un Videojuego
void menuInfoVideojuego(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│           "<<YELLOW"Ver información de un Videojuego"<<CYAN"           │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    string videojuego;
    DtVideojuego* dtVj;

    list<string> listVj = iControladorInfoVideojuego->listarNombreVj();
    cout<<"Lista de Videojuegos:"<<endl;
    for(list<string>::iterator it = listVj.begin();it !=listVj.end();it++)
        cout << (*it) << endl;
    cout<<endl;
    cout<<"Seleccione un Videojuego ➤ ";
    leerStr(videojuego);cout<<endl;
    dtVj=iControladorInfoVideojuego->imprimirVideojuego(videojuego);
    if(dtVj==NULL){
        cout<< RED"No existe un Videojuego con ese nombre..."<<RESET""<<endl;
        system("sleep 2");
    }else{
        cout<< "Nombre: "<< dtVj->getNombre() <<endl;
        cout<< "Descripcion: "<< dtVj->getDescripcion() <<endl;
        cout<< "Costo de Suscripcion: "<< dtVj->getCostoSus() <<endl;
        cout<< "Nombre de la Empresa: "<< dtVj->getDesarrollador()->getTrabajaEn() <<endl;
        cout<< "Cantidad de Horas Jugadas: "<< dtVj->getTotalHP() <<endl;
        estrellasPuntaje(dtVj->getPromPuntaje());
        cout<< "Categorias a las que pertenece: "<<endl;
        map<DtCategoria*,Categoria*> listCategorias = dtVj->getCategorias();
        for(map<DtCategoria*,Categoria*>::iterator it2 = listCategorias.begin();it2 !=listCategorias.end();it2++)
            cout<<(*it2->second);
        cout<<endl;
        continuar();
    }
}


//Eliminar un Videojuego
void menuEliminarVideojuego(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                "<<YELLOW"Eliminar un Videojuego"<<CYAN"                │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string videojuego, opt;

        list<string> listVj = iControladorEliminarVideojuego->listarNombreVj();
        if(listVj.empty())
            throw invalid_argument("No creaste ningún Videojuego...");
        cout<<"Lista de Videojuegos:"<<endl;
        for(list<string>::iterator it = listVj.begin();it !=listVj.end();it++)
            cout << (*it) << endl;
        cout<<endl;

        cout<<"Seleccione un Videojuego ➤ ";
        leerStr(videojuego);cout<<endl;
        if((iControladorEliminarVideojuego->existeVJ(videojuego))==true){
            iControladorEliminarVideojuego->seleccionarVideojuego(videojuego);

            cout<<"(C)onfirmar / (F)inalizar) ➤ ";
            leerStr(opt);cout<<endl;
            if(opt=="C" or opt=="c"){
                iControladorEliminarVideojuego->eliminarVideojuego();
                cout<<GREEN"Se ha eliminado el videojuego " << videojuego <<"..."<<RESET""<<endl; 
            }else if(opt=="F" or opt=="f"){
                iControladorEliminarVideojuego->cancelar();
                cout<<GREEN"Se ha cancelado la eliminacion del videojuego " << videojuego << "..."<<RESET""<<endl;
            }else
                throw invalid_argument("No existe esa opcion...");
        }else
            throw invalid_argument("No has creado ese Videojuego...");
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Agregar una Categoria
void menuAgregarCategoria(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                "<<YELLOW"Agregar una Categoria"<<CYAN"                 │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string genero, plataforma, descripcion, opt;
        bool existe=false, fin=false;
        list<DtCategoria*> listCate = iControladorAgregarCategoria->listarCategorias();
        
        if(listCate.empty()){
            cout<<RED"No se han ingresado categorias..."<<RESET""<<endl;
            cout<<endl;
        }else{
            cout<<"Lista de Categorias:"<<endl;
            for(list<DtCategoria*>::iterator it = listCate.begin();it !=listCate.end();it++)
                cout << **it << endl;
        }
        cout<<"Ingrese un genero ➤ ";
        leerStr(genero);cout<<endl;
        genero=passStrMayus(genero);
        cout<<"Ingrese una plataforma ➤ ";
        leerStr(plataforma);cout<<endl;
        plataforma=passStrMayus(plataforma);
        while(fin==false){
            existe=iControladorAgregarCategoria->existeC(genero,plataforma);
            if(existe==true){
                cout<<"Ya fue agregada esa categoria anterior mente..."<<endl;
                cout<<"Ingrese otro genero ➤ ";
                leerStr(genero);cout<<endl;
                genero=passStrMayus(genero);
                cout<<"Ingrese otra plataforma ➤ ";
                leerStr(plataforma);cout<<endl;
                plataforma=passStrMayus(plataforma);
            }else{
                cout<<"Escriba una breve descripcion ➤ ";
                leerStr(descripcion);cout<<endl;
                iControladorAgregarCategoria->datosCategorias(genero,plataforma,descripcion);

                cout<<"(C)onfirmar / (F)inalizar) ➤ ";
                leerStr(opt);cout<<endl;
                if(opt=="C" or opt=="c"){
                    iControladorAgregarCategoria->agregarCate();
                    cout<<GREEN"Se ha agregado la categoria " << genero << "-" << plataforma <<"..."<<RESET""<<endl; 
                }else if(opt=="F" or opt=="f"){
                    iControladorAgregarCategoria->cancelar();
                    cout<<GREEN"Se ha cancelado agregar la categoria " << genero << " - " << plataforma << "..."<<RESET""<<endl;
                }else
                    throw invalid_argument("No existe esa opcion...");
                fin=true;
            }
        }
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Asignar un Puntaje a un Videojuego
void menuAsignarPuntajeVJ(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│            "<<YELLOW"Asignar Puntaje a un Videojuego"<<CYAN"           │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string videojuego;
        int puntaje;
        bool exist, sePudo;
        
        map<string,DtVideojuego*> juegos=iControladorAsignarPuntajeVJ->listarDatosVJ();
        cout<< "Lista de Videojuegos: "<<endl;
        cout<<endl;
        for(map<string,DtVideojuego*>::iterator it=juegos.begin(); it!=juegos.end(); it++){
            cout<<"Nombre: " << it->second->getNombre()<< ". Descripcion: " << it->second->getDescripcion() << endl;
            cout<<endl;
        }
        
        cout<<"Seleccione el juego que quiere puntuar ➤ ";
        leerStr(videojuego);cout<<endl;
        exist=iControladorAsignarPuntajeVJ->existeVJ(videojuego);
        if(exist==false)
            throw invalid_argument("No existe ese videojuego...");
        cout<<"Que puntaje le quiere dar a "<< videojuego << " (1...5)" << " ➤ ";
        cin>>puntaje;cout<<endl;
        if(puntaje!=1 and puntaje!=2 and puntaje!=3 and puntaje!=4 and puntaje!=5)
            throw invalid_argument("La puntuacion solo puede ser de 1 a 5 ★ ...");
        if((iControladorAsignarPuntajeVJ->existePunt(videojuego))==false){
            iControladorAsignarPuntajeVJ->asigPuntVideojuego1(videojuego,puntaje);
            cout<<GREEN"Se ha puntuado a "<< videojuego << " con " << puntaje << " ★ de manera correcta..."<<RESET""<<endl;
        }else{
            iControladorAsignarPuntajeVJ->asigPuntVideojuego2(videojuego,puntaje);
            cout<<GREEN"Se ha cambiado la puntuacion dada a "<< videojuego << " con " << puntaje << " ★ de manera correcta..."<<RESET""<<endl;
        }        
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Buscar Videojuegos por una Categoria
void menuBuscarVJCat(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│         "<<YELLOW"Buscar Videojuegos por una Categoria"<<CYAN"         │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    string genero, plataforma;
    bool fin=false, existe=false;
    DtVideojuego* game;

    list<DtCategoria*> listCate = iControladorBuscarVJCat->listarCategorias();
    if(listCate.empty()){
        cout<<"No se han ingresado categorias..."<<endl;
        cout<<endl;
    }else{
        cout<<"Lista de Categorias:"<<endl;
        cout<<endl;
        for(list<DtCategoria*>::iterator it = listCate.begin();it !=listCate.end();it++)
            cout << **it;
    }

    cout<<endl;
    cout<<"Ingrese un genero ➤ ";
    leerStr(genero);cout<<endl;
    genero=passStrMayus(genero);
    cout<<"Ingrese una plataforma ➤ ";
    leerStr(plataforma);cout<<endl;
    plataforma=passStrMayus(plataforma);
    while(fin==false){
        existe=iControladorBuscarVJCat->existeC(genero,plataforma);
        if(existe==false){
            cout<<RED"Esa categoria no existe..."<<RESET""<<endl;
            cout<<endl;
            cout<<"Ingrese otro genero ➤ ";
            leerStr(genero);cout<<endl;
            genero=passStrMayus(genero);
            cout<<"Ingrese otra plataforma ➤ ";
            leerStr(plataforma);cout<<endl;
            plataforma=passStrMayus(plataforma);
        }else
            fin=true;
    }
    cout<< "Lista de Videojuegos segun la categoría: " << genero << " - " << plataforma <<endl;
    cout<<endl;
    list<DtVideojuego*> listVJ = iControladorBuscarVJCat->buscarVJCat(genero,plataforma);
    for(list<DtVideojuego*>::iterator it2=listVJ.begin(); it2!=listVJ.end(); it2++){
        game = new DtVideojuego(**it2);
        cout << "Nombre: " << game->getNombre() << ", Descripcion: " << game->getDescripcion() << endl;
        cout<<endl;
        
    }
    continuar();
}

//Cancelar Suscripcion de un Videojuego
void menuCancelarSuscripcion(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│         "<<YELLOW"Cancelar Suscripción de un Videojuego"<<CYAN"        │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;
    try{
        string videojuego;
        DtVideojuego* game;
        bool fin=false;

        list<DtVideojuego*> listDtVJ = iControladorCancelarSuscripcion->listarVjSuscActiva();
        cout<< "Tus Videojuegos: "<<endl;
        cout<<endl;
        for(list<DtVideojuego*>::iterator it=listDtVJ.begin(); it!=listDtVJ.end(); it++){
            game = new DtVideojuego(**it);
            cout << "Nombre: " << game->getNombre() <<endl;
            cout << "Descripcion: " << game->getDescripcion() << endl;
            cout << "Costo de la Suscripcion: " << game->getCostoSus() << endl;
            cout << endl;
        }

        cout<<"Selecione un videojuego..."<<endl;
        while(fin==false){
            cout<<"Nombre ➤ ";
            leerStr(videojuego);cout<<endl;
            if((iControladorCancelarSuscripcion->existeVj(videojuego))==true){
                if((iControladorCancelarSuscripcion->existeSusc(videojuego))==true){
                    iControladorCancelarSuscripcion->cancelarSuscripcion(videojuego);
                    cout<<GREEN"Se ha cancelado la suscripcion a " << videojuego << "..."<<RESET""<<endl;
                    fin=true;
                }else
                    throw invalid_argument ("No estás suscripto a ese Videojuego...");
            }else
                throw invalid_argument ("No existe el Videojuego...");
        }
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Ranking de Videojuegos
void menuRankingDeVideojuegos(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│                "<<YELLOW"Ranking de Videojuegos"<<CYAN"                │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string opcion;
        DtVideojuego* game;
        cout<<endl;
        cout<<"Ver ranking de videojuegos por [(D)uracion/(P)untaje]"<<endl;
        cout<<endl;
        cout<<"Selecione una opcion ➤ ";
        leerStr(opcion);cout<<endl;cout<<endl;

        if(opcion=="D" or opcion=="d"){
            list<DtVideojuego*> listDtVJ = iControladorListarVideojuegos->listarVideojuegosXTotalHP();
            cout<< "Videojuegos ordenados por duracion: "<<endl;
            cout<<endl;
            for(list<DtVideojuego*>::iterator it=listDtVJ.begin(); it!=listDtVJ.end(); it++){
                game = new DtVideojuego(**it);
                cout << "Nombre: " << game->getNombre() <<endl;
                cout << "Descripcion: " << game->getDescripcion() << endl;
                estrellasPuntaje(game->getPromPuntaje());
                cout << "Total de horas: " << game->getTotalHP() << endl;
                cout << endl;
            }
        }else if(opcion=="P" or opcion=="p"){
            list<DtVideojuego*> listDtVJ = iControladorListarVideojuegos->listarVideojuegosXpuntaje();
            cout<< "Videojuegos ordenados por puntaje: "<<endl;
            cout<<endl;
            for(list<DtVideojuego*>::iterator it=listDtVJ.begin(); it!=listDtVJ.end(); it++){
                game = new DtVideojuego(**it);
                cout << "Nombre: " << game->getNombre() <<endl;
                cout << "Descripcion: " << game->getDescripcion() << endl;
                estrellasPuntaje(game->getPromPuntaje());
                cout << "Puntuacion Promedio: " << game->getPromPuntaje() << endl;
                cout << "Total de horas: " << game->getTotalHP() << endl;
                cout << endl;
            }
        }else
            throw invalid_argument("No existe esa opcion...");
        continuar();
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

//Ver Partidas de un Videojuego
void menuVerPartidasDeUnVJ(){
    system("clear");
    cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
    cout<<CYAN"│             "<<YELLOW"Ver Partidas de un Videojuego"<<CYAN"            │"<<endl;
    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
    cout<<endl;

    try{
        string videojuego;

        list<DtVideojuego*> listVJ = iControladorVerPartidasDeUnVJ->listarVJ();
        cout<<"Lista de Videojuegos:"<<endl;
        if(listVJ.empty()){
            cout<<RED"No existe ningun Videojuego..."<<RESET""<<endl;
            cout<<endl;
        }else{
            for(list<DtVideojuego*>::iterator it = listVJ.begin();it !=listVJ.end();it++)
                cout << "Nombre: " << (*it)->getNombre() << ", Descripcion: " << (*it)->getDescripcion() << endl;
            cout<<endl;
        }
        cout<<"Selecione un Videojuego ➤ ";
        leerStr(videojuego);cout<<endl;

        if(iControladorVerPartidasDeUnVJ->existeVJ(videojuego)==true){
            list<DtPartidaIndividual*> listPI = iControladorVerPartidasDeUnVJ->verPartidasVjI(videojuego);
            list<DtPartidaMultijugador*> listPM = iControladorVerPartidasDeUnVJ->verPartidasVjM(videojuego);
            if(listPI.empty() and listPM.empty())
                cout<<RED""<< videojuego << " no tiene Partidas creadas..."<<RESET""<<endl;
            else{
                cout << "Lista de Partidas Individuales: " << endl;
                cout << endl;
                for(list<DtPartidaIndividual*>::iterator it = listPI.begin();it !=listPI.end();it++)
                    cout << **it << endl;
                if(listPI.empty()){
                    cout<< videojuego << " no tiene Partidas Individuales creadas..." <<endl;
                    cout<<endl;
                }
                for(list<DtPartidaMultijugador*>::iterator it2 = listPM.begin();it2 !=listPM.end();it2++)
                    cout << **it2 << endl;
                if(listPM.empty()){
                    cout<< videojuego << " no tiene Partidas Multijugador creadas..." <<endl;
                    cout<<endl;
                }
                continuar();
            }
        }else
            throw invalid_argument("No existe el Videojuego...");
    }catch(exception& e){
		cerr << RED"" << e.what() << RESET"" << endl;
	}
}

void menuJugador(){
    bool fin=false;
    int opcion;

    do{
        system("clear");
        cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
	    cout<<CYAN"│                   "<<YELLOW"MENU DEL JUGADOR"<<CYAN"                   │"<<endl;
	    cout<<CYAN"│       "<<RESET"1.- Iniciar Partida"<<CYAN"                            │"<<endl;
	    cout<<CYAN"│       "<<RESET"2.- Suscribirse a un Videojuego"<<CYAN"                │"<<endl;
	    cout<<CYAN"│       "<<RESET"3.- Información de un Videojuego"<<CYAN"               │"<<endl;
	    cout<<CYAN"│       "<<RESET"4.- Asignar Puntaje a un Videojuego"<<CYAN"            │"<<endl;
	    cout<<CYAN"│       "<<RESET"5.- Buscar Videojuego por una Categoria"<<CYAN"        │"<<endl;
	    cout<<CYAN"│       "<<RESET"6.- Cancelar Suscripción de un Videojuego"<<CYAN"      │"<<endl;
	    cout<<CYAN"│       "<<RESET"7.- Cerrar Sesión"<<CYAN"                              │"<<endl;
	    cout<<CYAN"└──────────────────────────────────────────────────────┘"<<endl;
        cout<<endl;
        cout<<RESET"Seleccione una opción ➤ ";
        cin>>opcion;cout<<endl;

        switch(opcion){
            case 1:
                iControladorIniciarPartida= fabrica->getIControladorIniciarPartida();
                menuIniciarPartida();
                delete iControladorIniciarPartida;
            break;
            case 2:
                iControladorSuscVideojuego= fabrica->getIControladorSuscVideojuego();
                menuSuscVideojuego();
                delete iControladorSuscVideojuego;
            break;
            case 3:
                iControladorInfoVideojuego= fabrica->getIControladorInfoVideojuego();
                menuInfoVideojuego();
                delete iControladorInfoVideojuego;
            break;
            case 4:
                iControladorAsignarPuntajeVJ= fabrica->getIControladorAsignarPuntajeVJ();
                menuAsignarPuntajeVJ();
                delete iControladorAsignarPuntajeVJ;
            break;
            case 5:
                iControladorBuscarVJCat= fabrica->getIControladorBuscarVJCat();
                menuBuscarVJCat();
                delete iControladorBuscarVJCat;
            break;
            case 6:
                iControladorCancelarSuscripcion= fabrica->getIControladorCancelarSuscripcion();
                menuCancelarSuscripcion();
                delete iControladorCancelarSuscripcion;
            break;
            case 7:
                iControladorIniCerrSesion= fabrica->getIControladorIniCerrSesion();
                menuCerrarSesion();
                delete iControladorIniCerrSesion;
                fin = true;
            break;
            default:
                cout<<endl;
                cout<<"┌──────────────────────────────────────────────────────┐" << endl;
                cout<<"│                No es una opcion válida...            │" << endl;
                cout<<"└──────────────────────────────────────────────────────┘" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        if(opcion!=3 and opcion!=5 and opcion!=7)
            system("sleep 2");
    }while(fin==false);
}

void menuDesarrollador(){
    bool fin=false;
    int opcion;

    do{
        system("clear");
        cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
	    cout<<CYAN"│                 "<<YELLOW"MENU DEL DESARROLLADOR"<<CYAN"               │"<<endl;
        cout<<CYAN"│       "<<RESET"1.- Agregar Videojuego"<<CYAN"                         │"<<endl;
        cout<<CYAN"│       "<<RESET"2.- Información de un Videojuego"<<CYAN"               │"<<endl;
        cout<<CYAN"│       "<<RESET"3.- Eliminar un Videojuego"<<CYAN"                     │"<<endl;
        cout<<CYAN"│       "<<RESET"4.- Agregar una Categoria"<<CYAN"                      │"<<endl;
        cout<<CYAN"│       "<<RESET"5.- Buscar Videojuego por una Categoría"<<CYAN"        │"<<endl;
        cout<<CYAN"│       "<<RESET"6.- Ranking de Videojuegos"<<CYAN"                     │"<<endl;
        cout<<CYAN"│       "<<RESET"7.- Ver Partidas de un Videojuego"<<CYAN"              │"<<endl;
        cout<<CYAN"│       "<<RESET"8.- Cerrar Sesión"<<CYAN"                              │"<<endl;
        cout<<CYAN"└──────────────────────────────────────────────────────┘"<<endl;
        cout<<endl;
        cout<<RESET"Seleccione una opción ➤ ";
        cin>>opcion;cout<<endl;

        switch(opcion){
            case 1: 
                iControladorAgregarVideojuego = fabrica->getIControladorAgregarVideojuego();
                menuAgregarVideojuego();
                delete iControladorAgregarVideojuego;
            break;
            case 2:
                iControladorInfoVideojuego = fabrica->getIControladorInfoVideojuego();
                menuInfoVideojuego();
                delete iControladorInfoVideojuego;
            break;
            case 3:
                iControladorEliminarVideojuego = fabrica->getIControladorEliminarVideojuego();
                menuEliminarVideojuego();
                delete iControladorEliminarVideojuego;
            break;
            case 4:
                iControladorAgregarCategoria = fabrica->getIControladorAgregarCategoria();
                menuAgregarCategoria();
                delete iControladorAgregarCategoria;
            break;
            case 5:
                iControladorBuscarVJCat= fabrica->getIControladorBuscarVJCat();
                menuBuscarVJCat();
                delete iControladorBuscarVJCat;
            break;
            case 6:
                iControladorListarVideojuegos= fabrica->getIControladorListarVideojuegos();
                menuRankingDeVideojuegos();
                delete iControladorListarVideojuegos;
            break;
            case 7:
                iControladorVerPartidasDeUnVJ= fabrica->getIControladorVerPartidasDeUnVJ();
                menuVerPartidasDeUnVJ();
                delete iControladorVerPartidasDeUnVJ;
            break;
            case 8:
                iControladorIniCerrSesion= fabrica->getIControladorIniCerrSesion();
                menuCerrarSesion();
                delete iControladorIniCerrSesion;
                fin = true;
            break;
            default:
                cout<<endl;
                cout<<"┌──────────────────────────────────────────────────────┐" << endl;
                cout<<"│                No es una opcion válida...            │" << endl;
                cout<<"└──────────────────────────────────────────────────────┘" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        if(opcion!=2 and opcion!=5 and opcion!=6 and opcion!=8)
            system("sleep 2");
    }while(fin==false);
}
void imprimir(string bar[102]){
    for(int i=0;i<=100;i++)
        cout<<BLUE""<<bar[i];
}
int main(){
    
    fabrica = Fabrica::getInstancia();
    iControladorIniCerrSesion = fabrica->getIControladorIniCerrSesion();
    bool fin=false, precargaDatos=false, inicio=false;
    int opcion;
    string tipoUsuario;
    system("clear");

    cout<<"                                    "<<YELLOW"░░░░░░░░░░"<<RESET"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<<endl;
    cout<<"                                    "<<YELLOW"███████╗░█"<<BLUE"█████╗████████╗██╗███╗░░░███╗"<<endl;
	cout<<"                                    "<<YELLOW"██╔════╝██"<<RESET"╔════╝╚══██╔══╝██║████╗░████║"<<endl;
	cout<<"                                    "<<YELLOW"█████╗░░╚█"<<BLUE"████╗░░░░██║░░░██║██╔████╔██║"<<endl;
	cout<<"                                    "<<RESET"██╔══╝░░░╚═══██╗░░░██║░░░██║██║╚██╔╝██║"<<endl;
	cout<<"                                    "<<BLUE"███████╗██████╔╝░░░██║░░░██║██║░╚═╝░██║"<<endl;
	cout<<"                                    "<<RESET"╚══════╝╚═════╝░░░░╚═╝░░░╚═╝╚═╝░░░░░╚═╝"<<endl;
    cout<<"                                    "<<BLUE"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<<endl;
	for(int t=0;t<4;t++)
		cout<<endl;
	int i=0;
	string bar[102], palabra, algo;
	memset(bar, 0, sizeof(bar));
	const char* lable = "|/-\\|";
    palabra="Cargando... ";
	while(i <= 100){
        cout<<RESET""<<palabra<<" ["<<i<<"%]["<<lable[i%4]<<"]";
        imprimir(bar);
        cout<<"\r";
        fflush(stdout);
        bar[i++] = "▆";
        if(i==100)
            palabra="Listo ";
        usleep(60000);
	}
	cout<<RESET""<<endl;
    
    do{
        system("clear");
        cout<<CYAN"┌──────────────────────────────────────────────────────┐"<<endl;
        cout<<CYAN"│                    "<<YELLOW"MENU PRINCIPAL"<<CYAN"                    │"<<endl;
        cout<<CYAN"│                 "<<RESET"1.- Registrarse"<<CYAN"                      │"<<endl;
        cout<<CYAN"│                 "<<RESET"2.- Iniciar sesión"<<CYAN"                   │"<<endl;
        cout<<CYAN"│                 "<<RESET"3.- Precarga de datos"<<CYAN"                │"<<endl;
        cout<<CYAN"│                 "<<RESET"4.- Salir"<<CYAN"                            │"<<endl;
        cout<<CYAN"└──────────────────────────────────────────────────────┘"<<endl; 
        cout<<endl;
        cout<<RESET"Seleccione una opción ➤ ";
        cin>>opcion;cout<<endl;

        switch(opcion){
            case 1:
                iControladorAltaUsuario = fabrica->getIControladorAltaUsuario();
                menuAltaUsuario();
                delete iControladorAltaUsuario;
            break;
            case 2:
                iControladorIniCerrSesion= fabrica->getIControladorIniCerrSesion();
                inicio=menuIniciarSesion();
                tipoUsuario=iControladorIniCerrSesion->queEs();
                delete iControladorIniCerrSesion;
                system("sleep 2");
                if(inicio==true){
                    if(tipoUsuario=="J" or tipoUsuario=="j")
                        menuJugador();
                    else if(tipoUsuario=="D" or tipoUsuario=="d")            
                        menuDesarrollador();
                }
            break;
            case 3:
                if(precargaDatos==false){
                    iControladorAgregarVideojuego = fabrica->getIControladorAgregarVideojuego();
                    iControladorAltaUsuario = fabrica->getIControladorAltaUsuario();
                    iControladorAgregarCategoria = fabrica->getIControladorAgregarCategoria();
                    iControladorIniCerrSesion = fabrica->getIControladorIniCerrSesion();
                    iControladorSuscVideojuego = fabrica->getIControladorSuscVideojuego();
                    iControladorIniciarPartida = fabrica->getIControladorIniciarPartida();
                    menuPrecargaDeDatos();
                    delete iControladorAltaUsuario;
                    delete iControladorAgregarVideojuego;
                    delete iControladorAgregarCategoria;
                    delete iControladorIniCerrSesion;
                    delete iControladorSuscVideojuego;
                    delete iControladorIniciarPartida;
                    cout<<GREEN"Datos precargados..."<<RESET""<<endl;
                    cout<<endl;
                }else{
                    cout<<RED"No se puede volver a precargar los datos.."<<RESET""<<endl;
                    cout<<endl;
                }
                precargaDatos=true;
            break;
            case 4:
                system("clear");
                system("sleep 1");
                cout<<"make: *** [makefile:83: run] Violación de segmento (core dumped) [Núcleo vaciado a un archivo]"<<endl;
                cout<<"[tecnoinf@tecnoinf210 Actual]$ ";
                cin>>algo;cout<<endl;
                cout<<"Te la creiste xD"<<endl;
                cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⣤⣤⠴⠶⠶⠶⠶⠒⠾⠿⠿⠿⣛⡛⠛⠛⠛⠛⠛⠻⠿⡷⠶⠶⢶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠀⠀⠀⠀⢀⣤⡾⠟⠛⠉⣉⣩⣤⡴⠦⠭⠥⠒⠒⠒⠒⠒⠒⠒⠒⠂⠤⠀⢀⣀⠈⠑⠢⢀⠑⠀⠀⠙⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠀⠀⣠⡾⠟⠁⣠⡢⠔⢫⠞⣉⣀⡀⠀⠀⠀⠐⠒⠄⠠⠀⠀⠐⡠⢂⡴⠶⠦⢴⡊⠙⠒⠀⠑⠀⠀⠀⠀⠹⣧⡀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠀⢠⣿⠀⡠⢊⡫⡀⢀⣤⣞⣡⣼⣿⣦⠀⠐⠉⠱⡤⢢⠦⠀⠀⣰⠋⣀⣤⣴⣿⣿⣆⠀⠀⠀⠀⠀⠀⠙⠳⢾⣷⡀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠀⣼⡏⣰⠁⠠⠪⠿⣟⠩⠉⠀⠀⠈⢻⡧⠄⣴⠞⠁⣣⠖⠀⢰⣧⠞⠁⠀⠠⠍⡻⣼⡆⠀⢀⣀⡀⠀⠀⠀⠀⠙⣧⡀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⣴⡾⠟⣽⢋⡒⠦⡢⠐⠀⠄⠒⠲⠶⠖⠋⠀⢸⡇⠀⠀⠙⠀⠀⠘⣷⡀⠤⠤⠀⠀⠀⠉⠛⠻⡍⠀⠐⠉⣉⣗⠦⣄⠘⢿⣦⡀⠀⠀"<<endl;
                cout<<"⣾⠋⠀⢸⠇⢹⠟⢦⣄⡀⠄⠀⠀⠉⠁⣰⠶⢖⣾⠁⠀⠀⠀⠐⠒⢦⣤⣝⠓⠒⠒⠊⠀⠈⠀⠀⢀⣴⠞⠋⣽⢻⠱⡈⢳⡈⢯⠻⣦⠀"<<endl;
                cout<<"⣿⠀⡆⠸⣆⢸⡦⡄⠉⠛⠶⣬⣔⡀⠘⠁⢸⡏⠁⠀⠀⠶⢦⣤⡀⠈⡇⠈⠳⠄⠀⢀⠀⠀⣀⡴⢿⠥⣄⣼⠃⡌⠀⢳⠀⢳⠸⡄⠘⣧"<<endl;
                cout<<"⣿⡀⡇⠀⠈⠷⣇⡗⣦⣠⡀⠈⠙⠛⡿⠶⠾⢿⣶⣶⣶⣶⣀⣀⣁⣀⣁⣀⣠⣤⣿⠿⠟⠛⣉⣀⡏⢀⡿⠁⠰⠀⠀⢸⠀⠀⠀⡇⠀⣿"<<endl;
                cout<<"⠘⣷⡁⢀⢸⠀⣿⠀⡟⠀⣷⠋⢳⡾⠙⢷⡀⠀⣠⠤⣌⠉⠉⣉⣭⣍⠉⣩⠭⢤⣀⡴⠚⢲⡇⠀⣿⠏⠀⠠⠃⠀⠀⣸⠀⠀⠀⠁⣼⠏"<<endl;
                cout<<"⠀⠘⣷⢸⠈⡆⣿⣿⣁⢀⠏⠀⢸⡇⠀⠀⢻⣾⠁⠀⠈⢳⣴⠏⠀⠹⣶⠇⠀⠀⢹⡀⣀⣼⣷⡾⠃⢠⠀⢀⠄⠀⠠⠁⠀⠀⣀⣼⠋⠀"<<endl;
                cout<<"⠀⠀⢸⣿⠀⡇⣿⣿⣿⣿⣤⣄⣼⠃⠀⠀⢸⡟⠀⠀⠀⠀⣿⠀⠀⠀⣿⡀⠀⢀⣿⣿⣿⣿⡟⠁⢠⠃⠀⠀⠀⡀⠀⠀⢀⣼⠟⠁⠀⠀"<<endl;
                cout<<"⠀⠀⢸⣿⠀⡇⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣿⣧⣀⣀⣤⣤⣿⣶⣶⣶⣿⣿⣿⣿⣿⣿⡿⣫⠄⢀⠂⠀⠀⠀⠀⡄⠀⢠⣿⠁⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⢸⣿⠀⣧⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣩⠞⠁⡰⠁⠀⠠⠀⠀⡐⠀⢠⡾⠃⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⢸⡇⠀⣿⡟⢀⡟⠀⣿⠋⢻⡿⠻⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢁⡔⠁⠠⠞⠀⠀⠀⠁⢀⠌⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⣼⠃⡄⢹⣿⡙⢇⣠⡇⠀⣸⠁⢠⠇⠀⢹⠃⢠⠛⠙⡏⠉⣇⣼⠿⢃⡴⠋⠀⠐⠁⠔⠀⠐⠁⣠⣢⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⣿⠀⡇⠸⡿⢷⣄⡀⠙⠒⠳⡤⠼⣄⣀⢼⣀⢾⣀⣸⣶⡾⠟⣁⡴⠋⢀⡠⠒⠁⠀⠀⢀⣤⡾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⣿⠀⠻⡄⠉⠠⡉⠙⠳⠶⣶⣶⣶⣾⣷⣶⠿⠿⠟⠋⠉⠖⠫⠕⠒⠈⠀⢀⣤⣴⡶⠟⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⢿⡄⠀⠉⠓⠀⠀⠈⠉⠠⠌⠀⠀⠀⣀⠠⠄⠂⠠⠤⠤⠴⠊⠁⣀⣴⡾⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠈⠻⣦⣑⠒⠤⣅⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣶⠶⠶⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
                cout<<"⠀⠀⠀⠀⠈⠙⠛⠶⠶⣤⣭⣭⣭⣭⣴⠶⠶⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;

                system("sleep 3");
                
                system("clear");
                cout<<BLUE"┌──────────────────────────────────────────────────────┐"<<endl;
                cout<<BLUE"│                   "<<YELLOW"Hasta la próxima"<<BLUE"                   │"<<endl;
                cout<<BLUE"└──────────────────────────────────────────────────────┘"<<RESET""<<endl;
                system("sleep 2");
                system("clear");
                fin = true;
            break;
            default:
                cout<<endl;
                cout<<RED"┌──────────────────────────────────────────────────────┐" << endl;
                cout<<RED"│                No es una opcion válida...            │" << endl;
                cout<<RED"└──────────────────────────────────────────────────────┘" <<RESET""<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        if(opcion!=4)
            system("sleep 2");
    }while(fin==false);
}
