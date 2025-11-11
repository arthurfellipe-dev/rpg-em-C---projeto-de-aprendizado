//
// Created by guest on 08/11/2025.
//

#ifndef EMPTY_HOLLOW_COMBATE_H
#define EMPTY_HOLLOW_COMBATE_H

int turno(struct jogador *player, struct inimigo *enemy, int boss);
int gerarMonstro(struct jogador *player, struct inimigo *inimigo);
int danoMonstro(struct inimigo *enemy);
void iniciarCombate(struct jogador *player);

#endif //EMPTY_HOLLOW_COMBATE_H