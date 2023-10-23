//
// Created by keilo on 10/22/2023.
//

#include "Nitro.h"

Nitro::Nitro(Item* ptrItem, bool estado, string id, string nombre, int precio, int velocidad) {
    this->ptrItem = ptrItem;
    this->estado = estado;
    this->nombre = nombre;
    this->id = id;
    this->precio = precio;
    this->velocidad = velocidad;
}

string Nitro::getId()  {
    return this->id;
}


void Nitro::setId(const string &id)  {
    this->id = id;
}

string Nitro::getNombre()  {
    return this->nombre;
}

void Nitro::setNombre(const string &nombre)  {
    this->nombre = nombre;
}

int Nitro::getPrecio()  {
    return this->precio;
}

void Nitro::setPrecio(int precio)  {
    this->precio = precio;
}

int Nitro::getTraccion()  {
    return this->ptrItem->getTraccion();
}

void Nitro::setTraccion(int traccion)  {
    this->ptrItem->setTraccion(traccion);
}

int Nitro::getVelocidad()  {
    return this->velocidad;
}

void Nitro::setVelocidad(int velocidad)  {
    this->velocidad =  velocidad;
}

int Nitro::getPotencia()  {
    return this->ptrItem->getPotencia();
}

void Nitro::setPotencia(int potencia)  {
    this->ptrItem->setPotencia(potencia);
}

int Nitro::costo() {
    return this->ptrItem->costo() + this->precio;
}

string Nitro::toString() {
    stringstream s;
    s << this->ptrItem->toString() << endl;
    s << this->nombre << ": " << this->precio << endl;
    return s.str();
}



