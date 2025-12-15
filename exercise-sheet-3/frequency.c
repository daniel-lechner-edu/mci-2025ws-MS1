/**
3.4 Häufigkeitsberechnung mit Pointerarithmetik (21%)
Implementieren Sie ein Programm, welches eine Zeichenfolge als Kommandozeilenparameter einliest und anschließend für diese Zeichenfolge die Häufigkeit der einzelnen Zeichen in sortierter Form ausgibt (in Reihenfolge ihres Vorkommens in der ASCII-Tabelle). Wichtig: Verwenden Sie dafür Pointerarithmetik! Hier eine beispielhafte Ausgabe für den Kommandozeilenparameter Hello World!:

> Zeichen: ' ' - Häufigkeit: 1
> Zeichen: '!' - Häufigkeit: 1
> Zeichen: 'H' - Häufigkeit: 1
> Zeichen: 'W' - Häufigkeit: 1
> Zeichen: 'd' - Häufigkeit: 1
> Zeichen: 'e' - Häufigkeit: 1
> Zeichen: 'l' - Häufigkeit: 3
> Zeichen: 'o' - Häufigkeit: 2
> Zeichen: 'r' - Häufigkeit: 1

Verwenden Sie bei Ihrer Ausgabe obiges Format, d.h. Zeilenumbruch nach jedem Eintrag. Nur Zeichen welche in der Zeichenkette mindestens einmal vorkommen, sollen berücksichtigt werden.

Überprüfen Sie außerdem, ob der Benutzer genügend Kommandozeilenparameter angegeben hat, und wenn nicht, geben Sie eine entsprechende Fehlermeldung aus und beenden das Programm mit einem Exit-Code ungleich 0.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Fehler: Bitte genau einen Kommandozeilenparameter angeben.\n");
        return 1;
    }

    int frequency[128] = {0};
    char *ptr = argv[1];

    while (*ptr != '\0') {
        frequency[(int)*ptr]++;
        ptr++;
    }

    for (int i = 0; i < 128; i++) {
        if (frequency[i] > 0) {
            printf("Zeichen: '%c' - Häufigkeit: %d\n", i, frequency[i]);
        }
    }

    return 0;
}
