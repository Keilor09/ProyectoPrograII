//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_NODO_H
#define PROYECTO_1_NODO_H

#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;
template<class tipo>
class Nodo {

private:
    tipo *dat;
    Nodo *sig;
public:
    Nodo(){
        dat = nullptr;
        sig = nullptr;
    }

    Nodo(tipo *dato, Nodo *suguiente) : dat(dato), sig(suguiente) {}


    tipo *getDat() const{
        return dat;
    }
    void setDat(tipo *datos){
        dat = datos;
    }

    Nodo *getSig() const {
        return sig;
    }
    void setSig(Nodo *siguiente) {
        Nodo::sig = siguiente;
    }

    friend ostream &operator<<(ostream &os, const Nodo &nodo) { //esto lo genera directamente CLion
        os << "[DATO]: " << *nodo.dat << "\n";
        return os;
    }

};


#endif //PROYECTO_1_NODO_H
