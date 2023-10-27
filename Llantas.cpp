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

bool Llantas::agregarDecorador(Item* decorador) {

}

bool Llantas::quitarDecorador(Item* decorador) {

}

string Llantas::toString() {
    stringstream s;
    s << this->ptrItem->toString() << endl;
    s << this->nombre << ": " << this->precio << endl;
    return s.str();
}

void Llantas::setEstado(bool estado) {
    this->estado = estado;
}

bool Llantas::getEstado() {
    return estado;
}

Item* Llantas::cargaDatos(Json::Value objeto) {
    bool estado = objeto["estado"].asBool();
    string nombre = objeto["nombre"].asString();
    string id = objeto["id"].asString();
    int precio = objeto["precio"].asInt();
    int traccion = objeto["traccion"].asInt();
    Item* ptrItem = getPtrItem();

    return new Llantas(ptrItem, estado, id, nombre, traccion, precio);
}

Json::Value Llantas::salvaDatos(Item* llantas) {
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

ostream& Llantas::imprimir(ostream& os) const {
    os << "Nombre: " << nombre << endl;
    os << "ID: " << id << endl;
    os << "Estado: " << endl;
    if (estado) {
        os << "Ocupado" << endl;
    }
    else {
        os << "Libre" << endl;
    }
    os << "Traccion: " << traccion << endl;
    os << "Precio: " << precio << endl;
    return os;
}

ostream &operator<<(ostream &os, const Llantas &llantas) {
    llantas.imprimir(os);
    return os;
}

Llantas::Llantas() {}
