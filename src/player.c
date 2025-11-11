#include "rpg.h"
#include "player.h"

#include "world.h"

void playerClasse(struct jogador *player){
    int escolhaClasse;
    printf("\n\n\n\n      Bem vindo jogador, qual seu nome? \n\n");
    scanf("%s", player->nome);

    limpar_buffer();

    player->ouro = 0;
    player->xp = 0;
    player->vida = 500;
    player->energia = 150;
    player->dano = 0;
    player->nivel = 1;
    player->inventario.pocao_vida = 0;
    player->inventario.pocao_energia = 0;
    player->bonus_dano = 0;
    player->inventario.arma_equipada.nome = "maos nuas";
    player->inventario.arma_equipada.raridade = SEM_ARMA;
    player->inventario.arma_equipada.dano_base = 10;

    if (strcmp(player->nome, "CHAOS")== 0){
        printf("\nVOCÊ EVOLUIU PARA CLASSE SECRETA: Monarca do Vazio\n\n");
        player->vida *= 10;
        player->energia *= 10;
        player->ouro = 1000;
    } else {
        printf("\n      Escolha sua classe: \n\n");
        printf("0-Mago(menos vida, mais energia\n");
        printf("1-Espadachin(mais vida, menos energia\n");
        scanf("%d", &escolhaClasse);

        limpar_buffer();

        switch(escolhaClasse){
        case MAGO:
            player->classe = MAGO;
            player->vida -= 20;
            player->energia += 50;
            printf("\n %s, o(a) poderoso(a) Mago(a)!!\n", player->nome);
            break;
        case ESPADACHIM:
            player->classe = ESPADACHIM;
            player->vida += 50;
            player->energia -= 20;
            printf("\n %s, o(a) poderoso(a) Espadachin!!\n", player->nome);
            break;
        default:
            printf("\n Escolha invalida\n\n");
            break;
        }
    }
}

void verStatus(struct jogador *player) {
    printf("\n      STATUS\n\n");
    printf("Nome: %s\n", player->nome);
    printf("Vida: %d\n", player->vida);
    printf("Energia: %d\n", player->energia);
    printf("Moedas de ouro: %d\n", player->ouro);
    printf("Nivel: %d\n", player->nivel);
    printf("Poções de vida: %d\n", player->inventario.pocao_vida);
    printf("Poções de energia: %d\n", player->inventario.pocao_energia);
}

void imprimirLevelUp(struct jogador *player) {
    printf("\a");
    printf("\n");
    printf("         ' \n");
    printf("    * .   + \n");
    printf("       .    ' \n");
    printf("   '   L E V E L   U P !   * \n");
    printf("     .       '     . \n");
    printf("   +     . * \n");
    printf("             ' \n");
    printf("\n");
    printf("\n Você subiu para o nível %d! \n", player->nivel);
    sleep(2);
}

int dano(struct jogador *player){

    int dano_base_arma = player->inventario.arma_equipada.dano_base;

    int bonus_energia = 0;
    if (player->energia <= 100) {
        bonus_energia = 0;
    } else if(player->energia <= 200) {
        bonus_energia = 10;
    } else if (player->energia <= 300) {
        bonus_energia = 20;
    } else if (player->energia < 400) {
        bonus_energia = 30;
    } else {
        bonus_energia = 50;
    }

    int variacao = rand() % 10 + 1;

    player->dano = dano_base_arma + bonus_energia + variacao;

    int critico = (rand() % 100) + 1;

    if (critico <= 15){
        player->dano *= 1.5;
        imprimirCritico();
    }
    player->dano += player->bonus_dano;
    player->bonus_dano = 0;

    return player->dano;
}

void imprimirCritico() {
    printf("  *-------------------*\n");
    printf("  |   !!! CRÍTICO !!!   |\n");
    printf("  *-------------------*\n");
}
