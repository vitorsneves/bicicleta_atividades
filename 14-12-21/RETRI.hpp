#pragma once

class RETRI {
    private:
        // Triangulo.
        double baseTriangu;
        double alturaTriangu;
        double areaTriangu;

        // Retangulo.
        double ladoMaiorReta;
        double ladoMenorReta;
        double areaReta;

    // Metodos publicos.
    public:
        // Construtores.
        RETRI();
        RETRI(double baseTriangu, double alturaTriangu, double ladoMaiorReta, double ladoMenorReta);

        // Triangulo.
        double setTriangu(double baseTriangu, double alturaTriangu);
        double getAreaTriangu();

         // Retangulo.       
        double setRetangulo(double ladoMenorReta, double ladoMaiorReta);
        double getAreaRetangulo();

    // Metodos privados.
    private:
        void calcularAreaTriangu();
        void calcularAreaReta();
};