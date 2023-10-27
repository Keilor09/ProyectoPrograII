//
// Created by keilo on 10/22/2023.
//

#include "Jugador.h"

Jugador::Jugador(const string &id, const string &nombre, int dineroDisponible, Lista<Item>* listaVehiculos) : id(id), nombre(nombre),
dineroDisponible(dineroDisponible), vehiculosDisponibles(listaVehiculos){}

Jugador::Jugador() {
    id = "";
    nombre = "";
    dineroDisponible = 0.0;
    vehiculosDisponibles = NULL;
}


Jugador::~Jugador() {

}

const string &Jugador::getId() const {
    return id;
}

void Jugador::setId(const string &id) {
    Jugador::id = id;
}

const string &Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string &nombre) {
    Jugador::nombre = nombre;
}

int Jugador::getDineroDisponible() const {
    return dineroDisponible;
}

void Jugador::setDineroDisponible(int dineroDisponible) {
    Jugador::dineroDisponible = dineroDisponible;
}

Lista<Item>* Jugador::getVehiculosDisponibles() {
    return this->vehiculosDisponibles;
}

void Jugador::setVehiculosDisponibles(Lista<Item>* lista) {
    this->vehiculosDisponibles = lista;
}

ostream &operator<<(ostream &os, const Jugador &jugador) {
    os << "ID: " << jugador.id << endl;
    os << "Nombre: " << jugador.nombre << endl;
    os << "Dinero disponible: " << jugador.dineroDisponible << endl;
    os << "Vehiculos obtenidos: " << endl;
    os << endl;
    os << jugador.vehiculosDisponibles->toString() << endl;
    return os;
}

string Jugador::toString() {
    stringstream s;
    s << "ID: " << this->id << endl;
    s << "Nombre: " << this->nombre << endl;
    s << "Dinero disponible: " << this->dineroDisponible << endl;
    s << "Vehiculos disponibles:" << endl;
    s << endl;
    s << vehiculosDisponibles->toString() << endl;

    return s.str();
}


