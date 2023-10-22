#include <iostream>

using namespace std;

#include "Vehiculo.h"
#include "Tienda.h"
#include "Nitro.h"
#include "Llantas.h"
#include "Motor.h"

int main() {

    Item* vehiculo = new Vehiculo("V1", "Ferrari 458 Italia Coupe", 15000, 21, 250, 562);

    cout << vehiculo->toString() << endl;

    Item* nitro = new Nitro(vehiculo, true, "N1", "Nitro basico", 1000, 10);
    nitro->aumentarVelocidad();
    nitro->aumentarPrecio();


    return 0;
}
