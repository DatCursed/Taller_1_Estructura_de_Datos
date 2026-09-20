# Taller 01: Estructura de Datos - Sistema básico de gestión de pacientes

## Integrantes:
* **Nombre:** Diego Seco 
* **RUT:** 218925383 
* **Usuario de Github:** DiegoSB20 
* **Carrera:** ICCI

* **Nombre:** David Rodríguez
* **RUT:**  218065791
* **Usuario de Github:** DatCursed
* **Carrera:** ICCI

## Instrucciones de Compilación

Sistema hospitalario desarrollado en C++17.

1. Requisitos

Compilador compatible con C++17.
CMake.
CLion, Visual Studio con soporte para C++/CMake, u otro IDE compatible.

la carpeta del proyecto deberá contener las tres carpetas Classes, Core y data_structures. 
debe contener el archivo pacientes.txt.
debe contener el main.cpp que inicia el programa. 
y por ulitmo el CMakeLists.txt.
en este caso se veria asi: 

cmake_minimum_required(VERSION 3.20)

project(Taller_1_Estructura_de_Datos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Taller_1_Estructura_de_Datos
        main.cpp

        clases/Persona.cpp
        clases/Paciente.cpp
        clases/Atencion.cpp
        clases/Servicio.cpp

        Core/CargaArchivo.cpp
        Core/SistemaHospital.cpp
        Core/Menu.cpp
)

## Ejecutar en CLion

* 1.Abrir CLion.
* 2.Seleccionar File → Open.
* 3.Abrir la carpeta que contiene CMakeLists.txt.
* 4.Esperar a que CLion cargue CMake.
* 5.Seleccionar el target Taller_1_Estructura_de_Datos.
* 6.Compilar con Build → Build Project o Ctrl + F9.
* 7.Ejecutar con Run → Run 'Taller_1_Estructura_de_Datos' o Shift + F10.

Se recomienda mantener pacientes.txt en la carpeta principal del proyecto.

Si aparece No hay pacientes en espera. aunque el archivo tenga datos, revisar la ubicación del archivo y el directorio de ejecución del IDE.


## Ejecutar en Visual Studio

* 1.Instalar Visual Studio con las herramientas de desarrollo de C++ y CMake.
* 2.Abrir File → Open → Folder.
* 3.Seleccionar la carpeta que contiene CMakeLists.txt.
* 4.Esperar la configuración de CMake.
* 5.Seleccionar el target Taller_1_Estructura_de_Datos.
* 6.Usar Build → Build All.
* 7.Ejecutar con F5 o el botón de ejecución.



## Compilar desde terminal con CMake

Desde la carpeta principal:

cmake -S . -B build
cmake --build build

La ubicación final del ejecutable depende del generador y configuración. En Windows puede quedar, por ejemplo, en build/Debug/Taller_1_Estructura_de_Datos.exe.

# compilar y ejetcutar desde github 

## Clion

* 1. Abrir CLion.
* 2. En la pantalla inicial seleccionar "Get from VCS"
   o "Clone Repository".
* 3. Pegar la URL del repositorio de GitHub.
* 4. Elegir la carpeta donde se guardará el proyecto.
* 5. Presionar "Clone".
* 6. Abrir el proyecto cuando CLion lo solicite.
* 7. Esperar a que CMake termine de cargar.
* 8. Seleccionar el target "Taller_1_Estructura_de_Datos".
* 9. Compilar con Build → Build Project.
* 10. Ejecutar con Run → Run 'Taller_1_Estructura_de_Datos'.

## Visual 

* 1. Abrir Visual Studio.
* 2. Seleccionar "Clone a repository".
* 3. Pegar la URL del repositorio de GitHub.
* 4. Elegir la carpeta de destino.
* 5. Presionar "Clone".
* 6. Abrir el proyecto CMake.
* 7. Visual Studio detectará el CMakeLists.txt.
* 8. Seleccionar el target "Taller_1_Estructura_de_Datos".
* 9. Compilar con Build → Build All.
* 10. Ejecutar con F5.

Desde Git Bash / CMD / PowerShell

Esta es la opción más independiente del IDE. Primero se clona el repositorio:
git clone https://github.com/DatCursed/Taller_1_Estructura_de_Datos.git
cd Taller_1_Estructura_de_Datos
cmake -S . -B build
cmake --build build
Y finalmente ejecutar el .exe generado.

