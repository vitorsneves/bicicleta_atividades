#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
    ATIVIDADE: IMPLEMENTAR TABELA
    DATA: 30/11/2021
    ALUNOS: WESLLEY CARDOSO MARIANO;
    VITOR BELARMINO SILVA NEVES
*/

#define QNT_LINHAS 10
#define QNT_COLUNAS 5
#define TAMANHO_PALAVRA 32
#define LARGURA_COLUNA 20
#define LARGURA_ENDERECO 32

typedef struct tabela {
    char matriz[QNT_LINHAS][QNT_COLUNAS][TAMANHO_PALAVRA];
    int linhasPreenchidas;
} tabela;

//resultados da busca na tabela
typedef struct resulBusca {
    int posicoes[QNT_LINHAS];
    int qntPosicoes;
} resulBusca;

//funcoes que desenham na tela
void imprimeCabecalhoTabela();
void imprimirLinha(int linha, tabela tabela);
void imprimeTabela(tabela tabela);
int opcoesDeBusca();
void imprimirMenu();
int selecionarColuna();

//funcionalidades da tabela
void adicionarPessoa(tabela* tabela);
void removerPessoa(tabela* tabela, int linha);
void remover(tabela* tabela);
void buscar(tabela tabela);
resulBusca buscarTabela(tabela tabela, int coluna, char* palavra);
void editarTabela(tabela* tabela);
int menu(tabela* tabela);

//funcoes auxiliares
tabela dadosIniciais();

//------------------------------
//funcoes que desenham na tela--
//------------------------------

void imprimeCabecalhoTabela() {
    printf("\nNOME                ");
    printf("ENDERECO                        ");
    printf("CODIGO POSTAL       ");
    printf("BAIRRO              ");
    printf("TELEFONE\n");
}

void imprimirLinha(int linha, tabela tabela) {

    for(int i = 0; i < 5; i++) {
            if(i == 1)
                printf("%-32s", tabela.matriz[linha][i]);
            else
                printf("%-20s", tabela.matriz[linha][i]);
    }

    printf("\n");
}

void imprimeTabela(tabela tabela) {
    imprimeCabecalhoTabela();

    for(int i = 0; i < tabela.linhasPreenchidas; i++)
        imprimirLinha(i, tabela);
}

int opcoesDeBusca() {
    int escolha;

    printf("\nVoce deseja procurar por nome ou telefone?\n");
    printf("1 - nome\n");
    printf("2 - telefone\n");
    scanf("%d", &escolha);
    fflush(stdin);

    if(escolha == 2)
        return 4;

    return 0;
}

void imprimirMenu() {
    printf("\nMENU\n");
    printf("Escolha uma opcao:\n");
    printf("\"1\" -> Adicionar\n");
    printf("\"2\" -> Remover\n");
    printf("\"3\" -> Pesquisar\n");
    printf("\"4\" -> Editar\n");
    printf("\"5\" -> Retornar\n");
    printf("\"6\" -> Fechar programa\n");
    printf("\nescolha: ");
}

int selecionarColuna() {
    int escolha;

    printf("\nEscolha uma coluna para editar:\n");
    printf("\"1\" -> Nome\n");
    printf("\"2\" -> Endereco\n");
    printf("\"3\" -> Codigo postal\n");
    printf("\"4\" -> Bairro\n");
    printf("\"5\" -> Telefone\n");
    printf("\nEscolha: ");
    
    scanf("%d", &escolha);
    fflush(stdin);

    return (escolha - 1);
}

//---------------------------
//funcionalidades da tabela--
//---------------------------

void adicionarPessoa(tabela* tabela) {

    system("cls || clear");
    printf("\nDigite o nome (maximo 20 caracteres): ");
    scanf("%[^\n]%*c", tabela->matriz[tabela->linhasPreenchidas][0]);
    printf("Digite o endereco (maximo 30 caracteres): ");
    scanf("%[^\n]%*c", tabela->matriz[tabela->linhasPreenchidas][1]);
    printf("Digite o codigo postal: ");
    scanf("%[^\n]%*c", tabela->matriz[tabela->linhasPreenchidas][2]);
    printf("Digite o bairro: ");
    scanf("%[^\n]%*c", tabela->matriz[tabela->linhasPreenchidas][3]);
    printf("Digite o telefone: ");
    scanf("%[^\n]%*c", tabela->matriz[tabela->linhasPreenchidas][4]);
    tabela->linhasPreenchidas++;

}

void removerPessoa(tabela* tabela, int linha) {

    tabela->linhasPreenchidas--;

    for(int i = linha; i < tabela->linhasPreenchidas; i++)
        for(int j = 0; j < QNT_COLUNAS; j++) {
            
            strcpy(tabela->matriz[i][j], tabela->matriz[i + 1][j]);
        }

}

void remover(tabela* tabela) {

    system("cls || clear");
    printf("\nDELETAR");
    int coluna = opcoesDeBusca();
    system("cls || clear");
    imprimeTabela(*tabela);

    if(coluna == 0)
        printf("\nDigite o nome do cliente que deseja excluir.\n");
    else
        printf("\nDigite o telefone do cliente que deseja excluir.\n");

    char palavra[TAMANHO_PALAVRA];
    scanf("%[^\n]%*c", &palavra);

    resulBusca resulBusca = buscarTabela(*tabela, coluna, palavra);

    if(resulBusca.qntPosicoes == 0) {
        printf("\nNenhuma pessoa encontrada\n");
        return;
    }

    printf("\nPessoas encontradas:\n");
    imprimeCabecalhoTabela();
    for(int i = 0; i < resulBusca.qntPosicoes; i++)
        imprimirLinha(resulBusca.posicoes[i], *tabela);

    printf("\nDeseja realmente excluir esse(s) cliente(s)? (Y/N)\n");
    char escolha;
    scanf(" %c", &escolha);
    fflush(stdin);

    if(escolha == 'Y' || escolha == 'y' || escolha == 'S' || escolha == 's')
        for(int i = 0; i < resulBusca.qntPosicoes; i++)
            removerPessoa(tabela, resulBusca.posicoes[i]);
}

