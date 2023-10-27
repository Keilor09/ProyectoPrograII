//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_JUGADOR_H
#define PROYECTO_1_JUGADOR_H

#include <iostream>
#include "Lista.h"
#include "Vehiculo.h"

using namespace std;
class Jugador {
    private:
        string id;
        string nombre;
        int dineroDisponible;
        Lista<Item>* vehiculosDisponibles;
    public:
        Jugador(const string &id, const string &nombre, int dineroDisponible, Lista<Item>* listaVehiculos);

        Jugador();

        virtual ~Jugador();

        const string &getId() const;

        void setId(const string &id);

        const string &getNombre() const;

        void setNombre(const string &nombre);

        int getDineroDisponible() const;

        void setDineroDisponible(int dineroDisponible);

        Lista<Item>* getVehiculosDisponibles();

        void setVehiculosDisponibles(Lista<Item>*);

        friend ostream &operator<<(ostream &os, const Jugador &jugador);

        string toString();

};


#endif //PROYECTO_1_JUGADOR_H
