
class manipulaVetor {

    private:
        double* vetor;
        int tamanho;
    
    public:
        manipulaVetor(int tamannho);
        ~manipulaVetor();
        void recebeVetor();
        void colocarEmOrdem();
        void imprimeVetor();

};