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

    tipo* buscarId(const string& id) {
        Nodo<tipo>* actual = raiz;

        while (actual != nullptr) {
            if (actual->getDat()->getId() == id) {
                return actual->getDat();
            }

            actual = actual->getSig();
        }

        return nullptr;
    }

    void eliminarNodoPorId(const string& id) {
        // Buscamos el nodo en la lista.
        Nodo<tipo>* actual = raiz;
        Nodo<tipo>* anterior = nullptr;
        while (actual != nullptr && actual->getDat()->getId() != id) {
            anterior = actual;
            actual = actual->getSig();
        }

        // Si el nodo no existe, devolvemos.
        if (actual == nullptr) {
            return;
        }

        // Si el nodo es el primero, actualizamos la raíz.
        if (actual == raiz) {
            raiz = actual->getSig();
        } else {
            // Eliminamos el nodo de la lista.
            anterior->setSig(actual->getSig());
        }

        // Eliminamos el nodo de forma segura.
        delete actual;
    }

};


#endif //PROYECTO_1_LISTA_H
