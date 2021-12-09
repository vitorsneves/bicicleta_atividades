#pragma once

class Fatorial {

    private:
        int valorRecebido = 0;
        int resultado = 1;

    public:
        int calculaFatorial();
    private:
        static int fatorial(int numero);

};