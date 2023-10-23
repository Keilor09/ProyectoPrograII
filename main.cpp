#include <iostream>

using namespace std;

#include "Vehiculo.h"
#include "Tienda.h"
#include "Nitro.h"
#include "Llantas.h"
#include "Motor.h"

int main() {

    Vehiculo* veh = new Vehiculo("V1", "Ferrari 458 Italia Coupe", 15000, 21, 250, 562);

    cout << veh->toString() << endl;

    veh->agregarDecorador(new Nitro(veh, true, "N1", "Nitro basico", 1000, 10));

    cout << veh->toString() << endl;

    //Item* nitro = new Nitro(veh, true, "N1", "Nitro basico", 1000, 10);
    //Item* motor = new Motor(nitro, true, "M1", "motor intermedio", 25, 1700);
   // Item* llanta = new Llantas(motor, true, "LL1", "llanta AA alta traccion", 80, 2200);

   // cout << llanta->toString() << endl;
   // cout << "Costo total: " << llanta->costo() << endl;


    return 0;
}
