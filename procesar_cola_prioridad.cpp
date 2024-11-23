#include <iostream>
#include <string>

struct Persona {
    char prioridad;
    std::string nombre;
    Persona* siguiente;
};

class Cola {
private:
    Persona* frente;
    Persona* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(char prioridad, const std::string& nombre) {
        Persona* nueva = new Persona;
        nueva->prioridad = prioridad;
        nueva->nombre = nombre;
        nueva->siguiente = nullptr;
        if (final == nullptr) {
            frente = final = nueva;
        } else {
            final->siguiente = nueva;
            final = nueva;
        }
    }

    void procesar() {
        Cola colaA, colaB, colaC, colaD;
        while (frente != nullptr) {
            Persona* temp = frente;
            frente = frente->siguiente;
            switch (temp->prioridad) {
                case 'A':
                    colaA.encolar(temp->prioridad, temp->nombre);
                    break;
                case 'B':
                    colaB.encolar(temp->prioridad, temp->nombre);
                    break;
                case 'C':
                    colaC.encolar(temp->prioridad, temp->nombre);
                    break;
                case 'D':
                    colaD.encolar(temp->prioridad, temp->nombre);
                    break;
                default:
                    std::cerr << "Prioridad desconocida: " << temp->prioridad << std::endl;
            }
            delete temp;
        }
        colaA.procesarCola();
        colaB.procesarCola();
        colaC.procesarCola();
        colaD.procesarCola();
    }

    void procesarCola() {
        while (frente != nullptr) {
            std::cout << "Procesando: " << frente->prioridad << " - " << frente->nombre << std::endl;
            Persona* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }
};

int main() {
    Cola cola;
    cola.encolar('B', "Daniel");
    cola.encolar('C', "Pablo");
    cola.encolar('D', "Coraline");
    cola.encolar('A', "Alfonzo");
    cola.encolar('C', "Lara");
    cola.encolar('A', "Paula");
    cola.encolar('A', "Chancho");
    cola.encolar('A', "Luz");

    std::cout << "Procesando la cola segun prioridades:" << std::endl;
    cola.procesar();

    return 0;
}
