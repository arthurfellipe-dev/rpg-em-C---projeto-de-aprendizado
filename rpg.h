#ifndef EMPTY_HOLLOW_RPG_H
#define EMPTY_HOLLOW_RPG_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "itens.h"

enum  classe{MAGO, ESPADACHIM};
enum  dificuldadeInimigo{FRAGMENTO, ESPECTRO, ECO, ARAUTO, BOSS};
enum RaridadeArma {SEM_ARMA,COMUM,EPICA,LENDARIA};

struct arma {
    const char *nome;
    enum RaridadeArma raridade;
    int dano_base;
};

struct inventario {
    int pocao_vida;
    int pocao_energia;
    struct arma arma_equipada;
};
struct jogador{
    char nome[30];
    int ouro, xp, nivel;
    int vida, energia;
    float dano;
    int bonus_dano;
    struct inventario inventario;

    int classe;
};
struct inimigo {
    int vida, dano;
    int tipo;
};

#endif //EMPTY_HOLLOW_RPG_H