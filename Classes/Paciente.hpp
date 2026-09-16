#ifndef PACIENTE_HPP
#define PACIENTE_HPP


#include "Persona.hpp"
#include <string>
//using namespace std;

class Paciente : public Persona {
private:
    std::string id;
    std::string servicioDestino;

public:
    Paciente();
    Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& servicioDestino);
    ~Paciente() override;

    std::string getId() const;
    std::string getServicioDestino() const;

    void setId(const std::string& id);
    void setServicioDestino(const std::string& servicioDestino);

    void mostrarInformacion() const override;
};

#endif // PACIENTE_HPP
