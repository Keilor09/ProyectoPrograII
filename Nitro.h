//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_NITRO_H
#define PROYECTO_1_NITRO_H

#include "Tienda.h"

class Nitro : public Tienda {
    public:
    Nitro();

    Nitro(Item* ptrItem, bool estado, string id, string nombre, int precio, int velocidad);

    string getId();

    void setId(const string &id);

    string getNombre();

    void setNombre(const string &nombre);

    int getPrecio();

    void setPrecio(int precio);

    int getTraccion();

    void setTraccion(int traccion);

    int getVelocidad();

    void setVelocidad(int velocidad);

    int getPotencia();

    void setPotencia(int potencia);

    bool getEstado();

    void setEstado(bool estado);

    bool agregarDecorador(Item* decorador);

    bool quitarDecorador(Item* decorador);

    string toString();

    Item *cargaDatos(Json::Value objeto);

    Json::Value salvaDatos(Item* nitro);

    Item* getPtrItem();

    void setPtrItem(Item*);

    friend ostream &operator<<(ostream &os, const Nitro &nitro);

    virtual ostream& imprimir(ostream& os) const;

};


#endif //PROYECTO_1_NITRO_H
