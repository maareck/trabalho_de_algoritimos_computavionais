#include <iostream>

int main(int argc, char** argv) {
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        int fileira = -1, acento = -1;
        char poltrona = ' ';
        char tipoPassagem = ' ';

        printf("\nEscolha o tipo de passagem (Econômico/Executivo): ");
        scanf(" %c", &tipoPassagem);

        printf("\nDigite a fileira (1-10): ");
        scanf("%d", &fileira);
        printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
        scanf(" %c", &poltrona);

        switch(poltrona){
            case 'A':
                acento = 0;
                break;
            case 'B':
                acento = 1;
                break;
            case 'C':
                acento = 2;
                break;
            case 'D':
                acento = 3;
                break;
            case 'E':
                acento = 4;
                break;
            case 'F':
                acento = 5;
                break;
            default:
                printf("\nPoltrona invalida");
                continue;
        }

        if (reserva[fileira-1][acento] == 'x') {
            printf("\nEsse assento já está reservado. Por favor, escolha outro.");
            continue;
        }

        if (tipoPassagem == 'E' || tipoPassagem == 'e') {
            if (poltrona == 'A' || poltrona == 'F') {
                printf("\nPoltrona não disponível para passagem Econômica. Por favor, escolha outra.");
                continue;
            }
        } else if (tipoPassagem == 'X' || tipoPassagem == 'x') {
            if (poltrona != 'A' && poltrona != 'F') {
                printf("\nPoltrona recomendada para passagem Executiva é A ou F. Deseja continuar? (s/n): ");
                char confirmar = ' ';
                scanf(" %c", &confirmar);
                if (confirmar == 'n' || confirmar == 'N') {
                    continue;
                }
            }
        }

        reserva[fileira-1][acento] = 'x';

        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");

        for (int x=0; x<10; x++){
            if (x<9) printf("\n\t0%d\t", x+1);
            else printf("\n\t%d\t", x+1);    
            for (int y=0; y<6; y++){
                printf("[%c] ", reserva[x][y]);
                if (y==2){
                    printf("\t");
                }
            }
        }
        printf("\n");

        printf("\nDeseja realizar outra reserva? (s/n): ");
        scanf(" %c", &continuar);

        if (continuar == 'n' || continuar == 'N') {
            printf("\nEncerrando o sistema de reservas...");
            break;
        }
    }

    return 0;
}