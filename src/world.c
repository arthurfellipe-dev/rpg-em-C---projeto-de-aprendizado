#include "rpg.h"
#include "world.h"

void titulo(){
    printf("\n\n");
    printf(" ███████╗███╗   ███╗██████╗ ████████╗██╗    ██╗\n");
    printf(" ██╔════╝████╗ ████║██╔══██╗╚══██╔══╝╚██╗ ██╔╝\n");
    printf(" █████╗  ██╔████╔██║██████╔╝   ██║    ╚████╔╝ \n");
    printf(" ██╔══╝  ██║╚██╔╝██║██╔═══╝   ██║     ╚██╔╝  \n");
    printf(" ███████╗██║ ╚═╝ ██║█║        ██║      ██║   \n");
    printf(" ╚══════╝╚═╝     ╚═╝╚═╝        ╚═╝      ╚═╝   \n");
    printf("          -=A Hollow Legacy=-           ");
}

void entradaBossFinal() {
    printf("███╗   ███╗ ██████╗ ███╗   ██╗ █████╗ ██████╗  ██████╗ █████╗\n");
    printf("████╗ ████║██╔═══██╗████╗  ██║██╔══██╗██╔══██╗██╔════╝██╔══██╗\n");
    printf("██╔████╔██║██║   ██║██╔██╗ ██║███████║██████╔╝██║     ███████║\n");
    printf("██║╚██╔╝██║██║   ██║██║╚██╗██║██╔══██║██╔══██╗██║     ██╔══██║\n");
    printf("██║ ╚═╝ ██║╚██████╔╝██║ ╚████║██║  ██║██║  ██║╚██████╗██║  ██║\n");
    printf("╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝\n");
    printf("\n");
    printf("\t\t\t\t O  M O N A R C A  D O  V A Z I O\n");
    printf("\t\t\t\t   ────────────★────────────\n");
    printf("\nVocê sente o tempo parar ao seu redor...\n");
    printf("Uma presença ancestral preenche o ar, densa como gravidade.\n");
    printf("Dos confins da dimensão esquecida... ele desperta.\n");
    printf("O Monarca do Vazio encara sua alma com olhos que já viram o fim de mundos.\n");
    printf("\nPrepare-se, esta será a sua batalha final.\n");
}

void finalDoJogo() {
    printf("\n");
    printf("\t==================================================\n");
    printf("\t\t\t ✦ VOCÊ DERROTOU O MONARCA ✦\n");
    printf("\t==================================================\n");
    printf("\tO silêncio preenche o mundo...\n");
    printf("\tA escuridão se retrai, como se temesse sua luz.\n");
    printf("\tVocê sente o peso de mil eras se erguer de seus ombros.\n");
    printf("\n\t✦ Mas será mesmo o fim?\n");
    printf("\t✦ Ou apenas o começo de uma nova era?\n");
    exit(0);
}

void morteBoss() {
    printf("\n      O Monarca do Vazio começa a se despedaçar em sombras...\n");
    printf("      Seus gritos ecoam em sua mente, mesmo após o silêncio retornar.\n");
    printf("      Você derrotou uma entidade ancestral... mas a escuridão observa.\n");
    finalDoJogo();
}

void introducaoCombate(){
    int cena = rand() % 3;

    printf("\n\t  =============================\n");
    printf("\t  |  Dimensão: Sombria        |\n");
    printf("\t  |  Ambiente: Floresta negra |\n");
    printf("\t  =============================\n\n");

    switch(cena){
    case 0:
        printf("\n\t  Você sente um arrepio na espinha...\n");
        printf("\n\t  Algo se aproxima entre as sombras.\n");
        break;
    case 1:
        printf("\n\t  A névoa se desfaz e um vulto surge.\n");
        printf("\n\t  Prepare-se, a batalha é inevitável!\n");
        break;
    case 2:
        printf("\n\t  Um grito rasga o silêncio ao seu redor.\n");
        printf("\n\t  Você encara o perigo de frente!\n");
        break;
    }
}

void introducaoLoja() {
    int cena2 = rand() % 3;

    printf("\n\t  =============================\n");
    printf("\t  |          LOJA             |\n");
    printf("\t  =============================\n\n");

    switch (cena2) {
    case 0:
        printf("\t  Após cruzar um vale sombrio, você avista uma luz tênue...\n");
        printf("\t  Uma loja misteriosa surge entre as árvores retorcidas.\n");
        printf("\t  O cheiro de antigas magias está no ar.\n");
        break;
    case 1:
        printf("\t  Depois de dias de viagem, seus pés finalmente pisam no solo firme de um pequeno povoado.\n");
        printf("\t  Ali, uma loja simples, mas cheia de segredos, aguarda por aventureiros como você.\n");
        break;
    case 2:
        printf("\t  Enquanto explorava uma trilha esquecida, você tropeça em uma clareira escondida.\n");
        printf("\t  No centro, uma loja encantada com mercadorias que parecem desafiar o tempo.\n");
        break;
    }
    printf("\n");
}

