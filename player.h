//
// Created by guest on 08/11/2025.
//

#ifndef EMPTY_HOLLOW_PLAYER_H
#define EMPTY_HOLLOW_PLAYER_H
#include "rpg.h"

void playerClasse(struct jogador *player);
void verStatus(struct jogador *player);
void imprimirLevelUp(struct jogador *player);
int dano(struct jogador *player);
void imprimirCritico();
#endif //EMPTY_HOLLOW_PLAYER_H