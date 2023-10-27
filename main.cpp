#include <iostream>

using namespace std;

#include "Vehiculo.h"
#include "Tienda.h"
#include "Nitro.h"
#include "Llantas.h"
#include "Motor.h"
#include "Jugador.h"

int main() {

    //Creando listas genericas para almacenar vehiculos y los decoradores
    Lista<Item>* listaVehiculos = new Lista<Item>;
    Lista<Item>* listaNitro = new Lista<Item>;
    Lista<Item>* listaLlantas = new Lista<Item>;
    Lista<Item>* listaMotor = new Lista<Item>;

    //Metodo para recuperar los datos del archivo de vehiculo y crear los vehiculos para luego agregarlos a la lista de  vehiculos
    ifstream entrada("archivoVehiculo.txt");
    Item* ptrItemVehiculo = new Vehiculo();
    Json::Value objeto;
    Json::Reader reader;
    reader.parse(entrada, objeto);

    for (int i = 0; i < objeto.size(); i++) {
        ptrItemVehiculo = ptrItemVehiculo->cargaDatos(objeto[i]);
        listaVehiculos->coloFinal(ptrItemVehiculo);
        entrada.close();
    }

    //Metodo para recuperar los datos del archivo de nitro y crear los vehiculos para luego agregarlos a la lista de nitro
    ifstream entradaNitro("archivoNitro.txt");
    Item* ptrItemNitro = new Nitro();
    Json::Value objetoNitro;
    Json::Reader readerNitro;
    reader.parse(entradaNitro, objetoNitro);

    for (int i = 0; i < objetoNitro.size(); i++) {
        ptrItemNitro = ptrItemNitro->cargaDatos(objetoNitro[i]);
        listaNitro->coloFinal(ptrItemNitro);
        entradaNitro.close();
    }

    //Metodo para recuperar los datos del archivo de motor y crear los vehiculos para luego agregarlos a la lista de motor
    ifstream entradaMotor("archivoMotor.txt");
    Item* ptrItemMotor = new Motor();
    Json::Value objetoMotor;
    Json::Reader readerMotor;
    reader.parse(entradaMotor, objetoMotor);

    for (int i = 0; i < objetoMotor.size(); i++) {
        ptrItemMotor = ptrItemMotor->cargaDatos(objetoMotor[i]);
        listaMotor->coloFinal(ptrItemMotor);
        entradaMotor.close();
    }

    //Metodo para recuperar los datos del archivo de llantas y crear los vehiculos para luego agregarlos a la lista de llantas
    ifstream entradaLlantas("archivoLlantas.txt");
    Item* ptrItemLlantas = new Llantas();
    Json::Value objetoLlantas;
    Json::Reader readerLlantas;
    reader.parse(entradaLlantas, objetoLlantas);

    for (int i = 0; i < objetoLlantas.size(); i++) {
        ptrItemLlantas = ptrItemLlantas->cargaDatos(objetoLlantas[i]);
        listaLlantas->coloFinal(ptrItemLlantas);
        entradaLlantas.close();
    }

    //Creacion del jugador 1 con sus atributos y la lista de vehiculos
    Jugador* jugador1 = new Jugador("1111", "Pepito", 5000, listaVehiculos);

    cout << "==========MOSTRANDO JUGADOR Y SUS VEHICULOS SIN MEJORAR==========" << endl;
    cout << *jugador1;

    // MEJORANDO VEHICULOS
    jugador1->getVehiculosDisponibles()->buscarId("V1")->agregarDecorador(listaLlantas->buscarId("LL1"));
    jugador1->getVehiculosDisponibles()->buscarId("V1")->agregarDecorador(listaMotor->buscarId("M2"));

    jugador1->getVehiculosDisponibles()->buscarId("V2")->agregarDecorador(listaNitro->buscarId("N3"));
    jugador1->getVehiculosDisponibles()->buscarId("V2")->agregarDecorador(listaLlantas->buscarId("LL3"));

    jugador1->getVehiculosDisponibles()->buscarId("V3")->agregarDecorador(listaMotor->buscarId("M1"));
    jugador1->getVehiculosDisponibles()->buscarId("V3")->agregarDecorador(listaNitro->buscarId("N1"));
    cout << "==========MOSTRANDO JUGADOR Y SUS VEHICULOS MEJORADOS==========" << endl;
    cout << *jugador1;

    // QUITANDO MEJORAS
    jugador1->getVehiculosDisponibles()->buscarId("V1")->quitarDecorador(listaLlantas->buscarId("LL1"));
    jugador1->getVehiculosDisponibles()->buscarId("V1")->quitarDecorador(listaMotor->buscarId("M2"));

    jugador1->getVehiculosDisponibles()->buscarId("V2")->quitarDecorador(listaNitro->buscarId("N3"));
    jugador1->getVehiculosDisponibles()->buscarId("V2")->quitarDecorador(listaLlantas->buscarId("LL3"));

    jugador1->getVehiculosDisponibles()->buscarId("V3")->quitarDecorador(listaMotor->buscarId("M1"));
    jugador1->getVehiculosDisponibles()->buscarId("V3")->quitarDecorador(listaNitro->buscarId("N1"));

    cout << "==========QUITANDO MEJORAS Y MOSTRANDO JUGADOR Y SUS VEHICULOS SIN LAS MEJORAS==========" << endl;
    cout << *jugador1;
    cout << "=================================================================" << endl;

    return 0;
}
