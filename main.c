#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char resposta_correta[30];
    char pergunta_usu[30];
} pergunta;

typedef struct {
    char nome[30];
    int pontuacao;
    char status_de_jogo[30];
} jogador;

void cadastro(pergunta resposta[], int contador_pergunta) {
    printf("Digite a Afirmacao: ");
    setbuf(stdin, NULL);
    fgets(resposta[contador_pergunta].pergunta_usu, 30, stdin);
    printf("A resposta eh verdadeira ou falsa (V/F):\n");
    scanf(" %c", &resposta[contador_pergunta].resposta_correta[0]);
    setbuf(stdin, NULL);
}

void cadastro_jogador(jogador lista[], int jogadores) {
    printf("Digite o nome do jogador: ");
    scanf("%s", lista[jogadores].nome);
    setbuf(stdin, NULL);
    strcpy(lista[jogadores].status_de_jogo, "Disponivel");
}

void iniciando_quizz(pergunta resposta[], int contador_pergunta, int opcao_jogador, jogador lista[]) {
    for (int i = 0; i < contador_pergunta; i++) {
        printf("A afirmacao eh: %s\n", resposta[i].pergunta_usu);
        printf("Coloque sua resposta: ");
        char resposta_usu;
        scanf(" %c", &resposta_usu);

        if ((resposta_usu == 'V' || resposta_usu == 'v') && (resposta[i].resposta_correta[0] == 'V' || resposta[i].resposta_correta[0] == 'v')) {
            printf("Resposta Correta!\n");
            lista[opcao_jogador - 1].pontuacao += 10;
        } else if ((resposta_usu == 'F' || resposta_usu == 'f') && (resposta[i].resposta_correta[0] == 'F' || resposta[i].resposta_correta[0] == 'f')) {
            printf("Resposta Correta!\n");
            lista[opcao_jogador - 1].pontuacao += 10;
        } else {
            printf("Resposta Incorreta!\n");
        }
    }
}

void verifica_cadastro_jogador(int contador_pergunta, int jogadores) {
    if (contador_pergunta == 0 && jogadores == 0)
        printf("Cadastre Um jogador e uma pergunta antes!\n");
    else if (contador_pergunta < 1)
        printf("Cadastre ao menos UMA pergunta!\n");
    else if (jogadores < 1)
        printf("Cadastre ao menos UM jogador\n");
}

void jogar(jogador lista[], int contador_pergunta, int jogadores, pergunta resposta[]) {
    for (int i = 0; i < jogadores; i++) {
        printf("[%d] %s [Status: %s]\n", i + 1, lista[i].nome, lista[i].status_de_jogo);
    }

    printf("Escolha um jogador para comecar!\n");
    int opcao_jogador;
    scanf("%d", &opcao_jogador);
    setbuf(stdin, NULL);

    if (opcao_jogador < 1 || opcao_jogador > jogadores) {
        printf("Opcao invalida!\n");
    } else if (strcmp(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel") == 0) {
        printf("O jogador ja jogou! Escolha outro.\n");
    } else {
        strcpy(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel");
        printf("O jogador escolhido foi: %s\n", lista[opcao_jogador - 1].nome);
        printf("==== Iniciando o quizz! ====\n");
        iniciando_quizz(resposta, contador_pergunta, opcao_jogador, lista);
    }
}

int main() {
    int contador_pergunta = 0;
    jogador lista[30];
    pergunta resposta[30];
    int opcao = 0;
    int perguntas = 0;
    int jogadores = 0;

    do {
        printf("\n==== Quiz V/F, trabalho mensal ====\n");
        printf("1. Cadastrar Questoes: (%d/10)\n", perguntas);
        printf("2. Cadastrar Jogador: (%d/5)\n", jogadores);
        printf("3. Jogar\n");
        printf("4. Mostrar Pontuacao!\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            if (perguntas < 10) {
                cadastro(resposta, contador_pergunta);
                if (resposta[contador_pergunta].resposta_correta[0] == 'V' ||
                    resposta[contador_pergunta].resposta_correta[0] == 'v' ||
                    resposta[contador_pergunta].resposta_correta[0] == 'F' ||
                    resposta[contador_pergunta].resposta_correta[0] == 'f') {
                    contador_pergunta++;
                    perguntas++;
                } else {
                    printf("Coloque uma resposta valida!\n");
                }
            } else {
                printf("Numero maximo de perguntas atingido!\n");
            }
            break;

        case 2:
            if (jogadores < 5) {
                cadastro_jogador(lista, jogadores);
                jogadores++;
            } else {
                printf("Numero maximo de jogadores atingido!\n");
            }
            break;

        case 3:
            if (contador_pergunta >= 1 && jogadores >= 1) {
                jogar(lista, contador_pergunta, jogadores, resposta);
            } else {
                verifica_cadastro_jogador(contador_pergunta, jogadores);
            }
            break;

        case 4:
            for (int i = 0; i < jogadores; i++) {
                 for ()
                printf("Pontuacao: %s %d\n", lista[i].nome, lista[i].pontuacao);
            }
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
//atualizacao dia 07_04. melhorei o  codigo como um todo.
