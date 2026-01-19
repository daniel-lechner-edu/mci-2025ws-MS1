/**
4.3 Rechner (25%)
Im Rahmen von Aufgabe 2.2 von Übungsblatt 2 haben Sie bereits einen Rechner implementiert, welcher zwei Zahlen und die dazugehörige Operation via Kommandozeilenparameter eingelesen und verarbeitet hat. Für diese Aufgabe sollen Sie ein Programm implementieren, welches die gewünschten Daten von stdin einliest. Außerdem soll das Programm in der Lage sein beliebig oft Berechnungen durchzuführen, bis es zu einem Abbruch von Seiten des Benutzers kommt. Hier ein beispielhafter Programmablauf:

> Geben Sie Zahl 1 ein:
12
> Geben Sie die Operation ein:
+
> Geben Sie Zahl 2 ein:
5
> Ergebnis: 17
> Geben Sie Zahl 1 ein:
43
> Geben Sie die Operation ein:
blabla
> Falsche Eingabe!
> Geben Sie Zahl 1 ein:
7
> Geben Sie die Operation ein:
/
> Geben Sie Zahl 2 ein:
2
> Ergebnis: 3.5
> Geben Sie Zahl 1 ein:
exit
> Rechner wird geschlossen


Was gibt es zu beachten:

Der Benutzer soll seine Daten exakt nach dem obigen Schema eingeben können.
Bei Eingabe von exit soll der Rechner jederzeit beendet werden können (Sollte dies nicht funktionieren, kann es zu Schwierigkeiten beim automatischen Testen Ihres Rechners kommen).
Der Rechner soll die Operationen +,-,* und / für Integer unterstützen.
Bei einer Division kann es zu einer Dezimalzahl (z.B. 3,5) als Ergebnis kommen.
Kommt es zu einer Eingabe, welche nicht den Erwartungen enspricht (kein Integer oder keine Rechenoperation), dann soll eine Fehlermeldung auf stderr ausgegeben werden (Wichtig: Dabei müssen die Worte Falsche Eingabe verwendet werden). Die Programmausführung soll dabei jedoch nicht abgebrochen werden, stattdessen soll der Benutzer wieder dazu aufgefordert werden die erste Zahl für eine neue Berechnung einzugeben.
Sie können gerne Ihre Quellcode- bzw. Header-Dateien aus Übung 2.2 wiederverwenden.
Implementieren Sie Ihr Programm in der Datei calculator.c. Wenn Sie Quellcode-Dateien aus früheren Übungen direkt weiterverwenden, ist es wichtig, dass Sie in die untere Zelle einen korrekten Befehl zum kompilieren eingeben, da sonst die automatischen Tests nicht funktionieren.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("> Geben Sie Zahl 1 ein:\n");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("> Rechner wird geschlossen\n");
            break;
        }

        char *endptr;
        int num1 = strtol(input, &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }

        printf("> Geben Sie die Operation ein:\n");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("> Rechner wird geschlossen\n");
            break;
        }

        if (strlen(input) != 1 || (input[0] != '+' && input[0] != '-' && input[0] != '*' && input[0] != '/')) {
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }

        char op = input[0];

        printf("> Geben Sie Zahl 2 ein:\n");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("> Rechner wird geschlossen\n");
            break;
        }

        int num2 = strtol(input, &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "> Falsche Eingabe!\n");
            continue;
        }

        if (op == '+') {
            printf("> Ergebnis: %d\n", num1 + num2);
        } else if (op == '-') {
            printf("> Ergebnis: %d\n", num1 - num2);
        } else if (op == '*') {
            printf("> Ergebnis: %d\n", num1 * num2);
        } else if (op == '/') {
            if (num2 == 0) {
                fprintf(stderr, "> Falsche Eingabe!\n");
                continue;
            }
            if (num1 % num2 == 0) {
                printf("> Ergebnis: %d\n", num1 / num2);
            } else {
                printf("> Ergebnis: %.1f\n", (double)num1 / num2);
            }
        }
    }

    return 0;
}
