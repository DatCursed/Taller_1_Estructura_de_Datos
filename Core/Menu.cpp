#include "Menu.hpp"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::mostrarMenuPrincipal() {
    cout << "=== HOSPITAL MARMAJA ===" << endl;
    cout << "1. Atender pacientes" << endl;
    cout << "2. Ver departamento" << endl;
    cout << "3. Revisar historial de atención" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    cout << "Seleccionar opción: ";
}

void Menu::iniciar() {
    if (!this->sistema.cargarDatos("pacientes.txt")) {
        this->sistema.cargarDatos("../pacientes.txt");
    }

    int opcion = 0;
    int numeroOpcion = 1;

    while (opcion != 4) {


        cout << "------------------- Opción "
             << numeroOpcion
             << " -------------------"
             << endl;

        mostrarMenuPrincipal();


        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        //cout << endl;

        switch (opcion) {

            case 1:
                opcionAtender();
                break;

            case 2:
                opcionVerDepartamento();
                break;

            case 3:
                opcionHistorial();
                break;

            case 4:
                //cout << endl;
                cout << "Hasta luego :D." << endl;
                break;

            default:
                cout << "Opción inválida." << endl;
                break;
        }

        if (opcion >= 1 && opcion <= 3) {
            numeroOpcion = opcion + 1;
        }
    }
}

void Menu::opcionAtender() {
    cout << "=== PACIENTES EN ESPERA ===" << endl;

    this->sistema.mostrarColaEspera();

    cout << endl;
    cout << "Indique la cantidad de pacientes a atender: ";

    int cantidad;

    if (cin >> cantidad) {
        //cout << endl;
        cout << "=== ATENDIENDO PACIENTES ===" << endl;

        this->sistema.atenderPacientes(cantidad);
        cout << endl;
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Menu::opcionVerDepartamento() {
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;

    this->sistema.mostrarDepartamentos();

    cout << endl;
    cout << "Seleccionar opción: ";

    int dep;

    if (cin >> dep) {
        cout << endl;
        this->sistema.verDepartamento(dep);
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Menu::opcionHistorial() {
    this->sistema.mostrarHistorial();
}
