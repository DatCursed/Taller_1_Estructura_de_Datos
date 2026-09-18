#include "Servicio.hpp"
#include <iostream>

using namespace std;

Servicio::Servicio() {
    nombreServicio = "";
}

Servicio::Servicio(const string& nombreServicio) {
    this->nombreServicio = nombreServicio;
}

Servicio::~Servicio() {
}

string Servicio::getNombreServicio() const {
    return nombreServicio;
}

void Servicio::setNombreServicio(const string& nombreServicio) {
    this->nombreServicio = nombreServicio;
}

List<Paciente>& Servicio::getListaPacientes() {
    return this->listaPacientes;
}

void Servicio::agregarPaciente(const Paciente& paciente) {
    this->listaPacientes.insertLast(paciente);
}

void Servicio::mostrarPacientes() {
    cout << "=== ESTADO " << nombreServicio << " ===" << endl;

    if (this->listaPacientes.empty()) {
        cout << "No hay pacientes en el departamento." << endl;
        return;
    }

    int i = 0;
    while (true) {
        try {
            Paciente p = this->listaPacientes.get(i);
            cout << p.getNombre() << " (" << p.getEdad() << ")" << endl;
            i++;
        } catch (...) {
            break;
        }
    }
}
