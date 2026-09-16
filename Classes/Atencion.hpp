#ifndef ATENCION_HPP
#define ATENCION_HPP

#include "Paciente.hpp"
#include <string>
//using namespace std;

class Atencion {
private:
    std::string idPaciente;
    std::string nombrePaciente;
    int edadPaciente;
    std::string servicio;

public:
    Atencion();
    Atencion(const Paciente& paciente);
    Atencion(const std::string& id, const std::string& nombre, int edad, const std::string& servicio);
    ~Atencion();

    std::string getIdPaciente() const;
    std::string getNombrePaciente() const;
    int getEdadPaciente() const;
    std::string getServicio() const;

    void mostrarDetalle() const;
};

#endif // ATENCION_HPP
