#include "rpg.h"
#include "player.h"
#include "combate.h"
#include "world.h"
#include "itens.h"

int main() {
    srand(time(NULL));

    int escolhaPlay;
    struct jogador player;

    titulo();
    sleep(1);

    playerClasse(&player);

    do {
        printf("\n      Menu principal: \n\n");
        printf("1-Combate\n");
        printf("2-Loja\n");
        printf("3-Status\n");
        printf("4-Mudar dimenção\n");
        printf("5-Créditos\n");
        printf("6-Sair\n");
        scanf("%d", &escolhaPlay);

        limpar_buffer();

        switch(escolhaPlay) {
        case 1:
            iniciarCombate(&player);
            break;
        case 2:
            loja(&player);
            break;
        case 3:
            verStatus(&player);
            break;
        case 4:
            printf("\nem deselvolvimento(não sei fazer, AINDA");
            break;
        case 5:
            verCreditos();
            break;
        case 6:
            printf("\nobrigado por jogar");
            break;
        default:
            printf("inválido");
            break;
        }
    }while(escolhaPlay != 6);

    return 0;
}