void verCreditos(){
    printf("\n      CRÉDITOS\n\n");
    printf(" Jogo criado por: Arthur Fellipe\n");
    printf(" Inspirado por: RPGs clássicos\n");
    printf(" Código feito em: Linguagem C\n");
    printf(" Desenvolvimento: 2025 - 2026\n");
    printf(" Obrigado por jogar EMPTY: A Hollow Legacy!\n");
}

void loja(struct jogador *player) {
    introducaoLoja();
    int escolhaLoja;

    printf(" Suas moedas de ouro: %d\n\n", player->ouro);
    printf(" Itens disponíveis:\n");
    printf(" 1 - Poção de Vida (20 moedas de ouro): Recupera 30 de vida\n");
    printf(" 2 - Poção de Energia (25 moedas de ouro): Recupera 50 de energia\n");
    printf(" 3 - Essência da Fúria (50 moedas de ouro): Aumenta permanentemente o dano em +5\n");
    printf(" 4 - Vontade do Monarca (60 moedas) espada comum\n");
    printf(" 5 - Quebradora de Eras (100 moedas) machado epico\n");
    printf(" 6 - Fragmento Ancestral (150 moedas) espada longa lendaria\n");
    printf(" 7 - Galho da Dimensao Esquecida (60 moedas) cajado comum\n");
    printf(" 8 - indice do Vazio (100 moedas) grimorio epico\n");
    printf(" 9 - Diario do Ultimo Monarca (150 moedas) tomo lendario\n");
    printf(" 10 - Sair da loja\n\n");
    printf(" Escolha um item: ");
    scanf("%d", &escolhaLoja);

    limpar_buffer();

    switch (escolhaLoja) {
    case 1:
        if (player->ouro >= 20) {
            player->inventario.pocao_vida++;
            player->ouro -= 20;
            printf(" Você comprou uma poção de vida!\n");
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 2:
        if (player->ouro >= 25) {
            player->inventario.pocao_energia++;
            player->ouro -= 25;
            printf(" Você comprou uma poção de energia!\n");
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 3:
        if (player->ouro >= 50) {
            player->bonus_dano += 5;
            player->ouro -= 50;
            printf(" Você absorveu a Essência da Fúria! Seu dano aumentou permanentemente em +5!\n");
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 4:
        if (player->classe != ESPADACHIM) {
            printf(" disponivel apenas para espadachins\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 60 ) {
            player->inventario.arma_equipada.raridade  = COMUM;
            player->inventario.arma_equipada.nome = "Vontade do Monarca";
            player->inventario.arma_equipada.dano_base = 20;
            player->ouro -= 60;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 5:
        if (player->classe != ESPADACHIM) {
            printf(" disponivel apenas para espadachins\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 100 ) {
            player->inventario.arma_equipada.raridade  = EPICA;
            player->inventario.arma_equipada.nome = "Quebradora de Eras";
            player->inventario.arma_equipada.dano_base = 30;
            player->ouro -= 100;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 6:
        if (player->classe != ESPADACHIM) {
            printf(" disponivel apenas para espadachins\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 150 ) {
            player->inventario.arma_equipada.raridade  = LENDARIA;
            player->inventario.arma_equipada.nome = "Fragmento Ancestral";
            player->inventario.arma_equipada.dano_base = 45;
            player->ouro -= 150;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }

        break;
    case 7:
        if (player->classe != MAGO) {
            printf(" disponivel apenas para magos\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 60 ) {
            player->inventario.arma_equipada.raridade  = COMUM;
            player->inventario.arma_equipada.nome = "Galho da Dimensao Esquecida";
            player->inventario.arma_equipada.dano_base = 20;
            player->ouro -= 60;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 8:
        if (player->classe != MAGO) {
            printf(" disponivel apenas para magos\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 100 ) {
            player->inventario.arma_equipada.raridade  = EPICA;
            player->inventario.arma_equipada.nome = "indice do Vazio";
            player->inventario.arma_equipada.dano_base = 30;
            player->ouro -= 100;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 9:
        if (player->classe != MAGO) {
            printf(" disponivel apenas para magos\n");
            sleep(1);
            break;
        }

        if (player->ouro >= 150 ) {
            player->inventario.arma_equipada.raridade  = LENDARIA;
            player->inventario.arma_equipada.nome = "Diario do Ultimo Monarca";
            player->inventario.arma_equipada.dano_base = 45;
            player->ouro -= 150;
            printf("você comprou %s", player->inventario.arma_equipada.nome);
            sleep(1);
        } else {
            printf(" Moedas de ouro insuficiente \n");
            sleep(1);
        }
        break;
    case 10:
        printf(" Você saiu da loja \n");
        sleep(1);
        break;
    default:
        printf(" Opção inválida \n");
        sleep(1);
        break;
    }
}

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
