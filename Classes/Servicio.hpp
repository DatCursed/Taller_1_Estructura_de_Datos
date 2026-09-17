#pragma once

#include <string>
#include "Paciente.hpp"
#include "../data_structure/List.hpp"

using namespace std;

class Servicio {
private:
    string nombreServicio;
    List<Paciente> listaPacientes;

public:
    Servicio();
    Servicio(const string& nombreServicio);
    ~Servicio();

    string getNombreServicio() const;
    void setNombreServicio(const string& nombreServicio);

    List<Paciente>& getListaPacientes();
    void agregarPaciente(const Paciente& paciente);
    void mostrarPacientes();
};
