#include  "rpg.h"
#include "player.h"
#include "combate.h"
#include "world.h"
#include "itens.h"

int turno(struct jogador *player, struct inimigo *enemy, int boss) {
    int escolhaAtacar = 0;
    printf("\n\n1-Atacar\n");
    printf("2-Usar poção\n");
    printf("3-fugir\n");
    scanf("%d", &escolhaAtacar);

    limpar_buffer();

    switch(escolhaAtacar) {
    case 1:
        habilidade(player);
        dano(player);

        enemy->vida -= player->dano;

        if(enemy->vida <= 0) {
            enemy->vida = 0;
            printf("\n\t  Parábens!! Você derrotou o inimigo\n");
            sleep(2);

            int geração_ouro = rand() % 10 + 15;
            int geração_xp = rand() % 25 + 20;
            player->ouro += geração_ouro;
            player->xp += geração_xp;
            printf("\t  Você ganhou %d moedas de ouro e %d de XP!\n", geração_ouro, geração_xp);

            if (player->xp >= player->nivel * 60) {
                player->nivel++;
                player->xp = 0;
                player->vida += 20;
                player->energia += 20;
                imprimirLevelUp(player);
            }

            if (enemy->tipo == BOSS) {
                morteBoss();
            }

            return 0;
        }
        else {

            printf("\n\n\t  %s, causou %.2f de dano no inimigo", player->nome, player->dano);
            if (enemy->tipo != BOSS)
                printf("\n\t  Vida do inimigo: %d\n", enemy->vida);
            enemy->dano = danoMonstro(enemy);
            player->vida -= enemy->dano;
            printf("\n\t  O inimigo ataca e causa %d de dano!\n", enemy->dano);
            sleep(1);
            printf("\t  Sua vida atual: %d\n", player->vida);

            if (player->vida <= 0) {
                printf("\nVocê foi derrotado pelo inimigo...\n");
                exit(0);
            }
        }
        break;
    case 2:
        int escolha_pocao;
        printf("\n1-usar poção de vida\n2-usar poção de energia\n");
        scanf("%d", &escolha_pocao);

        limpar_buffer();

        if (escolha_pocao == 1 && player->inventario.pocao_vida > 0){
            printf("\nPoção usada com sucesso\n");
            sleep(1);
            player->inventario.pocao_vida--;
            player->vida += 30;
        } else if(escolha_pocao == 1 && player->inventario.pocao_vida <= 0)
            printf("\nVocê não tem poções de vida disponíveis");
            sleep(1);
        if (escolha_pocao == 2 && player->inventario.pocao_energia > 0){
            printf("\nPoção usada com sucesso\n");
            sleep(1);
            player->inventario.pocao_energia--;
            player->energia += 50;
        } else if(escolha_pocao == 2 && player->inventario.pocao_energia <= 0)
            printf("\nVocê não tem poções de energia disponíveis");
        break;
    case 3:
        printf("\n\t  você fugiu");
        sleep(1);
        return 0;
        break;
    default:
        printf("invalido");
        break;
    }


    return 1;
}

int danoMonstro(struct inimigo *enemy){
    if (enemy->tipo == FRAGMENTO)
        return rand() % 10 + 5;
    else if (enemy->tipo == ESPECTRO)
        return rand() % 15 + 10;
    else if (enemy->tipo == ECO)
        return rand() % 20 + 10;
    else if (enemy->tipo == ARAUTO)
        return rand() % 35 + 20;
    else if (enemy->tipo == BOSS){
        int especial = rand() % 4;
        if (especial == 0) {
            printf("\n      O Monarca do Vazio conjura o RUGIDO DO ABISMO!\n");
            printf("      Você sente sua alma ser esmagada...\n");
            return rand() % 40 + 30;
        } else {
            return rand() % 25 + 20;
        }
    }
    return 0;
}

int gerarMonstro(struct jogador *player, struct inimigo *enemy){
    int gerar_inimigo = 0;
    gerar_inimigo = rand() % 10;

    if (player->nivel >= 5) {
        enemy->vida = 1000;
        enemy->tipo = BOSS;
        entradaBossFinal();
        printf("\n\t  Vida do Boss: desconhecida\n");
        return 1;
    } else if (gerar_inimigo == 9 && player->nivel >= 3){
        enemy->vida = 400;
        enemy->tipo = ARAUTO;
        printf("\n\t  ─── ᚏ O Arauto do Vazio ᚏ ───  \n");
        printf("\t  vida do boss: %d\n", enemy->vida);
    } else if (gerar_inimigo >= 0 && gerar_inimigo <= 2){
        enemy->vida = 100;
        enemy->tipo = FRAGMENTO;
        printf("\n\t  Um fragmento do vazio!! Fique calmo eles são seres fracos\n");
        printf("\t  Vida do inimigo: %d\n", enemy->vida);
    } else if (gerar_inimigo >= 3 && gerar_inimigo <= 5 ){
        enemy->vida = 150;
        enemy->tipo = ESPECTRO;
        printf("\n\t  Um espectro rastejante!! Tome cuidado\n");
        printf("\t  Vida do inimigo: %d\n", enemy->vida);
    } else if (gerar_inimigo >= 6 && gerar_inimigo <= 9) {
        enemy->vida = 200;
        enemy->tipo = ECO;
        printf("\n\t  Um eco das almas!! Quer mesmo correr esse risco? \n");
        printf("\t  Vida do inimigo: %d\n", enemy->vida);
    }

    return 0;
}

void iniciarCombate(struct jogador *player) {
    struct inimigo enemy;
    int statusLuta = 1;
    int isBoss = 0;

    introducaoCombate();

    isBoss = gerarMonstro(player, &enemy);

    while (statusLuta == 1) {
        statusLuta = turno(player, &enemy, isBoss);
    }
}