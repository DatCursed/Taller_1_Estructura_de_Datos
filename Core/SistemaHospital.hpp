#pragma once

#include <string>
#include "../data_structure/Queue.hpp"
#include "../data_structure/Stack.hpp"
#include "../data_structure/List.hpp"
#include "../Clases/Persona.hpp"
#include "../Clases/Paciente.hpp"
#include "../Clases/Atencion.hpp"
#include "../Clases/Servicio.hpp"
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
