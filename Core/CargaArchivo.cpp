#include "CargaArchivo.hpp"
#include <iostream>
#include <fstream>

using namespace std;

CargaArchivo::CargaArchivo() {
    this->rutaArchivo = "";
}

CargaArchivo::CargaArchivo(const string& rutaArchivo) {
    this->rutaArchivo = rutaArchivo;
}

CargaArchivo::~CargaArchivo() {
}

string CargaArchivo::getRutaArchivo() const {
    return this->rutaArchivo;
}

void CargaArchivo::setRutaArchivo(const string& rutaArchivo) {
    this->rutaArchivo = rutaArchivo;
}

string CargaArchivo::extraerCampo(const string& linea, int& indice) {
    string campo = "";
    int largo = linea.length();

    while (indice < largo && linea[indice] != ';') {
        campo += linea[indice];
        indice++;
    }

    if (indice < largo && linea[indice] == ';') {
        indice++;
    }

    return campo;
}

bool CargaArchivo::cargarPacientes(Queue<Paciente>& colaPacientes) {
    ifstream archivo(this->rutaArchivo);

    if (!archivo.is_open()) {
        //cout << "Error: No se pudo abrir el archivo " << this->rutaArchivo << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

        int indice = 0;
        string rut = extraerCampo(linea, indice);
        string nombre = extraerCampo(linea, indice);
        string strEdad = extraerCampo(linea, indice);
        string enfermedad = extraerCampo(linea, indice);

        if (!rut.empty() && !nombre.empty() && !strEdad.empty()) {
            int edad = stoi(strEdad);
            Paciente paciente(rut, nombre, edad, enfermedad);
            colaPacientes.enqueue(paciente);
        }
    }

    archivo.close();
    //cout << "Carga de datos realizada con éxito desde " << this->rutaArchivo << endl;
    return true;
}
