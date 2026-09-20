#pragma once

#include <string>
#include "../data_structures/Queue.hpp"
#include "../data_structures/Stack.hpp"
#include "../data_structures/List.hpp"
#include "../classes/Persona.hpp"
#include "../classes/Paciente.hpp"
#include "../classes/Atencion.hpp"
#include "../classes/Servicio.hpp"
#include "CargaArchivo.hpp"

using namespace std;

class SistemaHospital {
private:
    Queue<Paciente> colaEspera;
    Stack<Atencion> historialAtenciones;
    List<Servicio> servicios;
    CargaArchivo cargador;

    void inicializarServicios();

public:
    SistemaHospital();
    ~SistemaHospital();

    bool cargarDatos(const string& rutaArchivo);
    void mostrarColaEspera();
    void atenderPacientes(int cantidad);
    void mostrarDepartamentos();
    void verDepartamento(int opcion);
    void mostrarHistorial();
};
