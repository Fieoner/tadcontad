/*
 *  PruebasFilmo.cpp
 *  Created on: 2/3/2015
 *  Author: carolina
 */

#include "Filmoteca.h"
#include "Pelicula.h"
#include <iostream>

using namespace std;

void validar (Pelicula p);
Pelicula pruebaConstructor1 ();
void pruebaConstructor4 ();
void pruebaConstructorString ();
void probarReparto (Pelicula &p);
void probarEliminarReparto (Pelicula &p);
void probarNoValido ();
void rellenarFilmoteca (Filmoteca &f);
void probarInsertar (Filmoteca &fi, Pelicula p);
void probarBuscarPelicula (Filmoteca &f);
void probarEliminar (Filmoteca &f);
void probarIncorrectos (Filmoteca &f);

int main () {

	string separador = "----------------------\n";
	Filmoteca film ("MiFilmoteca");
	Filmoteca film2016 ("Pelis del 2016");

	cout << "***********************************************" << endl;
	cout << "    PRUEBAS DE PELICULA" << endl;
	cout << "***********************************************" << endl;

	cout << "Prueba P1: Constructor Pelicula/0 " << endl;
	pruebaConstructor1 ();
	cout << separador << endl;

	cout << "Prueba P2: CONSTRUCTOR PELICULA/4" << endl;
	pruebaConstructor4 ();
	cout << separador << endl;

	cout << "Prueba P3: CONSTRUCTOR PELICULA/1" << endl;
	pruebaConstructorString ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba P4: REPARTO" << endl;
	cout << "-- Insertar --" << endl;
	Pelicula aux ("Cenicienta", "Almodovar", "animacion", 2015);
	probarReparto (aux);
	cout << "Pulse una tecla para continuar" << endl;
	cin.ignore (10, '\n');
	cin.get ();
	cout << "-- Eliminar --" << endl;
	probarEliminarReparto (aux);
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba P5: PELIS NO V�LIDAS" << endl;
	probarNoValido ();
	cout << separador << endl;

	cout << endl;
	cout << endl;

	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "***********************************************" << endl;
	cout << "    PRUEBAS DE FILMOTECA" << endl;
	cout << "***********************************************" << endl;

	cout << "Prueba F1. Mostrar una filmoteca vac�a" << endl;
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F2. Insertar en condiciones normales y mostrar filmoteca: " << endl;
	rellenarFilmoteca (film);
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F3. Insertar en condiciones excepcionales y mostrar filmoteca: " << endl;
	probarIncorrectos (film);
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F4. Eliminar peliculas y mostrar filmoteca: " << endl;
	probarEliminar (film);
	film.mostrarFilmoteca ();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F5. BUSCAR PELICULA: " << endl;
	probarBuscarPelicula (film);
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "***********************************************" << endl;
	cout << "    PRUEBAS CON FICHEROS  " << endl;
	cout << "***********************************************" << endl;

	cout << "Prueba F6. Guardar en fichero: " << endl;
	cout << "Guardado " + film.getPropietario () + "? " << film.guardarEnFichero (
			"catalogo") << endl;
	cout << separador << endl;

	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "Prueba F7. Recuperar de fichero: " << endl;
	film2016.recuperarDeFichero ("MiFilmotecaCatalogo.txt");

	cout << "---------------" << endl;

	film2016.mostrarFilmoteca ();
	cout << "Pulse una tecla para continuar" << endl;
	cin.get ();

	cout << "------ FIN --------" << endl;
	return 0;
}

////////////////////////////////////////////////////

void validar (Pelicula p) {
	cout << "Es peli ok \"" + p.getTitulo () + "\"? ";
	if (p.tieneDatos ()) {
		cout << "Yes" << endl;
		cout << p.aCadena () << endl;
	}
	else cout << "no" << endl;
}

Pelicula pruebaConstructor1 () {
	Pelicula p1;
	p1.setDirector ("Haneke");
	p1.setGenero ("comedia");
	p1.setTitulo ("Amor");
	p1.setFecha (2001);
	p1.insertarInterprete ("Trintignant");
	p1.insertarInterprete ("Emmanuelle Riva");
	p1.insertarInterprete ("Isabelle Huppert");
	p1.insertarInterprete ("William Shimell");
	p1.insertarInterprete ("Laurent Capelluto");
	p1.insertarInterprete ("Dinara Drukarova");
	validar (p1);
	return p1;
}

void pruebaConstructor4 () {
	Pelicula p1 ("Cenicienta", "Almodovar", "animacion", 2015);
	validar (p1);
}

void pruebaConstructorString () {
	Pelicula p1 ("Spotlight;Fulanito;Thriller;2016;");
	validar (p1);
	Pelicula p2 (
			"Dormir es un deporte;Indurain;documentales;1999;Wong;West;Zoidberg;DiMaggio;Leela;Dinara Drukarova;Laurent Capelluto;William Shimell;");
	validar (p2);
}

