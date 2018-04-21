/*
 * Pelicula.h
 *
 *  Created on: 24/2/2016
 *      Author: carolina
 */

#include <sstream>
#include <iostream>

using namespace std;

#ifndef NODOINTERPRETE_H_
#define NODOINTERPRETE_H_

class NodoInterprete {

public:
	string interprete;
	NodoInterprete *sig;

	NodoInterprete (string aux) {
		interprete = aux;
		sig = NULL;
	}

	NodoInterprete (string aux, NodoInterprete *n) {
		interprete = aux;
		sig = n;
	}
};

#endif /* NODOINTERPRETE_H_ */

#ifndef PELICULA_H_
#define PELICULA_H_

	typedef NodoInterprete *pInter;

class Pelicula {
public:
	Pelicula();
	Pelicula (string t, string d, string gen, int f);
	Pelicula (string lineaFichero);

	~Pelicula();


	string getTitulo();
	void setTitulo(string titulo);

	string getDirector();
	void setDirector(string d);

	string getGenero();
	void setGenero(string genero);

	int getFecha();
	void setFecha(int a);

	string aCadena();
	string formatoFichero();

	bool tieneDatos();

	bool insertarInterprete (string actor);
	bool eliminarInterprete (string actor);
	string getListaInterpretes ();

private:
	string titulo;
	string director;
	string genero;
	int    fecha;
	pInter interpretes;
	int    numInters;
};

#endif /* PELICULA_H_ */
