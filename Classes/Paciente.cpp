#include "Paciente.hpp"
#include <iostream>

using namespace std;

Paciente::Paciente() {
    id = "";
    servicioDestino = "";
}

Paciente::Paciente(const string& id, const string& nombre, int edad, const string& servicioDestino) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicioDestino = servicioDestino;
}

Paciente::~Paciente() {
}

string Paciente::getId() const {
    return id;
}

string Paciente::getServicioDestino() const {
    return servicioDestino;
}

void Paciente::setId(const string& id) {
    this->id = id;
}

void Paciente::setServicioDestino(const string& servicioDestino) {
    this->servicioDestino = servicioDestino;
}

void Paciente::mostrarInformacion() const {
    cout << id << " - " << nombre;
}

