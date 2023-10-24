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
    return this->id;
}


void Motor::setId(const string &id)  {
    this->id = id;
}

string Motor::getNombre()  {
    return this->nombre;
}

void Motor::setNombre(const string &nombre)  {
    this->nombre = nombre;
}

int Motor::getPrecio()  {
    return this->precio;
}

void Motor::setPrecio(int precio)  {
    this->precio = precio;
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
    return this->potencia;
}

void Motor::setPotencia(int potencia)  {
    this->potencia = potencia;
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

string Motor::toStringMotor() {
    stringstream s;
    s << "Nombre: " << this->nombre << endl;
    s << "ID: " << this->id << endl;
    s << "Estado: " << this->estado << endl;
    s << "Potencia: " << this->potencia << endl;
    s << "Precio: " << this->precio << endl;
    return s.str();
}


void Motor::setEstado(bool estado) {
    this->estado = estado;
}

bool Motor::getEstado() {
    return estado;
}

Motor* Motor::cargaDatos(Json::Value objeto) {
    bool estado = objeto["estado"].asBool();
    string nombre = objeto["nombre"].asString();
    string id = objeto["id"].asString();
    int precio = objeto["precio"].asInt();
    int potencia = objeto["potencia"].asInt();
    Item* ptrItem = getPtrItem();

    return new Motor(ptrItem, estado, id, nombre, potencia, precio);
}

Json::Value Motor::salvaDatos(Motor* motor) {
    Json::Value event;
    event["estado"] = motor->getEstado();
    event["nombre"] = motor->getNombre();
    event["id"] = motor->getId();
    event["precio"] = motor->getPrecio();
    event["potencia"] = motor->getPotencia();

    return event;
}

Item* Motor::getPtrItem() {
    return this->ptrItem;
}

void Motor::setPtrItem(Item* ptrItem) {
    this->ptrItem = ptrItem;
}