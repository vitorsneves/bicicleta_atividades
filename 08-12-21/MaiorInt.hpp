#pragma once

class MaiorInt {

    private:
        int numeros[3] = {0, 0, 0};
        int maior = 0;

    public:
        void recebeValores();
        int calculaMaior();

};