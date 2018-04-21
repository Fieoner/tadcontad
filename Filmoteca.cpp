/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"

Filmoteca::Filmoteca (string prop) {
	propietario = prop;
	Pelicula cabecera, centinela;
	cent = new NodoF(centinela);
	cab = new NodoF(cabecera, cent);
	cab->sig = cent;
}

Filmoteca::~Filmoteca () {
	if (cab->sig == cent){
		delete cab;
		delete cent;
	}
	else {
		pNodo aux, todel;
		todel = cab;
		aux = cab->sig;
		while (aux != cent){
			delete todel;
			todel = aux;
			aux = aux->sig;
		}
		delete todel;
		delete aux;
	}
}

bool Filmoteca::estaVacia () {
		bool vacia = false;
		if (cab->sig == cent) vacia = true;
		return vacia;
}

string Filmoteca::getPropietario () {
	return propietario;
}

void Filmoteca::setPropietario (string p) {
	propietario = p;
}

bool Filmoteca::insertarPelicula (Pelicula peli) {
	bool insertado = false;
	if (peli.tieneDatos() == false) return insertado;
	pNodo aux, link;
	aux = cab;
	if (this->estaVacia()){
		aux->sig = new NodoF(peli, cent);
	}
	else {
		int order;
		while (aux->sig != cent && insertado == false){
			order = aux->sig->info.getTitulo().compare(peli.getTitulo());
			if (order >= 0){
				if (order == 0) break;
				link = aux->sig;
				aux->sig = new NodoF(peli, link);
				insertado = true;
			}
			else {
				aux = aux->sig;
			}
			aux = aux->sig;
		}
	}
	return insertado;
}

bool Filmoteca::eliminarPelicula (string titulo) {
	bool eliminado = true;
	pNodo aux, todel;
	aux = cab;
	cent->info.setTitulo(titulo);
	if (this->estaVacia()){
		eliminado = false;
	}
	else {
		string cur = aux->sig->info.getTitulo();
		while (cur != titulo){
			aux = aux->sig;
		}
		if (aux->sig != cent){
			todel = aux->sig;
			aux->sig = aux->sig->sig;
			delete todel;
		}
		else {
			eliminado = false;
		}
	}
	return eliminado;
}

Pelicula Filmoteca::buscarPelicula (string t) {
}

void Filmoteca::mostrarFilmoteca () {
}

bool Filmoteca::guardarEnFichero (string f) {
}

void Filmoteca::recuperarDeFichero (string f) {
}
