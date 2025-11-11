# rpg-em-C---projeto-de-aprendizado
![Licença: MIT-NC](https://img.shields.io/badge/Licen%C3%A7a-MIT--NC-blue)

0. Compilação

## Compilação manual
gcc src/*.c -I include -o rpg
./rpg

## Compilação via Makefile
make run

1. Introdução


Esse projeto foi desenvolvido inicialmente apenas por diversão
e aplicar alguns conceitos que eu estava estudando na época tudo junto.

foi bem legal desenvolver ele, obvio que deu bastante problema
principalmente pela minha falta de conhecimento(no inicio estava tudo no main
com mais de 30 variáveis globais e sem struct)

aprendi bastante, e é isso que importa, algumas partes não lógicas foram feitas por ia,
quais vou deixar claro mais a frente


2. Estrutura do Projeto


depois de finalmente estudar mais dividi em módulos:

main.c {

    básicamente o main, ele controla o menu principal de escolha do player,
    se vai lutar, ir pra loja etc. Também chama a função titulo(), playerClasse()
    e cria a variável struct jogador player.
}

player.c {

    contém as funções mais relacionadas ao player em si,
    funções:

        void playerClasse(struct jogador *player);
            responsável pela escolha da classe do player e pela inicialização dos status

        void verStatus(struct jogador *player);
            mostrar os status(vida, energia etc)

        void imprimirLevelUp(struct jogador *player);
            imprimida quando o player sobe de nível

        int dano(struct jogador *player);
            calcula o dano que o player causa com base na energia, arma etc

        void imprimirCritico();
            imprimida quando o dano é critico
}

combate.c {

    responsável pelo fluxo de combate, que acaba quando o player morre ou mata o inimigo,
    funções:
        int turno(struct jogador *player, struct inimigo *enemy, int boss);
            controla a escolha durante o ataque, gera xp e ouro, retorna 0 se
            monstro morrer ou fugir e 1 se não

        int gerarMonstro(struct jogador *player, struct inimigo *inimigo);
            gera o monstro de forma pseudo-aleatória, com base no tipo
            retorna 1 se for boss

        int danoMonstro(struct inimigo *enemy);
            gera o dano do monstro com base no tipo e especial do boss

        void iniciarCombate(struct jogador *player);
            controla o turno com base no retorno e verifica se é boss ou não para
            evitar gerar 2 inimigos ao mesmo tempo.
}

world.c {
    funções mais gerais da história e estética do jogo
    funções:
        void limpar_buffer();
            limpa o buffer para evitar bugs

        void titulo();
            imprime titulo do jogo

        void entradaBossFinal();
            imprime mensagem de entrada do boss

        void finalDoJogo();
            imprime mensagem final

        void introducaoCombate();
            mensagem que varia quando combate inicia

        void introducaoLoja();
            mensagem que varia quando entra na loja

        void loja(struct jogador *player);
            contém poções de vida, energia, dano e itens com habilidades de causar dano

        void verCreditos();
            creditos do jogo

        void morteBoss();
            imprime mensagem de morte do boss
}


rpg.h {

    cabeçalho que contem os #includes gerais (stdio etc) estruturas, enums do jogo

}

3. Fluxo Geral do Jogo


    titulo é imprimido, jogador escolhe classe e tem status iniciados, jogador vai pro menu principal
    e escolhe o que deseja fazer. Após derrotar o boss o jogo acaba

4. Funções geradas por ia


    como disse apenas funções não lógicas foram por ia, pois o intuito sempre foi praticar,
    aprender e fazer algo que gosto:

    void entradaBossFinal();
    void finalDoJogo();
    void introducaoCombate();
    void introducaoLoja();
    void morteBoss();
    void imprimirLevelUp(struct jogador *player);
    void imprimirCritico();

    não vi problema em usar nessas partes pois, são apenas printf, foi uma questão apenas de otimização de tempo

5. Possíveis Expansões Futuras


    se esse tópico estiver vazio, implantei tudo que queria, caso não, ficaria feliz em ter seu apoio!!

    *salvar progresso(estou estudando ainda)
   
    *dimenções diferentes
   
    *inimigos mais inteligentes com habilidades diferentes (não só bonecos que causam dano)
   
    *mais classes
   
    *arte ancii
   
    *habilidades (além das armas)
   
    *mais inimigos
   
    *itens dropaveis
   
    *boss secreto
   
    *titulos
   
    *coisas como veneno, congelar etc
   
    *combos de ataque
   
    *sistema de missões
   
    *printfs de forma que seja letra por letra (usleep)
   
    *CORES

7. Sobre mim
 
    sou um estudante do IFBA, me chamo ########, bom, não posso dizer,
    digamos que meu nome em jogos seja Rapozitav2 (minecraft etc)

