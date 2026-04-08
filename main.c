#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char resposta_correta[30];
    char pergunta_usu[30];
} pergunta;

typedef struct
{
    char nome[30];
    int pontuacao;
    char status_de_jogo[30];
} jogador;

void cadastro(pergunta resposta[], int contador_pergunta) //cadastro das  perguntas.
{
    printf("Digite a Afirmacao: ");
    setbuf(stdin, NULL);
    fgets(resposta[contador_pergunta].pergunta_usu, 30, stdin);
    printf("A resposta eh verdadeira ou falsa (V/F):");
    scanf(" %c", &resposta[contador_pergunta].resposta_correta[0]);
    setbuf(stdin, NULL);
}

void cadastro_jogador(jogador lista[], int jogadores) //cadastro  dos jogadores.
{
    printf("Digite o nome do jogador: ");
    scanf("%s", lista[jogadores].nome);
    setbuf(stdin, NULL);
    strcpy(lista[jogadores].status_de_jogo, "Disponivel");
    lista[jogadores].pontuacao = 0;
}

void iniciando_quizz(pergunta resposta[], int contador_pergunta, int opcao_jogador, jogador lista[]) // inicia o quizz, e compara se as respostas do usuario e  do jogador estao correspondentes.
{
    for (int i = 0; i < contador_pergunta; i++)
    {
        printf("\n A afirmacao eh: %s\n", resposta[i].pergunta_usu);
        printf("Coloque sua resposta: ");
        char resposta_usu;
        scanf(" %c", &resposta_usu);

        if ((resposta_usu == 'V' || resposta_usu == 'v') && (resposta[i].resposta_correta[0] == 'V' || resposta[i].resposta_correta[0] == 'v'))
        {
            printf("Resposta Correta!\n");
            lista[opcao_jogador - 1].pontuacao += 10;
        }
        else if ((resposta_usu == 'F' || resposta_usu == 'f') && (resposta[i].resposta_correta[0] == 'F' || resposta[i].resposta_correta[0] == 'f'))
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

void verifica_cadastro_jogador(int contador_pergunta, int jogadores)  //verifica se ha jogadores  e perguntas o suficiente  para entrar no quizz.
{
    if (contador_pergunta == 0 && jogadores == 0)
        printf("Cadastre Um jogador e uma pergunta antes!\n");
    else if (contador_pergunta < 1)
        printf("Cadastre ao menos UMA pergunta!\n");
    else if (jogadores < 1)
        printf("Cadastre ao menos UM jogador\n");
}

void jogar(jogador lista[], int contador_pergunta, int jogadores, pergunta resposta[]) //printa os  nomes dos jogadores, deixa o usuario escolher, verifica se o jogador ja jogou ou nao, se nao inicia o quizz com  a  funcao  iniciando_quizz
{
    for (int i = 0; i < jogadores; i++)
    {
        printf("[%d] %s [Status: %s]\n", i + 1, lista[i].nome, lista[i].status_de_jogo);
    }

    printf("Escolha um jogador para comecar!\n");
    int opcao_jogador;
    scanf("%d", &opcao_jogador);
    setbuf(stdin, NULL);

    if (opcao_jogador < 1 || opcao_jogador > jogadores)
    {
        printf("Opcao invalida!\n");
    }
    else if (strcmp(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel") == 0)
    {
        printf("O jogador ja jogou! Escolha outro.\n");
    }
    else
    {
        strcpy(lista[opcao_jogador - 1].status_de_jogo, "Indisponivel");
        printf("O jogador escolhido foi: %s\n", lista[opcao_jogador - 1].nome);
        printf("==== Iniciando o quizz! ====\n");
        iniciando_quizz(resposta, contador_pergunta, opcao_jogador, lista);
    }
}

void pontu_rank(jogador lista[], int jogadores, int ranking)// ve se ja foi jogado  o quizz, se sim, mostra a  pontuacao usando b ubble  sort e  ordena por ordem de  jogo, caso tenham dois jogadores  com a mesma  qtd d e pontos.
{

    if (ranking >= 1)
    {
        for (int i = 0; i < jogadores; i++)
        {
            for (int j = 0;  j < jogadores - 1 - i; j++)
            {
                if (lista[j].pontuacao < lista[j+1].pontuacao)
                {
                    jogador temp  = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < jogadores; i++)
        {
            printf("Pontuacao do jogador [%s] eh: %d\n", lista[i].nome, lista[i].pontuacao);
        }
    }
    else
    {
        printf("Primeiro Jogue o  quizz  ao  menos uma  vez!\n");
    }
}

int main()
{
    int contador_pergunta = 0; 
    jogador lista[30];
    pergunta resposta[30];
    int opcao = 0; //armazena a opcao  do jogador no  menu
    int perguntas = 0;  //controle de  qtd de perguntas.
    int jogadores = 0; //controle de qtd de jogadores
    int ranking = 0;  //serve  apenas  para nao deixar  ver o ranking sem ter jogado  uma vez ao menos.

    do
    {
        printf("\n==== Quiz V/F, trabalho mensal ====\n");
        printf("1. Cadastrar Questoes: (%d/10)\n", perguntas);
        printf("2. Cadastrar Jogador: (%d/5)\n", jogadores);            //Menu
        printf("3. Jogar\n");
        printf("4. Mostrar Pontuacao!\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (perguntas < 10)
            {
                cadastro(resposta, contador_pergunta);
                if (resposta[contador_pergunta].resposta_correta[0] == 'V' ||
                        resposta[contador_pergunta].resposta_correta[0] == 'v' ||   //verifica se a resposta cadastrada eh  v ou f, se for prossegue, se nao, nao.
                        resposta[contador_pergunta].resposta_correta[0] == 'F' ||
                        resposta[contador_pergunta].resposta_correta[0] == 'f')
                {
                    contador_pergunta++; //
                    perguntas++;  //add + 1 a cada pergunta cadastrada,  no print do  menu, mostrando quntos ja foram cadastradas.
                }
                else
                {
                    printf("Coloque uma resposta valida!\n");
                }
            }
            else
            {
                printf("Numero maximo de perguntas atingido!\n");
            }
            break;

        case 2:
            if (jogadores < 5)
            {
                cadastro_jogador(lista, jogadores); //puxa o cadastro la de cima.
                jogadores++;   //add  mais um a quantidade de jogadores  cadastrados
            }
            else
            {
                printf("Numero maximo de jogadores atingido!\n");
            }
            break;

        case 3:
            if (contador_pergunta >= 1 && jogadores >= 1) //se ja tem um  jogador e  uma pergunta, inicia a funcao jogar.
            {
                jogar(lista, contador_pergunta, jogadores, resposta);
                ranking++; //diz que agora  sim, alguem ja  jogoumalguma vez e o ranking esta aberto.
            }
            else
            {
                verifica_cadastro_jogador(contador_pergunta, jogadores);  // se nao ha  jogadores ou perguntas oi  bastatnte puxa a  funcao.
            }
            break;

        case 4:
            pontu_rank(lista, jogadores, ranking); //mostra o ranking  com bubblesort da funcao chamada.
            break;

        default:
            if (opcao  > 5 || opcao < 0)
                printf("Opcao invalida!"); //se opcao  for maior q 5  e menor que 0, printa que eh invalida.
        }
    }
    while (opcao != 5);  //roda o  codigo ate  que o usuario  aperte  5.

    return 0;
}
