#include <stdio.h>
#include <stdlib.h>

void programma_corretto() {
    int vector[10], i, j, k;
    int swap_var;

    printf("Inserire 10 interi:\n");

    for (i = 0; i < 10; i++) {
        int c = i + 1;
        printf("[%d]:", c);
        while (scanf("%d", &vector[i]) != 1) {
            printf("Input non valido. Inserisci un numero intero: ");
            while (getchar() != '\n');  // Pulisce il buffer di input
        }
    }


    for (j = 0; j < 10 - 1; j++) {
        for (k = 0; k < 10 - j - 1; k++) {
            if (vector[k] > vector[k + 1]) {
                swap_var = vector[k];
                vector[k] = vector[k + 1];
                vector[k + 1] = swap_var;
            }
        }
    }

    printf("Il vettore ordinato è:\n");
    for (j = 0; j < 10; j++) {
        int g = j + 1;
        printf("[%d]:", g);
        printf("%d\n", vector[j]);
    }
}

void programma_errore() {
    int vector[10], i, j, k,swap_var;

    printf("Inserire 11 interi (questo causerà un errore di segmentazione):\n");

    for (i = 0; i <= 10; i++) {
        int c = i + 1;
        printf("[%d]:", c);
        while (scanf("%d", &vector[i]) != 1) {
            printf("Input non valido. Inserisci un numero intero: ");
            while (getchar() != '\n');  // Pulisce il buffer di input
        }
    }


    for (j = 0; j < 10 - 1; j++) {
        for (k = 0; k < 10 - j - 1; k++) {
            if (vector[k] > vector[k + 1]) {
                swap_var = vector[k];
                vector[k] = vector[k + 1];
                vector[k + 1] = swap_var;
            }
        }
    }

    printf("Il vettore ordinato è:\n");
    for (j = 0; j <= 10; j++) {
        int g = j + 1;
        printf("[%d]:", g);
        printf("%d\n", vector[j]);
    }

    printf("Come puoi ben vedere, utilizzando lo stesso criterio del programma corretto, il vettore sarà ordinato solo per i primi 10 elementi, ");
    printf("l'11esimo numero, a prescindere dal suo valore, \nsi troverà appositamente all'ultimo posto per mostrare l'errore di segmentazione");
    printf("e quindi far vedere che non si trova dentro il vettore da 10 elementi.");

}

int main() {
    int scelta;
    int continua = 1;  // Variabile per controllare l'uscita dal ciclo

    while (continua) {
        printf("Caro utente, puoi scegliere tra 2 opzioni, avere il programma che va in errore o quello corretto.\n");
        printf("A te la scelta!\n");
        printf("Seleziona un'opzione:\n");
        printf("1. Esegui il programma corretto\n");
        printf("2. Esegui il programma con errore\n");
        printf("Scelta: ");
        if (scanf("%d", &scelta) != 1) {
            printf("Input non valido. Inserisci un numero.\n");
            while (getchar() != '\n');  // Pulisce il buffer
            continue;
        }

        if (scelta == 1) {
            printf("\nEsecuzione del programma corretto:\n");
            programma_corretto();
            continua = 0;  // Imposta la variabile a 0 per uscire dal ciclo
        } else if (scelta == 2) {
            printf("\nEsecuzione del programma con errore di segmentazione:\n");
            programma_errore();
            continua = 0;  // Imposta la variabile a 0 per uscire dal ciclo
        } else {
            printf("Scelta non valida. Riprova.\n");
        }
    }

    return 0;
}

