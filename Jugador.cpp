//
// Created by keilo on 10/22/2023.
//

#include "Jugador.h"

Jugador::Jugador(const string &id, const string &nombre, float dineroDisponible, Lista<Vehiculo>* vehiculosDisponibles) : id(id), nombre(nombre),
dineroDisponible(dineroDisponible), vehiculosDisponibles(new Lista<Vehiculo>()){}

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

float Jugador::getDineroDisponible() const {
    return dineroDisponible;
}

void Jugador::setDineroDisponible(float dineroDisponible) {
    Jugador::dineroDisponible = dineroDisponible;
}

Lista<Vehiculo>* Jugador::getVehiculosDisponibles() {
    return this->vehiculosDisponibles;
}

void Jugador::setVehiculosDisponibles(Lista<Vehiculo>* lista) {
    this->vehiculosDisponibles = lista;
}