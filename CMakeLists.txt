cmake_minimum_required(VERSION 3.26)
project(Proyecto_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_1 main.cpp
        Item.h
        Jugador.cpp
        Jugador.h
        Lista.h
        Nodo.h
        Tienda.h
        Vehiculo.cpp
        Vehiculo.h
        Nitro.cpp
        Nitro.h
        Llantas.cpp
        Llantas.h
        Motor.cpp
        Motor.h
        dist/json/json.h
        dist/jsoncpp.cpp
)
