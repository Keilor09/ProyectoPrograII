#include <iostream>

using namespace std;

#include "Vehiculo.h"
#include "Tienda.h"
#include "Nitro.h"
#include "Llantas.h"
#include "Motor.h"

int main() {

    Vehiculo* ptrVehiculo;
    Vehiculo* v1 = new Vehiculo("V1", "Ferrari 458 Italia Coupe", 15000, 21, 250, 562);
    Vehiculo* v2 = new Vehiculo("V2", "Tesla Model X", 17000, 22, 180, 670);
    Vehiculo* v3 = new Vehiculo("V3", "Maserati MC12 Stradale", 15000, 18, 255, 450);

    //cout << v1->toString() << endl;

    //v1->agregarDecorador(new Nitro(v1, true, "N1", "Nitro basico", 1000, 10));

    //cout << v1->toString() << endl;


    // prueba json

    Nitro* nitroPtr;
    Nitro* n1 = new Nitro(nullptr, true, "N1", "Nitro basico", 1000, 10);
    Nitro* n2 = new Nitro(nullptr, true, "N2", "Nitro intermedio", 1500, 20);
    Nitro* n3 = new Nitro(nullptr, true, "N3", "Nitro alto rendimiento", 2000, 30);


    Motor* ptrMotor;
    Motor* m1 = new Motor(nullptr, true, "M1", "motor intermedio", 25, 1700);
    Motor* m2 = new Motor(nullptr, true, "M2", "motor alto rendimiento", 50, 2300);


    Llantas* ptrLlanta;
    Llantas* l1 = new Llantas(nullptr, true, "LL1", "llanta AA alta traccion", 80, 2200);
    Llantas* l2 = new Llantas(nullptr, true, "LL2", "llanta B traccion normal", 45, 1100);
    Llantas* l3 = new Llantas(nullptr, true, "LL3", "llanta C traccion baja", -10, 600);

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
*/
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


    return 0;
}
