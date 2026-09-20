#pragma once

#include "SistemaHospital.hpp"

class Menu {
private:
    SistemaHospital sistema;

    void mostrarMenuPrincipal();
    void opcionAtender();
    void opcionVerDepartamento();
    void opcionHistorial();

public:
    Menu();
    ~Menu();

    void iniciar();
};
