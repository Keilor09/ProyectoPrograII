//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_NITRO_H
#define PROYECTO_1_NITRO_H

#include "Tienda.h"

class Nitro : public Tienda {
    public:

    Nitro(Item* ptrItem, bool estado, string id, string nombre, int precio, int velocidad);

    string getId() ; // Metodo virtual puro

    void setId(const string &id); // Metodo virtual puro

    string getNombre() ; // Metodo virtual puro

    void setNombre(const string &nombre); // Metodo virtual puro

    int getPrecio() ; // Metodo virtual puro

    void setPrecio(int precio); // Metodo virtual puro

    int getTraccion() ; // Metodo virtual puro

    void setTraccion(int traccion); // Metodo virtual puro

    int getVelocidad() ; // Metodo virtual puro

    void setVelocidad(int velocidad); // Metodo virtual puro

    int getPotencia(); // Metodo virtual puro

    void setPotencia(int potencia); // Metodo virtual puro

    bool getEstado();//Metodo Virtual puro

    void setEstado(bool estado);

    bool agregarDecorador(Item* decorador);

    bool quitarDecorador(Item* decorador);

    string toString(); // Metodo virtual puro;

    Nitro *cargaDatos(Json::Value objeto);

    Json::Value salvaDatos(Nitro* nitro);

    Item* getPtrItem();

    void setPtrItem(Item*);

    friend ostream &operator<<(ostream &os, const Nitro &nitro);

    virtual ostream& imprimir(ostream& os) const;

};


#endif //PROYECTO_1_NITRO_H
