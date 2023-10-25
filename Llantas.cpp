//
// Created by keilo on 10/22/2023.
//

#include "Llantas.h"

Llantas::Llantas(Item* ptrItem, bool estado, string id, string nombre, int traccion, int precio) {
    this->ptrItem = ptrItem;
    this->estado = estado;
    this->id = id;
    this->nombre = nombre;
    this->traccion = traccion;
    this->precio = precio;
}

string Llantas::getId()  {
    return this->id;
}

void Llantas::setId(const string &id)  {
    this->id = id;
}

string Llantas::getNombre()  {
    return this->nombre;
}

void Llantas::setNombre(const string &nombre)  {
    this->nombre = nombre;
}

int Llantas::getPrecio()  {
    return this->precio;
}

void Llantas::setPrecio(int precio)  {
    this->precio = precio;
}

int Llantas::getTraccion()  {
    return this->traccion;
}

void Llantas::setTraccion(int traccion)  {
    this->traccion = traccion;
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

int Llantas::costo() {
    return this->ptrItem->costo() + this->precio;
}

string Llantas::toString() {
    stringstream s;
    s << this->ptrItem->toString() << endl;
    s << this->nombre << ": " << this->precio << endl;
    return s.str();
}

string Llantas::toStringLlantas() {
    stringstream s;
    s << "Nombre: " << this->nombre << endl;
    s << "ID: " << this->id << endl;
    s << "Estado: " << this->estado << endl;
    s << "Traccion: " << this->traccion << endl;
    s << "Precio: " << this->precio << endl;
    return s.str();
}


void Llantas::setEstado(bool estado) {
    this->estado = estado;
}

bool Llantas::getEstado() {
    return estado;
}

Llantas* Llantas::cargaDatos(Json::Value objeto) {
    bool estado = objeto["estado"].asBool();
    string nombre = objeto["nombre"].asString();
    string id = objeto["id"].asString();
    int precio = objeto["precio"].asInt();
    int traccion = objeto["traccion"].asInt();
    Item* ptrItem = getPtrItem();

    return new Llantas(ptrItem, estado, id, nombre, traccion, precio);
}

Json::Value Llantas::salvaDatos(Llantas* llantas) {
    Json::Value event;
    event["estado"] = llantas->getEstado();
    event["nombre"] = llantas->getNombre();
    event["id"] = llantas->getId();
    event["precio"] = llantas->getPrecio();
    event["traccion"] = llantas->getTraccion();

    return event;
}

Item* Llantas::getPtrItem() {
    return this->ptrItem;
}

void Llantas::setPtrItem(Item* ptrItem) {
    this->ptrItem = ptrItem;
}

ostream &operator<<(ostream &os, const Llantas &llantas) {
    os << "Nombre: " << llantas.nombre << endl;
    os << "ID: " << llantas.id << endl;
    os << "Estado: " << llantas.estado << endl;
    os << "Traccion: " << llantas.traccion << endl;
    os << "Precio: " << llantas.precio << endl;
    return os;
}