void buscar(tabela tabela) {

    system("cls || clear");
    int coluna = opcoesDeBusca();
    system("cls || clear");
    imprimeTabela(tabela);

    if(coluna == 0)
        printf("\nDigite o nome do cliente que deseja procurar.\n");
    else
        printf("\nDigite o telefone do cliente que deseja procurar.\n");

    char palavra[TAMANHO_PALAVRA];
    scanf("%[^\n]%*c", &palavra);

    resulBusca resulBusca = buscarTabela(tabela, coluna, palavra);

    if(resulBusca.qntPosicoes == 0) {
        printf("Nenhum resultado encontrado\n");
        return;
    }

    imprimeCabecalhoTabela();

    for(int i = 0; i < resulBusca.qntPosicoes; i++)
        imprimirLinha(resulBusca.posicoes[i], tabela);
}

resulBusca buscarTabela(tabela tabela, int coluna, char* palavra) {
    resulBusca resulBusca;
    resulBusca.qntPosicoes = 0;

   for(int i = 0; i < tabela.linhasPreenchidas; i++) {

       if(strcmp(tabela.matriz[i][coluna], palavra) == 0) {

           resulBusca.posicoes[resulBusca.qntPosicoes] = i;
           resulBusca.qntPosicoes++;
       }
   }

   return resulBusca;
}

void editarTabela(tabela* tabela) {
    system("cls || clear");
    imprimeTabela(*tabela);

    printf("\ndigite o nome da pessoa que deseja editar: \n");
    char nome[TAMANHO_PALAVRA];
    scanf("%[^\n]%*c", &nome);

    resulBusca resulBusca = buscarTabela(*tabela, 0, nome);

    if(resulBusca.qntPosicoes == 0) {
        printf("\nPessoa nao encontrada.\n");
        return;
    }

    system("cls || clear");
    int escolha = selecionarColuna();

    system("cls || clear");
    imprimeCabecalhoTabela();
    imprimirLinha(resulBusca.posicoes[0], *tabela);

    printf("\nDigite o novo valor para ");
    
    switch(escolha) {
        case 0:
            printf("nome: ");
            break;
        case 1:
            printf("endereco: ");
            break;
        case 2:
            printf("codigo postal: ");
            break;
        case 3:
            printf("bairro: ");
            break;
        case 4:
            printf("telefone: ");
            break;
    }

    char novoValor[TAMANHO_PALAVRA];
    scanf("%[^\n]%*c", &novoValor);
    strcpy(tabela->matriz[resulBusca.posicoes[0]][escolha], novoValor);

    printf("\nlinha atualizada:\n");
    imprimirLinha(resulBusca.posicoes[0],*tabela);

}

int menu(tabela* tabela) {

    system("cls || clear");

    imprimirMenu();

    char escolha;
    scanf(" %c", &escolha);
    fflush(stdin);

    switch(escolha) {
        case '1':
            adicionarPessoa(tabela);
            break;
        case '2':
            remover(tabela);
            break;
        case '3':
            buscar(*tabela);
            break;
        case '4':
            editarTabela(tabela);
            break;
        case '5':
            return 1;
        case '6':
            return 0;
        default:
            printf("\nOpcao invalida\n");
    }

    system("pause");

    return 1;
}

//--------------------
//funcoes auxiliares--
//--------------------

tabela dadosIniciais() {
    tabela tabela;
    tabela.linhasPreenchidas = 4;

    strcpy(tabela.matriz[0][0], "Weslley");
    strcpy(tabela.matriz[0][1], "Av. Ines, n 0");
    strcpy(tabela.matriz[0][2], "74494755");
    strcpy(tabela.matriz[0][3], "Jd. Sao Jose");
    strcpy(tabela.matriz[0][4], "3233-6566");

    strcpy(tabela.matriz[1][0], "Vitor Neves");
    strcpy(tabela.matriz[1][1], "Av Tocantins, n850");
    strcpy(tabela.matriz[1][2], "74043050");
    strcpy(tabela.matriz[1][3], "Setor Central");
    strcpy(tabela.matriz[1][4], "99493-4236");

    strcpy(tabela.matriz[2][0], "Carlos");
    strcpy(tabela.matriz[2][1], "R. Suzana de Oliveira n 35");
    strcpy(tabela.matriz[2][2], "74495866");
    strcpy(tabela.matriz[2][3], "Jd. das Rosas");
    strcpy(tabela.matriz[2][4], "98129-1125");

    strcpy(tabela.matriz[3][0], "Amanda");
    strcpy(tabela.matriz[3][1], "Av. Sao Carlos, n 693");
    strcpy(tabela.matriz[3][2], "74494000");
    strcpy(tabela.matriz[3][3], "St. Campinas");
    strcpy(tabela.matriz[3][4], "3295-6688");

    return tabela;
}

//-------------
//funcao main--
//-------------

int main() {
    tabela tabela = dadosIniciais();
    int rodando = 1;
    char escolha = ' ';

    while(rodando) {
        system("cls || clear");
        imprimeTabela(tabela);

        printf("\nDigite \"M\" para acessar o menu de opcoes...\n");
        scanf(" %c", &escolha);
        fflush(stdin);

        if(escolha == 'M' || escolha == 'm')
            rodando = menu(&tabela);
    }

}