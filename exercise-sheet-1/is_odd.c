/*1.2 Bestimmung von ungeraden Zahlen (25%)
Implementieren Sie ein Programm, welche für jede beliebige Integer-Zahl bestimmen kann, ob diese ungerade ist. Die zu untersuchende Zahl soll mittels Kommandozeilenparameter an das Programm übergeben werden. Falls eine Zahl ungerade ist, soll die Zeichenkette "true" ausgegeben werden. Falls es sich um eine gerade Zahl handelt, dann die Zeichenkette "false".

Speichern Sie Ihre Lösung in der Datei is_odd.c ab und laden Sie diese auf JupyterHub in denselben Ordner wie den Übungszettel hoch.

%%bash
​
# Schreiben Sie in diese Zelle den Befehl der dafür nötig ist um Ihr Programm zu kompilieren.
# Beachten Sie dabei, dass der Name Ihres ausführbaren Programms "is_odd" sein sollte.
# z.B. gcc -Wall -Werror -o is_odd mein_quellcode.c
​
# DEINE ANTWORT HIER
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }
    int number = atoi(argv[1]);
    if (number % 2 != 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}