//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_ITEM_H
#define PROYECTO_1_ITEM_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "dist/json.h"

using namespace std;

class Item { // Clase abstracta // Interfaz
    public:
        string id;

        string nombre;

        int precio;

        int traccion;

        int velocidad;

        int potencia;

        virtual ~Item() {}

        virtual string getId() = 0; // Metodo virtual puro

        virtual void setId(const string &id) = 0; // Metodo virtual puro

        virtual string getNombre() = 0; // Metodo virtual puro

        virtual void setNombre(const string &nombre) = 0; // Metodo virtual puro

        virtual int getPrecio() = 0; // Metodo virtual puro

        virtual void setPrecio(int precio) = 0; // Metodo virtual puro

        virtual int getTraccion() = 0; // Metodo virtual puro

        virtual void setTraccion(int traccion) = 0; // Metodo virtual puro

        virtual int getVelocidad() = 0; // Metodo virtual puro

        virtual void setVelocidad(int velocidad) = 0; // Metodo virtual puro

        virtual int getPotencia() = 0; // Metodo virtual puro

        virtual void setPotencia(int potencia) = 0; // Metodo virtual puro

        virtual bool getEstado() = 0;//Metodo Virtual puro

        virtual void setEstado(bool estado) = 0;

        virtual bool agregarDecorador(Item* decorador) = 0;

        virtual bool quitarDecorador(Item* decorador) = 0;

        virtual string toString() = 0; // Metodo virtual puro;

        virtual ostream& imprimir(ostream&) const = 0; // Metodo virtual puro necesario para el funcionamiento de la sobrecarga << en la
                                                       // relacion de herencia creada, se desarrollara en las subclases

        friend ostream &operator<<(ostream &os, const Item &item) { // Sobrecarga operador << que se aprovecha del metodo imprimir del item para mostrar la informacion en pantalla
            item.imprimir(os);
            return os;
        }

        virtual Item *cargaDatos(Json::Value objeto) = 0;  //Metodo virtual puro

        virtual Json::Value salvaDatos(Item* item) = 0; //Metodo virtual puro


};


#endif //PROYECTO_1_ITEM_H
