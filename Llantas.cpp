//
// Created by keilo on 10/22/2023.
//

#include "Llantas.h"

Llantas::Llantas(Item* ptrItem, bool estado) {
    this->ptrItem = ptrItem;
    this->estado = estado;
}

string Llantas::getId()  {
    return this->ptrItem->getId();
}


void Llantas::setId(const string &id)  {
    this->ptrItem->setId(id);
}

string Llantas::getNombre()  {
    return this->ptrItem->getNombre();
}

void Llantas::setNombre(const string &nombre)  {
    this->ptrItem->setNombre(nombre);
}

int Llantas::getPrecio()  {
    return this->ptrItem->getPrecio();
}

void Llantas::setPrecio(int precio)  {
    this->ptrItem->setPrecio(precio);
}

int Llantas::getTraccion()  {
    return this->ptrItem->getTraccion();
}

void Llantas::setTraccion(int traccion)  {
    this->ptrItem->setTraccion(traccion);
}

int Llantas::getVelocidad()  {
    return this->ptrItem->getVelocidad();
}

void Llantas::setVelocidad(int velocidad)  {
    this->ptrItem->setVelocidad(velocidad);
}

int Llantas::getPotencia()  {
    return this->ptrItem->getPotencia();
}

void Llantas::setPotencia(int potencia)  {
    this->ptrItem->setPotencia(potencia);
}

void Llantas::aumentarPotencia() {

}

void Llantas::aumentarTraccion() {
    this->ptrItem->setTraccion(this->ptrItem->getTraccion() + this->traccion);
}

void Llantas::aumentarVelocidad() {

}

void Llantas::aumentarPrecio() {
    this->ptrItem->setPrecio(ptrItem->getPrecio() + this->precio);
}

string Llantas::toString() {
    stringstream s;
    s << this->ptrItem->toString() << endl;
    return s.str();
}