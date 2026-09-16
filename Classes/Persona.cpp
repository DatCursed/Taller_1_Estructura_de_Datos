#include "Persona.hpp"
#include <iostream>
//using namespace std;

Persona::Persona() : nombre(""), edad(0) {}

Persona::Persona(const std::string& nombre, int edad)
    : nombre(nombre), edad(edad) {}

Persona::~Persona() {}

std::string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << " | Edad: " << edad;
