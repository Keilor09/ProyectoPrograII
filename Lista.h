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
            list << ">>No hay jugadores en list equipo \n";
        while (actual != nullptr){
            list << *actual;
            actual = actual->getSig();
        }
        return list.str();
    }

};


#endif //PROYECTO_1_LISTA_H
