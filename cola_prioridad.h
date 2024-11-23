#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H

#include <iostream>
#include <string>

struct Nodo {
    std::string dato;
    int prioridad;
    Nodo* siguiente;
};

class ColaPrioridad {
private:
    Nodo* frente;

public:
    ColaPrioridad() : frente(nullptr) {}

    void encolar(const std::string& dato, int prioridad) {
        Nodo* nuevo = new Nodo;
        nuevo->dato = dato;
        nuevo->prioridad = prioridad;
        nuevo->siguiente = nullptr;

        if (frente == nullptr || prioridad < frente->prioridad) {
            nuevo->siguiente = frente;
            frente = nuevo;
        } else {
            Nodo* temp = frente;
            while (temp->siguiente != nullptr && temp->siguiente->prioridad <= prioridad) {
                temp = temp->siguiente;
            }
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    void desencolar() {
        if (frente == nullptr) {
            std::cout << "La cola está vacía." << std::endl;
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }

    std::string obtenerFrente() const {
        if (frente == nullptr) {
            throw std::runtime_error("La cola esta vacia.");
        }
        return frente->dato;
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    void mostrar() const {
        Nodo* temp = frente;
        while (temp != nullptr) {
            std::cout << "Dato: " << temp->dato << ", Prioridad: " << temp->prioridad << std::endl;
            temp = temp->siguiente;
        }
    }

    ~ColaPrioridad() {
        while (frente != nullptr) {
            desencolar();
        }
    }
};

#endif