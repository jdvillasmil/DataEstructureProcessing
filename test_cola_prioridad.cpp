#include <iostream>
#include "cola_prioridad.h"

int main() {
    ColaPrioridad cola;
    cola.encolar("Tarea 1", 2);
    cola.encolar("Tarea urgente", 1);
    cola.encolar("Tarea 2", 3);

    std::cout << "Contenido de la cola de prioridad:" << std::endl;
    cola.mostrar();

    cola.desencolar();
    std::cout << "Despues de desencolar:" << std::endl;
    cola.mostrar();

    return 0;
}
