#include "CargaArchivo.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

static bool servicioValido(const string& servicio) {

    if (servicio == "Urgencias") {
        return true;
    }

    if (servicio == "Medicina General") {
        return true;
    }

    if (servicio == "Cardiologia" ||
        servicio == "Cardiología") {

        return true;
    }

    if (servicio == "Neurologia" ||
        servicio == "Neurología") {

        return true;
    }

    if (servicio == "Traumatologia" ||
        servicio == "Traumatología") {

        return true;
    }

    if (servicio == "Cirugia" ||
        servicio == "Cirugía") {

        return true;
    }

    if (servicio == "Pediatria" ||
        servicio == "Pediatría") {

        return true;
    }

    if (servicio == "Hospitalizacion" ||
        servicio == "Hospitalización") {

        return true;
    }

    return false;
}

static bool existePaciente(
    Queue<Paciente>& cola,
    const string& id
) {
    Queue<Paciente> aux;

    bool encontrado = false;

    while (!cola.empty()) {

        Paciente paciente =
            cola.dequeue();

        if (paciente.getId() == id) {
            encontrado = true;
        }

        aux.enqueue(paciente);
    }

    // Restaurar la cola exactamente como estaba.
    while (!aux.empty()) {
        cola.enqueue(aux.dequeue());
    }

    return encontrado;
}

CargaArchivo::CargaArchivo() {
    this->rutaArchivo = "";
}

CargaArchivo::CargaArchivo(
    const string& rutaArchivo
) {
    this->rutaArchivo = rutaArchivo;
}

CargaArchivo::~CargaArchivo() {
}

string CargaArchivo::getRutaArchivo() const {
    return this->rutaArchivo;
}

void CargaArchivo::setRutaArchivo(
    const string& rutaArchivo
) {
    this->rutaArchivo = rutaArchivo;
}

string CargaArchivo::extraerCampo(
    const string& linea,
    int& indice
) {
    string campo = "";

    int largo = linea.length();

    while (indice < largo &&
           linea[indice] != ';') {

        campo += linea[indice];
        indice++;
    }

    if (indice < largo &&
        linea[indice] == ';') {

        indice++;
    }

    return campo;
}

bool CargaArchivo::cargarPacientes(
    Queue<Paciente>& colaPacientes
) {
    ifstream archivo(this->rutaArchivo);

    if (!archivo.is_open()) {
        return false;
    }

    string linea;

    while (getline(archivo, linea)) {

        if (linea.empty()) {
            continue;
        }

        int indice = 0;

        string id =
            extraerCampo(linea, indice);

        string nombre =
            extraerCampo(linea, indice);

        string strEdad =
            extraerCampo(linea, indice);

        string servicio =
            extraerCampo(linea, indice);

        // Ignorar encabezado:
        // ID;Nombre;Edad;Servicio
        if (id == "ID" &&
            nombre == "Nombre" &&
            strEdad == "Edad" &&
            servicio == "Servicio") {

            continue;
        }

        // Validar que existan los cuatro campos.
        if (id.empty() ||
            nombre.empty() ||
            strEdad.empty() ||
            servicio.empty()) {

            continue;
        }

        // Si quedaron caracteres después del cuarto campo,
        // la línea tiene más información de la esperada.
        if (indice < static_cast<int>(linea.length())) {
            continue;
        }

        // Validar servicio.
        if (!servicioValido(servicio)) {
            continue;
        }

        int edad = 0;

        try {
            size_t posicion = 0;

            edad = stoi(
                strEdad,
                &posicion
            );

            // Evita aceptar cosas como "25abc".
            if (posicion != strEdad.length()) {
                continue;
            }
        }
        catch (...) {
            // Edad que no es un número válido.
            continue;
        }

        // No aceptar edades negativas.
        if (edad < 0) {
            continue;
        }

        // No aceptar pacientes duplicados.
        if (existePaciente(
                colaPacientes,
                id
            )) {

            continue;
        }

        Paciente paciente(
            id,
            nombre,
            edad,
            servicio
        );

        colaPacientes.enqueue(
            paciente
        );
    }

    archivo.close();

    return true;
}
