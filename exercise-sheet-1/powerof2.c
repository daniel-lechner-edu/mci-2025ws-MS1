/*
1.4 Zweierpotenzen (25%)
Implementieren Sie ein Programm, welches für einen beliebigen positiven Integer ermitteln kann, ob dieser eine Zweierpotenz (20, 21, 22, 23,...) ist. Der zu untersuchende Integer soll dabei als Kommandozeilenparameter an das Programm übergeben werden. Falls es sich bei dem Integer um eine Zweierpotenz handelt, dann soll der entsprechende Exponent ausgegeben werden (z.B. für 32 soll 5 ausgegeben werden, weil 25= 32). Handelt es sich um keine Zweierpotenz, dann soll keinerlei Ausgabe erfolgen.

Speichern Sie Ihre Lösung in der Datei powerof2.c ab und laden Sie diese auf JupyterHub in denselben Ordner wie den Übungszettel hoch.

%%bash
​
# Schreiben Sie in diese Zelle den Befehl der dafür nötig ist um Ihr Programm zu kompilieren.
# Beachten Sie dabei, dass der Name Ihres ausführbaren Programms "powerof2" sein sollte.
# z.B. gcc -Wall -Werror -o powerof2 mein_quellcode.c
​
​
# DEINE ANTWORT HIER
# Weisen Sie der untenstehenden Variable den Wert True zu, sobald Sie die Aufgabe erfolgreich erledigt haben!
​
# Datentyp: bool
exercise_1_4_solved = False
%%bash
​
# Benutzen Sie diese Zelle um Ihr Ergebnis zu testen.
# Damit diese Zelle ausgeführt werden kann, müssen Sie zuerst Ihr Programm erfolgreich kompilieren.
​
./powerof2 32
%%bash
​
# Benutzen Sie diese Zelle um Ihr Ergebnis zu testen.
# Damit diese Zelle ausgeführt werden kann, müssen Sie zuerst Ihr Programm erfolgreich kompilieren.
​
./powerof2 7
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <positive integer>\n", argv[0]);
        return 1;
    }
    int number = atoi(argv[1]);
    if (number <= 0) {
        return 0; // Keine Ausgabe für nicht-positive Zahlen
    }
    int exponent = 0;
    int power_of_two = 1; // 2^0
    while (power_of_two < number) {
        power_of_two *= 2;
        exponent++;
    }
    if (power_of_two == number) {
        printf("%d\n", exponent);
    }
    return 0;
}