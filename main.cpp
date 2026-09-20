#include <windows.h>
#include "Core/Menu.hpp"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Menu menu;
    menu.iniciar();

    return 0;
}
