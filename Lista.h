//
// Created by keilo on 10/22/2023.
//

#ifndef PROYECTO_1_LISTA_H
#define PROYECTO_1_LISTA_H

#include "Nodo.h"

template<class tipo>
class Lista {
    private:
        Nodo<tipo> *raiz;
        Nodo<tipo>* actual;
        Nodo<tipo>* ultimo;

public:
    Lista() {
        raiz = nullptr;
    }
    ~Lista(){
        while (!listVacia()) {
            eliminaFinal();
        }
    }

    bool listVacia() {
        if (raiz == nullptr)
            return true;
        else
            return false;
    }

    void eliminaFinal(){
        Nodo<tipo>* actual = raiz;

        if (!listVacia()){
            if (raiz->getSig() == nullptr){
                delete raiz;
                raiz = nullptr;
            }
            else{
                while (actual->getSig()->getSig() != nullptr)
                    actual = actual->getSig();
                delete actual->getSig();
                actual->setSig(nullptr);
            }
        }
    }

    void coloFinal(tipo *datos) {
        Nodo<tipo>* actual = raiz;

        if (raiz == nullptr) {
            raiz = new Nodo<tipo>(datos, nullptr);
        }
        else{
            while (actual->getSig() != nullptr)
                actual = actual->getSig();
            actual->setSig(new Nodo<tipo>(datos, nullptr));
        }
    }


    string toString() {
        Nodo<tipo>* actual = raiz;
        stringstream list;

        if (listVacia())
            list << ">>No hay elementos en la lista \n";
        while (actual != nullptr){
            list << *actual;
            actual = actual->getSig();
        }
        return list.str();
    }

    tipo* getNodoActual () {
        return this->actual->getDat();
    }

    tipo* buscarId(const string& id) {
        Nodo<tipo>* actual = raiz;

        while (actual != nullptr) {
            if (actual->getDat()->getId() == id) {
                return actual->getDat();
            }

            actual = actual->getSig();
        }

        // Si no se encuentra la película, devuelve nullptr
        return nullptr;
    }

};


#endif //PROYECTO_1_LISTA_H
