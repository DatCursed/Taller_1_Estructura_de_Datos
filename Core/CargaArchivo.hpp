#pragma once

#include <string>
#include <fstream>
#include "../data_structures/Queue.hpp"
#include "../Classes/Paciente.hpp"

using namespace std;

class CargaArchivo {
private:
    string rutaArchivo;

    string extraerCampo(const string& linea, int& indice);

public:
    CargaArchivo();
    CargaArchivo(const string& rutaArchivo);
    ~CargaArchivo();

    string getRutaArchivo() const;
    void setRutaArchivo(const string& rutaArchivo);

    bool cargarPacientes(Queue<Paciente>& colaPacientes);
};
