/**
3.1 Großbuchstaben (21%)
Implementieren Sie ein Programm, dass mittels scanf eine Zeichenfolge einliest, jeden Kleinbuchstaben darin durch den entsprechenden Großbuchstaben ersetzt und die veränderte Zeichenfolge ausgibt. Nur Kleinbuchstaben sollen verändert werden, andere Zeichen sollen beibehalten werden. Ihre Implementierung soll für alle Zeichenfolgen mit Länge kleiner als 50 funktionieren. Achten Sie in Ihrer Implementierung darauf, dass es auch bei längeren Zeichenfolgen zu keinem Buffer-Overflow kommt.

Achtung: Die Benutzung von Bibliotheksfunktionen zur Umwandlung Ihrer Zeichenkette ist nicht erlaubt. Außerdem ist die Eingabe von Daten via scanf in Jupyter-Notebook nicht möglich. Testen Sie Ihre Implementierung daher direkt in der Kommandozeile.
 */

#include <stdio.h>
#define MAX_LENGTH 50
int main() {
    char str[MAX_LENGTH + 1];
    printf("Geben Sie eine Zeichenfolge ein (maximal %d Zeichen): ", MAX_LENGTH);
    if (scanf("%50s", str) == 1) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - ('a' - 'A');
            }
        }
        printf("Veränderte Zeichenfolge: %s\n", str);
    } else {
        printf("Fehler beim Einlesen der Zeichenfolge.\n");
    }
    return 0;
}