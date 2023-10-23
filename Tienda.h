//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_TIENDA_H
#define PROYECTO_1_TIENDA_H

#include "Item.h"

class Tienda : public Item { // Clase decorator
    protected:
        Item* ptrItem;

        bool estado;
    public:

        virtual double costo() = 0;

        bool getEstado() {
            return this->estado;
        }

        void setEstado(bool estado) {
            this->estado = estado;
        }

        virtual string getId()  = 0; // Metodo virtual puro

        virtual void setId(const string &id) = 0; // Metodo virtual puro

        virtual string getNombre() = 0; // Metodo virtual puro

        virtual void setNombre(const string &nombre) = 0; // Metodo virtual puro

        virtual int getPrecio()  = 0; // Metodo virtual puro

        virtual void setPrecio(int precio) = 0; // Metodo virtual puro

        virtual int getTraccion() = 0; // Metodo virtual puro

        virtual void setTraccion(int traccion) = 0; // Metodo virtual puro

        virtual int getVelocidad() = 0; // Metodo virtual puro

        virtual void setVelocidad(int velocidad) = 0; // Metodo virtual puro

        virtual int getPotencia() = 0; // Metodo virtual puro

        virtual void setPotencia(int potencia) = 0; // Metodo virtual puro

        virtual string toString() = 0; // Metodo virtual puro;

};


#endif //PROYECTO_1_TIENDA_H
