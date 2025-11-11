#include "itens.h"
#include "rpg.h"
#include "player.h"
#include "world.h"
void habilidade(struct jogador *player) {
    int escolhaHab;

    printf("1-usar habilidade\n");
    printf("2-usar especial\n");
    printf("3-ataque comum\n");
    scanf("%d", &escolhaHab);

    limpar_buffer();

    switch (escolhaHab) {
        case 1:
            if (player->inventario.arma_equipada.raridade == SEM_ARMA) {
                printf("\nhabilidade não desbloqueada\n");
                printf("ataque comum usado\n");
                sleep(1);
                break;
            }

            if (player->inventario.arma_equipada.raridade == COMUM) {
                if (player->energia < 10) {
                    printf("energia baixa\n");
                    sleep(1);
                } else {
                    player->bonus_dano += 20;
                    player->energia -= 10;
                    printf("Habilidade usada\n");
                    sleep(1);
                }
            } else if (player->inventario.arma_equipada.raridade  == EPICA) {
                if (player->energia < 20) {
                    printf("energia baixa\n");
                } else {
                    player->bonus_dano += 30;
                    player->energia -= 20;
                }
            } else if (player->inventario.arma_equipada.raridade  == LENDARIA) {
                if (player->energia < 30) {
                    printf("energia baixa\n");
                } else {
                    player->bonus_dano += 40;
                    player->energia -= 30;
                }
            }
        break;

        case 2:
            if (player->inventario.arma_equipada.raridade == SEM_ARMA) {
                printf("habilidade não desbloqueada\n");
                printf("ataque comum usado\n");
                break;
            }

            if (player->inventario.arma_equipada.raridade  == COMUM) {
                if (player->energia < 20) {
                    printf("energia baixa\n");
                } else {
                    player->bonus_dano += 40;
                    player->energia -= 20;
                }

            } else if (player->inventario.arma_equipada.raridade  == EPICA) {
                if (player->energia < 40) {
                    printf("energia baixa\n");
                } else {
                    player->bonus_dano += 60;
                    player->energia -= 40;
                }
            } else if (player->inventario.arma_equipada.raridade  == LENDARIA) {
                if (player->energia < 60) {
                    printf("energia baixa\n");
                } else {
                    player->bonus_dano += 80;
                    player->energia -= 60;
                }
            }
        break;

        case 3:

            break;
    }
}