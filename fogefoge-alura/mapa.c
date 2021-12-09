#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mapa.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void alocarMapa(MAPA* mapa) {
    mapa->matriz = malloc(sizeof(char*) * mapa->linhas);
    for(int i = 0; i < mapa->linhas; i++)
        mapa->matriz[i] = malloc(sizeof(char) * (mapa->colunas + 1));
}

void limparMapa(MAPA* mapa) {
    for(int i = 0; i < mapa->linhas; i++)
        free(mapa->matriz[i]);
    free(mapa->matriz);
}

void copiaMapa(MAPA* mapaCopia, MAPA* mapaOriginal) {
    mapaCopia->linhas = mapaOriginal->linhas;
    mapaCopia->colunas = mapaOriginal->colunas;

    alocarMapa(mapaCopia);

    for(int i = 0; i < mapaOriginal->linhas; i++)
        strcpy(mapaCopia->matriz[i], mapaOriginal->matriz[i]);
}

int procuraMapa(MAPA* mapa, POSICAO* posicao, char simbolo) {
    
    for(int i = 0; i < mapa->linhas; i++)
        for(int j = 0; j < mapa->colunas; j++)

            if(mapa->matriz[i][j] == simbolo) {
                posicao->x = i;
                posicao->y = j;
                return 1;
            }

    return 0;
}

MAPA leMapa() {
    MAPA mapa;
    FILE* arquivoMapa = fopen("mapa.txt", "r");

    fscanf(arquivoMapa, "%d %d", &(mapa.linhas), &(mapa.colunas));

    alocarMapa(&mapa);

    for(int i = 0; i < mapa.linhas; i++) {
        fscanf(arquivoMapa, "%s", mapa.matriz[i]);
    }

    return mapa;
}

void desenhaMapaSimples(MAPA* mapa) {
    for(int i = 0; i < mapa->linhas; i++)
        printf("%s\n", mapa->matriz[i]);
}

void desenhaMapa(MAPA* mapa) {
    for(int i = 0; i < mapa->linhas; i++)
        for(int parte = 0; parte < 4; parte++){
            for(int j = 0; i < mapa->colunas; j++)
                switch(mapa->matriz[i][j]){
                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        printf("%s", desenhoparede[parte]);
                        break;
                    case VAZIO:
                        printf("%s", desenhovazio[parte]);
                        break;
                    case FANTASMA:
                        printf("%s", desenhofantasma[parte]);
                        break;
                    case PILULA:
                        printf("%s", desenhopilula[parte]);
                        break;
                    case HEROI:
                        printf("%s", desenhoheroi[parte]);
                        break;
                }
            printf("\n");
        }
}