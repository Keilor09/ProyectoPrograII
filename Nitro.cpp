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

string Nitro::toStringNitro() {
    stringstream s;
    s << "Nombre: " << this->nombre << endl;
    s << "ID: " << this->id << endl;
    s << "Estado: " << this->estado << endl;
    s << "Velocidad: " << this->velocidad << endl;
    s << "Precio: " << this->precio << endl;
    return s.str();
}

void Nitro::setEstado(bool estado) {
    this->estado = estado;
}

bool Nitro::getEstado() {
    return estado;
}

Nitro* Nitro::cargaDatos(Json::Value objeto) {
    bool estado = objeto["estado"].asBool();
    string nombre = objeto["nombre"].asString();
    string id = objeto["id"].asString();
    int precio = objeto["precio"].asInt();
    int velocidad = objeto["velocidad"].asInt();
    Item* ptrItem = getPtrItem();

    return new Nitro(ptrItem, estado, id, nombre, precio, velocidad);
}

Json::Value Nitro::salvaDatos(Nitro* nitro) {
    Json::Value event;
    event["estado"] = nitro->getEstado();
    event["nombre"] = nitro->getNombre();
    event["id"] = nitro->getId();
    event["precio"] = nitro->getPrecio();
    event["velocidad"] = nitro->getVelocidad();

    return event;
}

Item* Nitro::getPtrItem() {
    return this->ptrItem;
}

void Nitro::setPtrItem(Item* ptrItem) {
    this->ptrItem = ptrItem;
}

ostream &operator<<(ostream &os, const Nitro &nitro) {
    os << "Nombre: " << nitro.nombre << endl;
    os << "ID: " << nitro.id << endl;
    os << "Estado: " << nitro.estado << endl;
    os << "Velocidad: " << nitro.velocidad << endl;
    os << "Precio: " << nitro.precio << endl;
    return os;
}


