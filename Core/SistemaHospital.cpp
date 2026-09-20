#include "SistemaHospital.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string normalizarServicio(const string& servicio) {

    if (servicio == "Cardiologia" ||
        servicio == "Cardiología") {
        return "Cardiología";
    }

    if (servicio == "Neurologia" ||
        servicio == "Neurología") {
        return "Neurología";
    }

    if (servicio == "Traumatologia" ||
        servicio == "Traumatología") {
        return "Traumatología";
    }

    if (servicio == "Pediatria" ||
        servicio == "Pediatría") {
        return "Pediatría";
    }

    if (servicio == "Hospitalizacion" ||
        servicio == "Hospitalización") {
        return "Hospitalización";
    }

    if (servicio == "Cirugia" ||
        servicio == "Cirugía") {
        return "Cirugía";
    }

    return servicio;
}

string servicioMayuscula(const string& servicio) {

    if (servicio == "Cardiología") {
        return "CARDIOLOGÍA";
    }

    if (servicio == "Neurología") {
        return "NEUROLOGÍA";
    }

    if (servicio == "Traumatología") {
        return "TRAUMATOLOGÍA";
    }

    if (servicio == "Pediatría") {
        return "PEDIATRÍA";
    }

    if (servicio == "Hospitalización") {
        return "HOSPITALIZACIÓN";
    }

    if (servicio == "Urgencias") {
        return "URGENCIAS";
    }

    if (servicio == "Medicina General") {
        return "MEDICINA GENERAL";
    }

    if (servicio == "Cirugía") {
        return "CIRUGÍA";
    }

    return servicio;
}

string servicioMinuscula(const string& servicio) {

    if (servicio == "Cardiología") {
        return "cardiología";
    }

    if (servicio == "Neurología") {
        return "neurología";
    }

    if (servicio == "Traumatología") {
        return "traumatología";
    }

    if (servicio == "Pediatría") {
        return "pediatría";
    }

    if (servicio == "Hospitalización") {
        return "hospitalización";
    }

    if (servicio == "Urgencias") {
        return "urgencias";
    }

    if (servicio == "Medicina General") {
        return "medicina general";
    }

    if (servicio == "Cirugía") {
        return "cirugía";
    }

    return servicio;
}

SistemaHospital::SistemaHospital() {
inicializarServicios();
}

SistemaHospital::~SistemaHospital() {
this->colaEspera.clear();
this->historialAtenciones.clear();
this->servicios.clear();
}

void SistemaHospital::inicializarServicios() {
this->servicios.insertLast(Servicio("Urgencias"));
this->servicios.insertLast(Servicio("Medicina General"));
this->servicios.insertLast(Servicio("Cardiología"));
this->servicios.insertLast(Servicio("Neurología"));
this->servicios.insertLast(Servicio("Traumatología"));
this->servicios.insertLast(Servicio("Cirugía"));
this->servicios.insertLast(Servicio("Pediatría"));
this->servicios.insertLast(Servicio("Hospitalización"));
}

bool SistemaHospital::cargarDatos(const string& rutaArchivo) {
this->cargador.setRutaArchivo(rutaArchivo);


return this->cargador.cargarPacientes(
    this->colaEspera
);


}

void SistemaHospital::mostrarColaEspera() {
if (this->colaEspera.empty()) {
cout << "No hay pacientes en espera." << endl;
return;
}


Queue<Paciente> aux;

int pos = 1;

while (!this->colaEspera.empty()) {

    Paciente paciente =
        this->colaEspera.dequeue();

    cout << pos
         << ". "
         << paciente.getId()
         << " - "
         << paciente.getNombre()
         << endl;

    aux.enqueue(paciente);

    pos++;
}

while (!aux.empty()) {
    this->colaEspera.enqueue(
        aux.dequeue()
    );
}


}

