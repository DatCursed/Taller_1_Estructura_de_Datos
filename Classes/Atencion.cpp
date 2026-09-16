#include "Atencion.hpp"
#include <iostream>
//using namespace std;

Atencion::Atencion() { 
  idPaciente = ""; 
  nombrePaciente = ""; 
  edadPaciente = 0; 
  servicio = ""; 
}


Atencion::Atencion(const Paciente& paciente) { 
  idPaciente = paciente.getId(); 
  nombrePaciente = paciente.getNombre(); 
  edadPaciente = paciente.getEdad(); 
  servicio = paciente.getServicioDestino(); 
}


Atencion::Atencion(const std::string& id, const std::string& nombre, int edad, const std::string& servicio) { 
  idPaciente = id; 
  nombrePaciente = nombre; 
  edadPaciente = edad; 
  this->servicio = servicio; 
}

Atencion::~Atencion() { }

std::string Atencion::getIdPaciente() const { return idPaciente; }
std::string Atencion::getNombrePaciente() const { return nombrePaciente; }
int Atencion::getEdadPaciente() const { return edadPaciente; }
std::string Atencion::getServicio() const { return servicio; }

void Atencion::mostrarDetalle() const {
    std::cout << "Nombre: " << nombrePaciente << " | Edad: " << edadPaciente << " | Departamento: " << servicio << "\n";
}
