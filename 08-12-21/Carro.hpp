#pragma once

class Carro {

    private:
        double distancia = 0;
        double tempo = 0;
        double velocidadeMedia = 0;

    public:
        void recebeDados();
        double calculaVelocidade();
    private:
        double recebeDistancia();
        double recebeTempo();
        double minutosParaSegundos(double minutos);

};