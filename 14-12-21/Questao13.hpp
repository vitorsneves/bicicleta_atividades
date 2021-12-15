#pragma once

#include <iostream>
#include "RETRI.hpp"

class Questao13 {

    private:
        static RETRI* retri;

    public:
        static void menuPrincipal();

    private:
        static void imprimirMenuPrincipal();
        static void imprimirMenuRetangulo();
        static void menuRetangulo();
        static void imprimirMenuTriangulo();
        static void menuTriangulo();

};
