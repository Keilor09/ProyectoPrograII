//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_MOTOR_H
#define PROYECTO_1_MOTOR_H

#include "Tienda.h"

class Motor : public Tienda{
    public:

        Motor(Item* ptrItem, bool estado, string id, string nombre, int potencia, int precio);

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

        int costo();
    bool getEstado();//Metodo Virtual puro

    void setEstado(bool estado); //Metodo Virtual Puro

    string toString();

};


#endif //PROYECTO_1_MOTOR_H
