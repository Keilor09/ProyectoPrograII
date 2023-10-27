//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_VEHICULO_H
#define PROYECTO_1_VEHICULO_H

#include "Item.h"
#include "Motor.h"
#include "Llantas.h"
#include "Nitro.h"
#include "Lista.h"
#include <fstream>
#include "dist/json.h"

class Vehiculo : public Item {
    private:
        Lista<Item>* listaDecoradores;
    public:
        Vehiculo();

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

        virtual bool getEstado();//Metodo Virtual puro

        virtual void setEstado(bool estado);

        bool agregarDecorador(Item* decorador);

        bool quitarDecorador(Item* decorador);

        Item *cargaDatos(Json::Value objeto);

        Json::Value salvaDatos(Item* vehiculo);

        friend ostream &operator<<(ostream &os, const Vehiculo &vehiculo);

        virtual ostream& imprimir(ostream& os) const;

        virtual string toString();

};


#endif //PROYECTO_1_VEHICULO_H
