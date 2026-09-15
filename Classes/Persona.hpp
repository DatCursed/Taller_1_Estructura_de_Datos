#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona();
    Persona(const std::string& nombre, int edad);
    virtual ~Persona();

    std::string getNombre() const;
    int getEdad() const;

    void setNombre(const std::string& nombre);
    void setEdad(int edad);

    virtual void mostrarInformacion() const;
};

#endif // PERSONA_HPP
