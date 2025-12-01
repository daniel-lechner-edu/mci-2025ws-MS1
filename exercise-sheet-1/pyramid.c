/*1.3 Pyramide (25%)
Implementieren Sie ein Programm, welches exakt folgende Ausgabe erzeugt:

  *  
 ***
*****
Dabei soll mindestens eine for-Schleife für die Ausgabe verwendet werden.

Speichern Sie Ihre Lösung in der Datei pyramid.c ab und laden Sie diese auf JupyterHub in denselben Ordner wie den Übungszettel hoch.

%%bash
​
# Schreiben Sie in diese Zelle den Befehl der dafür nötig ist um Ihr Programm zu kompilieren.
# Beachten Sie dabei, dass der Name ihrer Quellcode-Datei "pyramid.c" sein sollte.
# Beachten Sie dabei, dass der Name Ihres ausführbaren Programms "pyramid" sein sollte.
# z.B. gcc -Wall -Werror -o pyramid pyramid.c
​
# DEINE ANTWORT HIER
# Weisen Sie der untenstehenden Variable den Wert True zu, sobald Sie die Aufgabe erfolgreich erledigt haben!
​
# Datentyp: bool
exercise_1_3_solved = False
%%bash
​
# Benutzen Sie diese Zelle um Ihr Ergebnis zu testen.
# Damit diese Zelle ausgeführt werden kann, müssen Sie zuerst Ihr Programm erfolgreich kompilieren.
​
./pyramid
*/

#include <stdio.h>
int main() {
    int height = 3; // Höhe der Pyramide
    for (int i = 0; i < height; i++) {
        // Leerzeichen vor den Sternen
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        // Sterne
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        // Neue Zeile nach jeder Reihe
        printf("\n");
    }
    return 0;
}