#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE_INFERIOR_PADRAO 0
#define LIMITE_SUPERIOR_PADRAO 99

#define TENTATIVAS_FACIL 20
#define TENTATIVAS_MEDIO 15
#define TENTATIVAS_DIFICIL 6

int main() {
    int jogarNovamente;

    do {
        printf("\n\n");
        printf("          P  /_\\  P                              \n");
        printf("         /_\\_|_|_/_\\                            \n");
        printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
        printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
        printf("    |\" \"  |  |_|  |\"  \" |                     \n");
        printf("    |_____| ' _ ' |_____|                         \n");
        printf("          \\__|_|__/                              \n");
        printf("\n\n");

        int chute;
        int acertou;
        int nivel;
        int totaldetentativas;

        double pontos = 1000;
        int limite_inferior, limite_superior;
        int ultimoChute = -1;  // Inicializa com um valor que não será um chute válido

        printf("Digite o limite inferior para o intervalo de numeros (padrao: %d): ", LIMITE_INFERIOR_PADRAO);
        scanf("%d", &limite_inferior);

        printf("Digite o limite superior para o intervalo de numeros (padrao: %d): ", LIMITE_SUPERIOR_PADRAO);
        scanf("%d", &limite_superior);

        srand(time(0));
        int numerosecreto = rand() % (limite_superior - limite_inferior + 1) + limite_inferior;

        printf("Qual o nivel de dificuldade?\n");
        printf("(1) Facil (2) Medio (3) Dificil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        switch (nivel) {
            case 1:
                totaldetentativas = TENTATIVAS_FACIL;
                break;
            case 2:
                totaldetentativas = TENTATIVAS_MEDIO;
                break;
            default:
                totaldetentativas = TENTATIVAS_DIFICIL;
                break;
        }

        for (int i = 1; i <= totaldetentativas; i++) {
            printf("-> Tentativa %d de %d\n", i, totaldetentativas);
            printf("Chute um numero entre %d e %d: ", limite_inferior, limite_superior);
            scanf("%d", &chute);

            if (chute < limite_inferior || chute > limite_superior) {
                printf("Voce deve chutar um numero dentro do intervalo especificado.\n");
                i--;
                continue;
            }
            if (chute == ultimoChute) {
                printf("Voce ja chutou esse numero. Tente novamente.\n");
                i--;
                continue;
            }

            acertou = chute == numerosecreto;
            ultimoChute = chute;  // Atualiza o último chute

            if (acertou) {
                break;
            } else if (chute > numerosecreto) {
                printf("\nSeu chute foi maior do que o numero secreto!\n\n");
            } else {
                printf("\nSeu chute foi menor do que o numero secreto!\n\n");
            }

            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;
        }

        printf("\n");
        if (acertou) {
            printf("Parabens! Voce acertou!\n");
            printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
        } else {
            printf("Voce perdeu! Tente novamente!\n\n");
        }

        printf("Deseja jogar novamente? (Digite 1 para sim, 0 para sair): ");
        scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);
    return 0;
}