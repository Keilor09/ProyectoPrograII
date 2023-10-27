//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_LLANTAS_H
#define PROYECTO_1_LLANTAS_H

#include "Tienda.h"

class Llantas : public Tienda {
public:
    Llantas();

    Llantas(Item* ptrItem, bool estado, string id, string nombre, int traccion, int precio);

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

    bool agregarDecorador(Item* decorador);

    bool quitarDecorador(Item* decorador);

    string toString();

    bool getEstado();

    void setEstado(bool estado);

    Item *cargaDatos(Json::Value objeto);

    Json::Value salvaDatos(Item* llantas);

    Item* getPtrItem();

    void setPtrItem(Item*);

    friend ostream &operator<<(ostream &os, const Llantas &llantas);

    virtual ostream& imprimir(ostream&) const;



};


#endif //PROYECTO_1_LLANTAS_H
