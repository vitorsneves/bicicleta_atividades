#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
    ATIVIDADE: MULTIPLICAR MATRIZ POR CTE
    DATA: 01/12/2021
    ALUNOS: WESLLEY CARDOSO MARIANO;
    VITOR BELARMINO SILVA NEVES
*/

#define NUM_LINHAS 2
#define NUM_COLUNAS 2
#define TAMANHO_VETOR 2

double** alocaMatriz(int linhas, int colunas);
void limpaMatriz(double** matriz, int linhas);
double numEntre0e1();
void preencheMatriz(double** matriz, int linhas, int colunas);
double** matrizVezesCte(double** matriz, double constante);
void imprimirMatriz(double** matriz, int linhas, int colunas);

//cria e retorna matriz
double** alocaMatriz(int linhas, int colunas) {
    //aloca linhas
    double** matriz = malloc(linhas * sizeof(double*)); 

    //aloca colunas
    for(int i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(double));

    return matriz;
}

//libera espaco na memoria
void limpaMatriz(double** matriz, int linhas) {

    for(int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);
}

double numEntre0e1() {
    return (double)rand() / (double)RAND_MAX;
}

void preencheMatriz(double** matriz, int linhas, int colunas) {

    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            matriz[i][j] = numEntre0e1();
}

double** matrizVezesCte(double** matriz, double constante) {

    double** resultado = alocaMatriz(NUM_LINHAS, NUM_COLUNAS);

    for(int i = 0; i < NUM_LINHAS; i++)
        for(int j = 0; j < NUM_COLUNAS; j++)
            resultado[i][j] = matriz[i][j] * constante;

    return resultado;
}

void imprimirMatriz(double** matriz, int linhas, int colunas) {

    for(int i = 0; i < linhas; i++){
        //abre colchete
        printf("[");

        //imprime elementos da coluna
        for(int j = 0; j < colunas - 1; j++) 
            printf("%.4lf, ", matriz[i][j]);

        //imprime ultimo elemento e fecha colchete
        printf("%.4lf]\n", matriz[i][colunas - 1]); 
    }
}

int main() {
    srand(time(NULL));
    //cria matriz e vetor
    double** matriz = alocaMatriz(NUM_LINHAS, NUM_COLUNAS);
    double** vetorAlfa = alocaMatriz(1, TAMANHO_VETOR);

    //preenche com valores aleatorios
    preencheMatriz(matriz, NUM_LINHAS, NUM_COLUNAS);
    preencheMatriz(vetorAlfa, 1, TAMANHO_VETOR);

    //calcula resultado das divisoes
    double** matrizxAlfa1 = matrizVezesCte(matriz, vetorAlfa[0][0]);
    double** matrizxAlfa2 = matrizVezesCte(matriz, vetorAlfa[0][1]);

    printf("\nMatriz A:\n");
    imprimirMatriz(matriz, NUM_LINHAS, NUM_COLUNAS);

    printf("\nVetor alfa:\n");
    imprimirMatriz(vetorAlfa, 1, NUM_COLUNAS);

    printf("\nMatriz * alfa 1:\n");
    imprimirMatriz(matrizxAlfa1, NUM_LINHAS, NUM_COLUNAS);

    printf("\nMatriz * alfa 2:\n");
    imprimirMatriz(matrizxAlfa2, NUM_LINHAS, NUM_COLUNAS);

    limpaMatriz(matriz, NUM_LINHAS);
    limpaMatriz(vetorAlfa, 1);
    limpaMatriz(matrizxAlfa1 ,NUM_LINHAS);
    limpaMatriz(matrizxAlfa2 ,NUM_LINHAS);

    printf("\nPressione enter para continuar...\n");
    getchar();

    return 0;
}

