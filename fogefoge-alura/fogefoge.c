#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"mapa.h"
#include"fogefoge.h"

MAPA mapa;
POSICAO posHeroi;
int possuiPilula = 0;

int fimDeJogo() {
    return !procuraMapa(&mapa, &posHeroi, HEROI);
}

POSICAO direcaoAleatoria(POSICAO posAtual) {
    POSICAO novaPos;
    memcpy(&novaPos, &posAtual, sizeof(POSICAO));

    srand(time(0));
    int escolha = rand() % 4;

    switch(escolha) {
        case 0:
            novaPos.x++;
            break;
        case 1:
            novaPos.x--;
            break;
        case 2:
            novaPos.y++;
            break;
        case 3:
            novaPos.y--;
            break;
    }

    return novaPos;
}

void limparCasas(POSICAO posAtual, int paraCima, int paraDireita, int casas) {
    posAtual.x += paraCima;
    posAtual.y += paraDireita;
    if(mapa.matriz[posAtual.x][posAtual.y] != PAREDE_VERTICAL&&
    mapa.matriz[posAtual.x][posAtual.y] != PAREDE_HORIZONTAL&&
    casas >= 0){
        mapa.matriz[posAtual.x][posAtual.y] = VAZIO;
        limparCasas(posAtual, paraCima, paraDireita, casas - 1);
    }
}

void usarPilula() {
    limparCasas(posHeroi, 1, 0, 3);
    limparCasas(posHeroi, 0, 1, 3);
    limparCasas(posHeroi, -1, 0, 3);
    limparCasas(posHeroi, 0, -1, 3);
    possuiPilula = 0;
}

void moveFantasma() {
    MAPA mapaCopia;
    copiaMapa(&mapaCopia, &mapa);
    for(int i = 0; i < mapaCopia.linhas; i++)
        for(int j = 0; j < mapaCopia.colunas; j++)
            if(mapaCopia.matriz[i][j] == FANTASMA){
                POSICAO posAtual;
                posAtual.x = i;
                posAtual.y = j;
                POSICAO novaPos = direcaoAleatoria(posAtual);
                //fantasma se move para posicao vazia ou mata fogefoge
                if(mapaCopia.matriz[novaPos.x][novaPos.y] == VAZIO ||
                 mapaCopia.matriz[novaPos.x][novaPos.y] == HEROI){
                    mapa.matriz[i][j] = VAZIO;
                    mapa.matriz[novaPos.x][novaPos.y] = FANTASMA;
                }
            }
    limparMapa(&mapaCopia);
}

void moveHeroi() {
    POSICAO proximaPosicao = registraEntrada(posHeroi);

    //move para posicao vazia ou com pilula
    if(mapa.matriz[proximaPosicao.x][proximaPosicao.y] == VAZIO ||
    mapa.matriz[proximaPosicao.x][proximaPosicao.y] == PILULA){
        if(mapa.matriz[proximaPosicao.x][proximaPosicao.y] == PILULA)
            possuiPilula = 1;
        mapa.matriz[posHeroi.x][posHeroi.y] = VAZIO;
        posHeroi = proximaPosicao;
        mapa.matriz[proximaPosicao.x][proximaPosicao.y] = HEROI;
    }

    //move para fantasma e morre
    if(mapa.matriz[proximaPosicao.x][proximaPosicao.y] == FANTASMA)
        mapa.matriz[posHeroi.x][posHeroi.y] = VAZIO;

}

POSICAO registraEntrada(POSICAO posAtual) {
    char entrada;
    scanf(" %c", &entrada);

    if(!validarEntrada(entrada)) return posAtual;

    POSICAO proxPosicao;
    memcpy(&proxPosicao, &posAtual, sizeof(POSICAO));

    switch(entrada) {
        case 'w':
            proxPosicao.x--;
            break;
        case 'a':
            proxPosicao.y--;
            break;
        case 's':
            proxPosicao.x++;
            break;
        case 'd':
            proxPosicao.y++;
            break;
        case 'e':
            if(possuiPilula)
                usarPilula();
            break;
    }

    return proxPosicao;
}

int validarEntrada(char entrada) {
    return entrada == 'w' ||
           entrada == 'a' ||
           entrada == 's' ||
           entrada == 'd' ||
           entrada == 'e';
}

int main() {
    mapa = leMapa();
    procuraMapa(&mapa, &posHeroi, HEROI);
    while(!fimDeJogo()) {
        printf("Possui pilula: %s\n", possuiPilula ? "SIM" : "NAO");
        desenhaMapaSimples(&mapa);
        moveHeroi();
        moveFantasma();
    }
    limparMapa(&mapa);
}