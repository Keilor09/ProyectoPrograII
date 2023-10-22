//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_VEHICULO_H
#define PROYECTO_1_VEHICULO_H

#include "Item.h"

class Vehiculo : public Item {
    public:
        Vehiculo(string id, string nombre, int precio, int traccion, int velocidad, int potencia);

        virtual ~Vehiculo();

        virtual string getId();

        virtual void setId(const string &id);

        virtual string getNombre();

        virtual void setNombre(const string &nombre);

        virtual int getPrecio();

        virtual void setPrecio(int precio);

        virtual int getTraccion();

        virtual void setTraccion(int traccion);

        virtual int getVelocidad();

        virtual void setVelocidad(int velocidad);

        virtual int getPotencia();

        virtual void setPotencia(int potencia);

        virtual string toString();

        virtual void aumentarPotencia();

        virtual void aumentarTraccion();

        virtual void aumentarVelocidad();

        virtual void aumentarPrecio();

};


#endif //PROYECTO_1_VEHICULO_H
