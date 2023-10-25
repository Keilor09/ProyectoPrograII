#include <iostream>

using namespace std;

#include "Vehiculo.h"
#include "Tienda.h"
#include "Nitro.h"
#include "Llantas.h"
#include "Motor.h"
#include "Jugador.h"

int main() {

    Item* v1 = new Vehiculo("V1", "Ferrari 458 Italia Coupe", 15000, 21, 250, 562);
    Item* v2 = new Vehiculo("V2", "Tesla Model X", 17000, 22, 180, 670);
    Item* v3 = new Vehiculo("V3", "Maserati MC12 Stradale", 15000, 18, 255, 450);

    Lista<Item>* listaVehiculos = new Lista<Item>;
    listaVehiculos->coloFinal(v1);
    listaVehiculos->coloFinal(v2);
    listaVehiculos->coloFinal(v3);

    cout << listaVehiculos->toString();

    Item* n1 = new Nitro(nullptr, false, "N1", "Nitro basico", 1000, 10);
    Item* n2 = new Nitro(nullptr, false, "N2", "Nitro intermedio", 1500, 20);
    Item* n3 = new Nitro(nullptr, false, "N3", "Nitro alto rendimiento", 2000, 30);

    Item* m1 = new Motor(nullptr, false, "M1", "motor intermedio", 25, 1700);
    Item* m2 = new Motor(nullptr, false, "M2", "motor alto rendimiento", 50, 2300);

    Item* l1 = new Llantas(nullptr, false, "LL1", "llanta AA alta traccion", 80, 2200);
    Item* l2 = new Llantas(nullptr, false, "LL2", "llanta B traccion normal", 45, 1100);
    Item* l3 = new Llantas(nullptr, false, "LL3", "llanta C traccion baja", -10, 600);

    cout << "Lista de vehiculos" << endl;
    cout << *v1 << endl;
    cout << "========================" << endl;


    v1->agregarDecorador(l1);
    v1->agregarDecorador(m2);

    cout << "Vehiculo 1" << endl;
    cout << *v1 << endl;
    cout << "========================" << endl;

    v2->agregarDecorador(n3);
    v2->agregarDecorador(l3);

    cout << "Vehiculo 2" << endl;
    cout << *v2 << endl;
    cout << "========================" << endl;

    v3->agregarDecorador(m1);
    v3->agregarDecorador(n1);

    cout << "Vehiculo 3" << endl;
    cout << *v3 << endl;
    cout << "========================" << endl;

    v1->quitarDecorador(l1);
    v1->quitarDecorador(m2);

    v2->quitarDecorador(n3);
    v2->quitarDecorador(l3);

    v3->quitarDecorador(m1);
    v3->quitarDecorador(n1);

    cout << listaVehiculos->toString();

/*
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "  ";

    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    ofstream salida("archivoVehiculo.txt");

    Json::Value event;
    Json::Value arreglo(Json::arrayValue);

    arreglo.append(ptrVehiculo->salvaDatos(v1));
    arreglo.append(ptrVehiculo->salvaDatos(v2));
    arreglo.append(ptrVehiculo->salvaDatos(v3));

    writer->write(arreglo, &salida);
    salida.close();

    ifstream entrada("archivoVehiculo.txt");

    Json::Value objeto;
    Json::Reader reader;
    reader.parse(entrada, objeto);

    for (int i = 0; i < objeto.size(); i++) {
        ptrVehiculo = ptrVehiculo->cargaDatos(objeto[i]);
        cout << ptrVehiculo->toStringVehiculo() << endl;
        entrada.close();
    }

    delete n1;
    delete n2;
    delete n3;
    delete n1;
    delete n2;
    delete l1;
    delete l2;
    delete l3;
    delete v1;
    delete v2;
    delete v3;
*/

    return 0;
}
