#pragma once

#include <iostream>
#include "RETRI.hpp"

class Questao13 {

    private:
        static RETRI* retri;

    public:
        static void abrir();

    private:
        static void imprimirMenuPrincipal();
        static void menuPrincipal();
        static void menuRetangulo();
        static void menuTriangulo();

};
