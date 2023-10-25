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

bool Vehiculo::getEstado() {

}

void Vehiculo::setEstado(bool estado) {

}

bool Vehiculo::agregarDecorador(Item* decorador) {
    if (!decorador->getEstado()) {
        decorador->setEstado(true);
        listaDecoradores->coloFinal(decorador);
        if (decorador->getId() == "M1" || decorador->getId() == "M2") {
            Item *motor = new Motor(this, decorador->getEstado(), decorador->getId(), decorador->getNombre(),
                                    decorador->getPotencia(), decorador->getPrecio());
            this->setPrecio(this->precio + decorador->getPrecio());
            this->setPotencia(this->potencia + decorador->getPotencia());
            return true;
        } else {
            if (decorador->getId() == "LL1" || decorador->getId() == "LL2" || decorador->getId() == "LL3") {
                Item *llanta = new Llantas(this, decorador->getEstado(), decorador->getId(), decorador->getNombre(),
                                           decorador->getTraccion(), decorador->getPrecio());
                this->setPrecio(this->precio + decorador->getPrecio());
                this->setTraccion(this->traccion + decorador->getTraccion());
                return true;
            } else {
                Item *nitro = new Nitro(this, decorador->getEstado(), decorador->getId(), decorador->getNombre(),
                                        decorador->getPrecio(), decorador->getVelocidad());
                this->setPrecio(this->precio + decorador->getPrecio());
                this->setVelocidad(this->velocidad + decorador->getVelocidad());
                return true;
            }
        }
    } else {
        return false;
    }
}

Vehiculo * Vehiculo::cargaDatos(Json::Value objeto) {
    string id = objeto["id"].asString();
    string nombre = objeto["nombre"].asString();
    int precio = objeto["precio"].asInt();
    int traccion = objeto["traccion"].asInt();
    int velocidad = objeto["velocidad"].asInt();
    int potencia = objeto["potencia"].asInt();

    return new Vehiculo(id, nombre, precio, traccion, velocidad, potencia);
}

Json::Value Vehiculo::salvaDatos(Vehiculo* vehiculo) {
    Json::Value event;
    event["id"] = vehiculo->getId();
    event["nombre"] = vehiculo->getNombre();
    event["precio"] = vehiculo->getPrecio();
    event["traccion"] = vehiculo->getTraccion();
    event["velocidad"] = vehiculo->getVelocidad();
    event["potencia"] = vehiculo->getPotencia();

    return event;
}

ostream& Vehiculo::imprimir(ostream& os) const{
    os << "Vehiculo: " << nombre << endl;
    os << "ID: " << id << endl;
    os << "Precio: " << precio << endl;
    os << "Traccion: " << traccion << endl;
    os << "Velocidad: " << velocidad << endl;
    os << "Potencia: " << potencia << endl;
    os << "Mejoras: " << endl << endl;
    os << listaDecoradores->toString() << endl;
    return os;
}

ostream &operator<<(ostream &os, const Vehiculo &vehiculo) {
    vehiculo.imprimir(os);
    return os;
}


string Vehiculo::toString() {
    stringstream s;
    s << "Vehiculo: " << this->nombre << endl;
    s << "ID: " << this->id << endl;
    s << "Precio: " << this->precio << endl;
    s << "Traccion: " << this->traccion << endl;
    s << "Velocidad: " << this->velocidad << endl;
    s << "Potencia: " << this->potencia << endl;
    s << listaDecoradores->toString();
    return s.str();
}








