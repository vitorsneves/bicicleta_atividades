#include <stdlib.h> //alocacao dinamica
#include <stdio.h>  
#include <math.h>
#include <time.h> //necessario para seed do srand

/*
 * TAREFA 02(C2)
 * DATA: 02/12/2021
 * ALUNO: VITOR BELARMINO SILVA NEVES
*/

//tamanho do vetor
#define TAMANHO_VET 5

typedef struct vetor {
    double* array;
    int size;
} vetor;


//funcoes que manipulam struct vetor
vetor* criaVetor(int tamanho);
void limpaVetor(vetor* vetor);
void imprimeVetor(vetor vetor);
void preencheVetorReal(vetor* vetor);
void preencheVetorBinario(vetor* vetor);

//funcoes que realizam calculos
double numEntre0e1();
int binario();
double calculaNet(vetor vetorX, vetor vetorW);
double calculaY(double net);


//-----------------------------------
//funcoes que manipulam struct vetor-
//-----------------------------------

//aloca e retorna um struct vetor do tamanho desejado
vetor* criaVetor(int tamanho) {
    //aloca struct vetor
    vetor* vetor = malloc(sizeof(vetor));
    vetor->size = tamanho;

    //aloca array de double
    vetor->array = malloc(tamanho * sizeof(double));

    return vetor;
}

//libera espaco na memoria
void limpaVetor(vetor* vetor) {
    free(vetor->array);
    free(vetor);
}

void imprimeVetor(vetor vetor) {
    printf("[");

    //imprime valores até o penultimo
    for(int i = 0; i <= vetor.size - 2; i++)
        printf("%.4lf, ", vetor.array[i]);

    //imprime ultimo valor e fecha colchete
    printf("%.4lf]\n", vetor.array[vetor.size - 1]);
}

void preencheVetorReal(vetor* vetor) {
    for(int i = 0; i < vetor->size; i++)
        vetor->array[i] = numEntre0e1();
}

void preencheVetorBinario(vetor* vetor) {
    for(int i = 0; i < vetor->size; i++)
        vetor->array[i] = binario();
}


//------------------------------
//funcoes que realizam calculos-
//------------------------------

//retorna um numero aleatorio entre 0 e 1
double numEntre0e1() {
    return (double)rand() / RAND_MAX;
}

//retorna 0 ou 1 (aleatoriamente)
int binario() {
    return rand() % 2;
}

double calculaNet(vetor vetorX, vetor vetorW) {
    double net = 0.0;

    //percorre elementos do vetor x
    for(int i = 0; i < vetorX.size; i++)
        //percorre elementos do vetor w
        for(int j = 0; j < vetorW.size; j++)
            //multiplica o vetX[i] atual por cada um dos vetW[j] e acumula soma em net
            net += vetorX.array[i] * vetorW.array[j];

    return net;
}

double calculaY(double net) {
    return tanh(net);
}

//------------
//funcao main-
//------------

int main() {
    system("cls || clear");
    printf("\nBem vindo ao programa.\n");
    srand(time(NULL));

    //cria e preenche vetores
    vetor* vetorX = criaVetor(TAMANHO_VET);
    vetor* vetorW = criaVetor(TAMANHO_VET);
    preencheVetorBinario(vetorX);
    preencheVetorReal(vetorW);

    // calcula net e y
    double net = calculaNet(*vetorX, *vetorW);
    double y = calculaY(net);

    //exibe resultados
    printf("\nVetor x --> ");
    imprimeVetor(*vetorX);
    printf("\nY = %.6lf\n", y);

    limpaVetor(vetorX);
    limpaVetor(vetorW);

    printf("\nAperte enter para continuar...");
    getchar();
}