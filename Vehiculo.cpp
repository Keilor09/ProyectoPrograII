//
// Created by keilo on 10/22/2023.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo(string id, string nombre, int precio, int traccion, int velocidad, int potencia) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->traccion = traccion;
    this->velocidad = velocidad;
    this->potencia = potencia;
    this->listaDecoradores = new Lista<Item>();
}

Vehiculo::~Vehiculo() {

}

string Vehiculo::getId() {
    return this->id;
}

void Vehiculo::setId(const string &id) {
    this->id = id;
}

string Vehiculo::getNombre() {
    return this->nombre;
}

void Vehiculo::setNombre(const string &nombre) {
    this->nombre = nombre;
}

int Vehiculo::getPrecio() {
    return this->precio;
}

void Vehiculo::setPrecio(int precio) {
    this->precio = precio;
}

int Vehiculo::getTraccion() {
    return this->traccion;
}

void Vehiculo::setTraccion(int traccion) {
    this->traccion = traccion;
}

int Vehiculo::getVelocidad() {
    return this->velocidad;
}

void Vehiculo::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

int Vehiculo::getPotencia() {
    return this->potencia;
}

void Vehiculo::setPotencia(int potencia) {
    this->potencia = potencia;
}

int Vehiculo::costo() {
    return this->precio;
}

void Vehiculo::agregarDecorador(Item* decorador) {
    this->listaDecoradores->coloFinal(decorador);

    if (decorador->getId() == "M1" || decorador->getId() == "M2") {
        this->setPotencia(this->getPotencia() + decorador->getPotencia());
        this->setPrecio(this->costo() + decorador->getPrecio());
    }
    else {
        if (decorador->getId() == "LL1" || decorador->getId() == "LL2" || decorador->getId() == "LL3") {
            this->setTraccion(this->getTraccion() + decorador->getTraccion());
            this->setPrecio(this->costo() + decorador->getPrecio());
        }
        else {
            if (decorador->getId() == "N1" || decorador->getId() == "N2" || decorador->getId() == "N3") {
                this->setVelocidad(this->getVelocidad() + decorador->getVelocidad());
                this->setPrecio(this->costo() + decorador->getPrecio());
            }
        }
    }
}


string Vehiculo::toString() {
    stringstream s;
    s << "Vehiculo: " << this->nombre << endl;
    s << "ID: " << this->id << endl;
    s << "Precio: " << this->costo() << endl;
    s << "Traccion: " << this->traccion << endl;
    s << "Velocidad: " << this->velocidad << endl;
    s << "Potencia: " << this->potencia << endl;
    return s.str();
}