void insertarActor (Pelicula &p, string x) {
	bool exito = p.insertarInterprete (x);
	if (exito)
		cout << x + " insertado: YES" << endl;
	else cout << x + " insertado: NO" << endl;
}

void probarReparto (Pelicula &p) {
	insertarActor (p, "Doctor Zoidberg");
	insertarActor (p, "Billy West");
	insertarActor (p, "Turanga Leela");
	insertarActor (p, "Amy Wong");
	insertarActor (p, "Amy Wong");
	insertarActor (p, "John DiMaggio");
	insertarActor (p, "Franky DiMaggio");
	insertarActor (p, "Paul Newman");
	insertarActor (p, "Robert Redforf");
	insertarActor (p, "Dani Rovira");
	insertarActor (p, "C3PO");
	insertarActor (p, "Amaya Salamanca");
	cout << p.aCadena () << endl;
}

void eliminarActor (Pelicula &p, string x) {
	bool exito = p.eliminarInterprete (x);
	if (exito)
		cout << x + " eliminado: YES" << endl;
	else cout << x + " eliminado: NO" << endl;
}

void probarEliminarReparto (Pelicula &p) {
	eliminarActor (p, "Amy Wong");
	eliminarActor (p, "Doctor Zoidberg");
	eliminarActor (p, "Turanga Leela");
	eliminarActor (p, "Amaya Salamanca");
	cout << p.aCadena () << endl;
}

void probarInsertar (Filmoteca &fi, Pelicula p) {
	cout << "insertando" << endl;
	if (fi.insertarPelicula (p))
		cout << " - " + p.getTitulo () + " (" + p.getDirector ()
				+ "): INSERTADO" << endl;
	else cout << " - " + p.getTitulo () + " (" + p.getDirector ()
			+ "): NO INSERTADO" << endl;
}

void probarBuscarPelicula (Filmoteca &f) {
	Pelicula p = f.buscarPelicula ("Zoiberg");
	cout << p.aCadena () << endl;
	Pelicula p2 = f.buscarPelicula ("Yoga");
	cout << p2.aCadena () << endl;
}

void _probarEliminar (Filmoteca &fi, string t) {
	if (fi.eliminarPelicula (t))
		cout << " - " + t + ": ELIMINADA" << endl;
	else cout << " - " + t + ": NO ELIMINADA" << endl;
}

void probarEliminar (Filmoteca &f) {
	cout << "�ltima:" << endl;
	_probarEliminar (f, "Zoiberg el Robot");
	cout << "Primera:" << endl;
	_probarEliminar (f, "Azarosos");
	cout << "Medio: " << endl;
	_probarEliminar (f, "Kunfu");
	cout << "No existe: " << endl;
	_probarEliminar (f, "YYYYYYY");
}

void probarNoValido () {
	Pelicula sinTitulo;
	sinTitulo.setDirector ("Lazarillo de Tormes");
	validar (sinTitulo);
	Pelicula sinDire;
	sinDire.setTitulo ("Lo peor");
	validar (sinDire);
}

void rellenarFilmoteca (Filmoteca &f) {
	string ani = "animacion";
	string drama = "drama";
	string comedia = "comedia";
	string amor = "com. romantica";
	string docu = "documentales";
	Pelicula p = pruebaConstructor1 ();
	Pelicula p1 ("Cenicienta", "Almodovar", ani, 2015);
	Pelicula p2 ("Pinocho", "Bu�uel", drama, 1980);
	probarReparto (p2);
	Pelicula p3 ("Yoga", "Emir", drama, 2010);
	Pelicula p4 ("Kunfu", "Bruce Lee", comedia, 1989);
	Pelicula p5 ("Rambo", "Schwazzenegger", amor, 2001);
	Pelicula p6 ("Dormir es un deporte", "Indurain", docu, 1999);
	Pelicula p7 ("Azarosos", "Crowfunding", drama, 2006);
	Pelicula p8 ("Zoiberg el Robot", "C3PO", "sci fi", 2010);
	probarInsertar (f, p);
	probarInsertar (f, p7);
	cout << endl << endl << endl << "a insertar" << endl << endl;
	probarInsertar (f, p8);
	probarInsertar (f, p3);
	probarInsertar (f, p2);
	probarInsertar (f, p4);
	probarInsertar (f, p5);
	probarInsertar (f, p6);
	probarInsertar (f, p1);
}

void probarIncorrectos (Filmoteca &f) {
	// repetido
	Pelicula p1 ("Cenicienta", "Almodovar", "drama", 2015);
	probarInsertar (f, p1);
	// no valido
	Pelicula fantasma ("", "Almodovar", "drama", 1980);
	probarInsertar (f, fantasma);
}
