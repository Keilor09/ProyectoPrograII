//
// Created by keilo on 10/22/2023.
//

#include "Motor.h"

Motor::Motor(Item* ptrItem, bool estado, string id, string nombre, int potencia, int precio) {
    this->ptrItem = ptrItem;
    this->estado = estado;
    this->id = id;
    this->nombre = nombre;
    this->potencia = potencia;
    this->precio = precio;
}

string Motor::getId()  {
    return this->ptrItem->getId();
}


void Motor::setId(const string &id)  {
    this->ptrItem->setId(id);
}

string Motor::getNombre()  {
    return this->ptrItem->getNombre();
}

void Motor::setNombre(const string &nombre)  {
    this->ptrItem->setNombre(nombre);
}

int Motor::getPrecio()  {
    return this->ptrItem->getPrecio();
}

void Motor::setPrecio(int precio)  {
    this->ptrItem->setPrecio(precio);
}

int Motor::getTraccion()  {
    return this->ptrItem->getTraccion();
}

void Motor::setTraccion(int traccion)  {
    this->ptrItem->setTraccion(traccion);
}

int Motor::getVelocidad()  {
    return this->ptrItem->getVelocidad();
}

void Motor::setVelocidad(int velocidad)  {
    this->ptrItem->setVelocidad(velocidad);
}

int Motor::getPotencia()  {
    return this->ptrItem->getPotencia();
}

void Motor::setPotencia(int potencia)  {
    this->ptrItem->setPotencia(potencia);
}

int Motor::costo() {
    return this->ptrItem->costo() + this->precio;
}

string Motor::toString() {
    stringstream s;
    s << this->ptrItem->toString() << endl;
    s << this->nombre << ": " << this->precio << endl;
    return s.str();
}
void Motor::setEstado(bool estado) {
    this->estado = estado;
}
bool Motor::getEstado() {
    return estado;
}
