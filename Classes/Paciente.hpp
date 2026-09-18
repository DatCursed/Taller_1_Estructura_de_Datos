#pragma once

#include "Persona.hpp"
#include <string>

using namespace std;

class Paciente : public Persona {
private:
    string id;
    string servicioDestino;

public:
    Paciente();
    Paciente(const string& id, const string& nombre, int edad, const string& servicioDestino);
    ~Paciente() override;

    string getId() const;
    string getServicioDestino() const;

    void setId(const string& id);
    void setServicioDestino(const string& servicioDestino);

    void mostrarInformacion() const override; 
};

