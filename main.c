#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char resposta_correta [30];
    char pergunta_usu [30];

} pergunta;

typedef struct
{
    char nome [30];
    int pontuacao;
    char status_de_jogo [30];

} jogador;


int main()
{
    int contador_pergunta = 0;
    jogador lista[30];
    pergunta resposta[30];
    int opcao =0;
    int opcao_jogador =0;
    int perguntas =0;
    int jogadores = 0;
    char resposta_usu = 0;

    do
    {

        printf("\n==== Quiz V/F, trabalho mensal ====\n");
        printf("1. Cadastrar Questoes: (%d/10)\n", perguntas);
        printf("2. Cadastrar Jogador: (%d/5)\n", jogadores);
        printf("3. Jogar\n");
        printf("4. Mostrar Pontuacao!\n");
        printf("5. Sair\n");

        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            if (perguntas < 10)
            {
                printf("Digite a Afirmacao\n");
                setbuf(stdin, NULL);
                fgets(resposta[contador_pergunta].pergunta_usu, 30, stdin);

                printf("A resposta eh verdadeira ou falsa (V/F)?\n");
                scanf(" %c", &resposta[contador_pergunta].resposta_correta[0]);
                if (resposta[contador_pergunta].resposta_correta[0] == 'V' ||
                        resposta[contador_pergunta].resposta_correta[0] == 'v' ||
                        resposta[contador_pergunta].resposta_correta[0] == 'F' ||
                        resposta[contador_pergunta].resposta_correta[0] == 'f')
                {
                    setbuf(stdin, NULL);
                    contador_pergunta++;
                    perguntas++;
                }
                else
                    printf("Coloque uma respota valida!\n");
            }
            else
            {
                printf("Numero maximo de perguntas atingidas!\n");
            }
            break;

        case 2:

            if (jogadores < 5)

            {
                printf("Digite o nome do jogador:\n");
                scanf("%s", lista[jogadores].nome );
                setbuf(stdin, NULL);
                strcpy(lista[jogadores].status_de_jogo, "Disponivel");

                jogadores++;
            }
            else
            {
                printf("numero maximo de jogadores atingido!\n");
            }

            break;

        case 3:

            if (contador_pergunta >=1 && jogadores >= 1)
            {

                for (int i = 0; i < jogadores; i++)
                {
                    printf(" [%d] %s [Status: %s]\n", i + 1, lista[i].nome, lista[i].status_de_jogo);
                }

                printf("Escolha um jogador para comecar!\n");
                scanf("%d", &opcao_jogador);
                if (opcao_jogador < 1  || opcao_jogador > jogadores)
                {
                    printf("Escola uma opcao valida!\n");
                }

                else
                {

                    strcpy(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel");
                    if (strcmp(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel") == 0)
                    {
                        printf("O jogador ja jogou!, agora escolha outro.\n");

                    }
                    else
                    {
                        printf("O jogador escolhido foi: %s\n",
                               lista[opcao_jogador - 1].nome);


                        printf(" ==== Iniciando o quizz! ==== \n");

                        for (int i = 0; i < contador_pergunta; i++)
                        {
                            printf("A afirmacao eh: %s\n", resposta[i].pergunta_usu);
                            printf("Coloque sua resposta:\n");
                            scanf(" %c", &resposta_usu);

                            if (resposta_usu == resposta[i].resposta_correta[0])
                            {
                                printf("Resposta Correta!\n");
                                lista[opcao_jogador - 1].pontuacao += 10;

                            }
                            else
                            {
                                printf("Resposta Incorreta!\n");
                            }
                        }

                    }

                }

            }
            else if(contador_pergunta == 0 && jogadores == 0)
            {
                printf("Cadastre Um jogador e uma pergunta antes!\n");
            }
            else if (contador_pergunta < 1)
            {
                printf("Cadastre ao menos UMA pergunta!\n");
            }
            else if (jogadores < 1)
            {
                printf("Cadastre ao menos UM jogador\n");
            }

            break;

        case 4:
            printf("A pontuacao atual eh:");

            break;
        default:
            printf("Coloque uma resposta valida!\n");

        }

    }
    while (opcao != 5);

    return 0;
}
