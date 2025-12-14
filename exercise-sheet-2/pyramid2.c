/**
2.1 Beliebige Pyramide (20%)
Nachdem Sie in Übungsblatt 1 ein Programm implementiert haben, welches Pyramiden aus Sternchen ausgegeben hat, ist es nun Ihre Aufgabe jenes Programm so abzuändern, sodass beliebig große Pyramiden ausgegeben werden können. Übergeben Sie dazu die Größe (= Anzahl Zeilen) der Pyramide als Kommandozeilenparameter an Ihr Programm. So soll beispielsweise eine Pyramide mit Kommandozeilenparameter 5 so aussehen:

    *  
   ***
  *****
 *******
*********

Überprüfen Sie auch, ob der Benutzer tatsächlich einen Kommandozeilenparameter übergeben hat. Wenn nicht, dann geben Sie eine aussagekräftige Fehlermeldung aus und beenden das Programm mit einem Exit Code ungleich 0.

Ihr Programm soll für jede natürliche Zahl eine gültige Ausgabe liefern. Achten Sie darauf, dass vor und nach der Pyramide keine leere Zeilen vorkommen. Implementieren Sie Ihr Programm in einer Daten namens pyramid2.c.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide pyramid size as argument\n");
        return 1;
    }

    int size = atoi(argv[1]);

    if (size <= 0) {
        fprintf(stderr, "Error: Size must be a positive number\n");
        return 1;
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < size - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
