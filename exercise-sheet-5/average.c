/**
5.1 Durchschnitt mit dynamischer Speicherverwaltung (50%)
Implementieren Sie ein Programm, welches den Durchschnitt aller Elemente eines Integer-Arrays ausgibt. Der Benutzer soll jedes einzelne Array-Element über stdin eingeben. Im Gegensatz zu Aufgabe 3.3 soll der Speicher dieses Mal aber dynamisch verwaltet werden. Zu Beginn soll mit malloc Speicher für 5 Elemente (= Blockgröße) reserviert werden. Sobald dieser Speicher komplett befüllt ist, soll mit realloc Speicher für einen weiteren Block mit 5 Elementen reserviert werden. Wiederholen Sie diesen Vorgang so oft wie nötig.

Wird etwas anderes als ein Integer eingegeben, dann soll diese Eingabe ignoriert und das Einlesen fortgesetzt werden. Sobald der Benutzer eine leere Zeile eingibt, soll das Einlesen beendet werden. Dann soll das Array an eine Funktion übergeben werden, welche den Durchschnitt der Elemente berechnet und ausgibt. Dabei soll exakt eine Nachkommastelle ausgegeben werden. Am Ende soll der alloziierte Speicher explizit wieder freigegeben werden. Ein Programmablauf könnte beispielweise so aussehen:

> Geben Sie die Elemente Ihres Arrays an:
> Element #1:
5
> Element #2:
1
> Element #3:
not a number
> Element #3:
3
> Element #4:

> Eingabe beendet.
> Der Durchschnitt Ihres Arrays ist: 3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 5
#define MAX_INPUT 100

void calculate_average(int* array, int count) {
    if (count == 0) {
        printf("> Der Durchschnitt Ihres Arrays ist: 0.0\n");
        return;
    }

    long long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += array[i];
    }

    double average = (double)sum / count;
    printf("> Der Durchschnitt Ihres Arrays ist: %.1f\n", average);
}

int main() {
    int capacity = BLOCK_SIZE;
    int count = 0;
    int* array = malloc(capacity * sizeof(int));

    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("> Geben Sie die Elemente Ihres Arrays an:\n");

    char input[MAX_INPUT];
    while (1) {
        printf("> Element #%d:\n", count + 1);

        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            break;
        }

        char* endptr;
        int num = strtol(input, &endptr, 10);

        if (*endptr != '\0') {
            continue;
        }

        if (count >= capacity) {
            capacity += BLOCK_SIZE;
            int* new_array = realloc(array, capacity * sizeof(int));
            if (!new_array) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(array);
                return 1;
            }
            array = new_array;
        }

        array[count] = num;
        count++;
    }

    printf("> Eingabe beendet.\n");
    calculate_average(array, count);

    free(array);
    return 0;
}
