#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_HORIZONTAL '-'
#define PAREDE_VERTICAL '|'
#define PILULA '*'

struct posicao {
    int x;
    int y;
};
typedef struct posicao POSICAO;

struct mapa {
    int linhas;
    int colunas;
    char** matriz;
};
typedef struct mapa MAPA;

void alocarMapa(MAPA* mapa);
void limparMapa(MAPA* mapa);
int procuraMapa(MAPA* mapa, POSICAO* posicao, char simbolo);
MAPA leMapa();
void desenhaMapa(MAPA* mapa);
void copiaMapa(MAPA* mapaCopia, MAPA* mapaOriginal);
void desenhaMapaSimples(MAPA* mapa);

#endif