//
// Created by secod on 01-09-2026.
//

#include "Paciente.hpp"
#include "Paciente.hpp"
#include <iostream>

Paciente::Paciente() : Persona(), id(""), servicioDestino("") {}

Paciente::Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& servicioDestino)
    : Persona(nombre, edad), id(id), servicioDestino(servicioDestino) {}

Paciente::~Paciente() {}

std::string Paciente::getId() const {
    return id;
}

std::string Paciente::getServicioDestino() const {
    return servicioDestino;
}

void Paciente::setId(const std::string& id) {
    this->id = id;
}

void Paciente::setServicioDestino(const std::string& servicioDestino) {
    this->servicioDestino = servicioDestino;
}

void Paciente::mostrarInformacion() const {
    std::cout << id << " - " << nombre;
}