void SistemaHospital::atenderPacientes(int cantidad) {
if (cantidad <= 0) {
cout << "La cantidad de pacientes debe ser mayor que 0."
<< endl;
return;
}


if (this->colaEspera.empty()) {
    cout << "No hay pacientes para atender." << endl;
    return;
}

for (int i = 0;
     i < cantidad && !this->colaEspera.empty();
     i++) {

    Paciente paciente =
        this->colaEspera.dequeue();

    string nombreServicio =
        normalizarServicio(
            paciente.getServicioDestino()
        );

    Servicio* servicioEncontrado = nullptr;

    int posicion = 0;

    while (true) {
        try {
            Servicio& servicio =
                this->servicios.getReferencia(posicion);

            if (servicio.getNombreServicio() ==
                nombreServicio) {

                servicioEncontrado = &servicio;
                break;
            }

            posicion++;
        }
        catch (...) {
            break;
        }
    }

    if (servicioEncontrado == nullptr) {
        cout << "Servicio no válido para el paciente."
             << endl;
        continue;
    }

    // Agregar el paciente al servicio correspondiente.
    servicioEncontrado->agregarPaciente(paciente);

    cout << "ID: "
         << paciente.getId()
         << endl;

    cout << "Nombre: "
         << paciente.getNombre()
         << endl;

    cout << "Edad: "
         << paciente.getEdad()
         << endl;

    cout << "Servicio: "
         << paciente.getServicioDestino()
         << endl;

    cout << endl;
    cout << "Paciente enviado a "
         << paciente.getServicioDestino()
         << "."
         << endl;

    Atencion atencion(
        paciente.getId(),
        paciente.getNombre(),
        paciente.getEdad(),
        nombreServicio
    );

    this->historialAtenciones.push(
        atencion
    );
}


}

void SistemaHospital::mostrarDepartamentos() {
int i = 0;


while (true) {
    try {
        Servicio& servicio =
            this->servicios.getReferencia(i);

        cout << (i + 1)
             << ". "
             << servicio.getNombreServicio()
             << endl;

        i++;
    }
    catch (...) {
        break;
    }
}


}

void SistemaHospital::verDepartamento(int opcion) {
Servicio* servicioSeleccionado = nullptr;


try {
    servicioSeleccionado =
        &this->servicios.getReferencia(opcion - 1);
}
catch (...) {
    cout << "Opción de departamento inválida."
         << endl;
    return;
}

string nombreDepartamento =
    servicioSeleccionado->getNombreServicio();

string copia;

    if (nombreDepartamento == "Cardiología") {
        copia = "CARDIOLOGÍA";
    }
    else if (nombreDepartamento == "Neurología") {
        copia = "NEUROLOGÍA";
    }
    else if (nombreDepartamento == "Traumatología") {
        copia = "TRAUMATOLOGÍA";
    }
    else if (nombreDepartamento == "Pediatría") {
        copia = "PEDIATRÍA";
    }
    else if (nombreDepartamento == "Hospitalización") {
        copia = "HOSPITALIZACIÓN";
    }
    else if (nombreDepartamento == "Urgencias") {
        copia = "URGENCIAS";
    }
    else if (nombreDepartamento == "Medicina General") {
        copia = "MEDICINA GENERAL";
    }
    else if (nombreDepartamento == "Cirugía") {
        copia = "CIRUGÍA";
    }






cout << "=== ESTADO "
     << copia
     << " ==="
     << endl;

List<Paciente>& listaPacientes =
    servicioSeleccionado->getListaPacientes();

if (listaPacientes.empty()) {
    cout << "No hay pacientes en el departamento."
         << endl;
    return;
}

int cantidadPacientes = 0;
int i = 0;

while (true) {

    try {
        listaPacientes.get(i);

        cantidadPacientes++;
        i++;
    }
    catch (...) {
        break;
    }
}

string nombreMinuscula =
    nombreDepartamento;

if (!nombreMinuscula.empty() &&
    nombreMinuscula[0] >= 'A' &&
    nombreMinuscula[0] <= 'Z') {

    nombreMinuscula[0] =
        nombreMinuscula[0] + ('a' - 'A');
}

cout << "Pacientes en el departamento de "
     << nombreMinuscula
     << ": "
     << cantidadPacientes
     << endl;

i = 0;

while (true) {

    try {
        Paciente paciente =
            listaPacientes.get(i);

        cout << paciente.getNombre()
             << " ("
             << paciente.getEdad()
             << ")"
             << endl;
        cout << endl;

        i++;
    }
    catch (...) {
        break;
    }
}


}

void SistemaHospital::mostrarHistorial() {
cout << "=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ==="
<< endl;
cout << endl;

if (this->historialAtenciones.empty()) {
    cout << "No hay atenciones registradas."
         << endl;

    return;
}

Stack<Atencion> aux;

while (!this->historialAtenciones.empty()) {

    Atencion atencion =
        this->historialAtenciones.pop();

    cout << "Nombre: "
         << atencion.getNombrePaciente()
         << " | Edad: "
         << atencion.getEdadPaciente()
         << " | Departamento: "
         << atencion.getServicio()
         << endl;

    aux.push(atencion);
    cout << endl;
}

// Restaurar la pila original.
while (!aux.empty()) {
    this->historialAtenciones.push(
        aux.pop()
    );
}

}
