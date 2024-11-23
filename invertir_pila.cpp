#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* cima;

public:
    Pila() : cima(nullptr) {}

    void apilar(int valor) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    int desapilar() {
        if (cima == nullptr) {
            std::cerr << "Error: la pila esta vacia." << std::endl;
            exit(EXIT_FAILURE);
        }
        int valor = cima->dato;
        Nodo* temp = cima;
        cima = cima->siguiente;
        delete temp;
        return valor;
    }

    bool estaVacia() const {
        return cima == nullptr;
    }

    void invertir() {
        Pila pilaAuxiliar;
        while (!estaVacia()) {
            pilaAuxiliar.apilar(desapilar());
        }
        *this = pilaAuxiliar;
    }

    void mostrar() const {
        Nodo* actual = cima;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

int main() {
    Pila pila;
    pila.apilar(1);
    pila.apilar(2);
    pila.apilar(3);
    pila.apilar(4);

    std::cout << "Pila original: ";
    pila.mostrar();

    pila.invertir();

    std::cout << "Pila invertida: ";
    pila.mostrar();

    return 0;
}
