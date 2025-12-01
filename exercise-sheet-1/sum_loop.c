/* 1.1 Summenberechnung (25%)
Implementieren Sie eine Funktion, welche bei der Zahl 2 startet und jede achte Zahl, die noch kleiner als 1000 ist, zu der bisherigen Summe (d.h. 2 + 10 + 18 + 26 + ...) hinzuaddiert. Am Ende soll ihr Programm die Summe dieser Berechnung ausgeben.

Speichern Sie Ihre Lösung in der Datei sum_loop.c ab und laden Sie diese auf JupyterHub in denselben Ordner wie den Übungszettel hoch.

%%bash
​
# Schreiben Sie in diese Zelle den Befehl der dafür nötig ist um Ihr Programm zu kompilieren.
# Beachten Sie dabei, dass der Name Ihres ausführbaren Programms "sum_loop" sein sollte.
# z.B. gcc -Wall -Werror -o sum_loop mein_quellcode.c
​
# DEINE ANTWORT HIER
# Weisen Sie der untenstehenden Variable den Wert True zu, sobald Sie die Aufgabe erfolgreich erledigt haben!
​
# Datentyp: bool
exercise_1_1_solved = True
%%bash
​
# Benutzen Sie diese Zelle um Ihr Ergebnis zu testen.
# Damit diese Zelle ausgeführt werden kann, müssen Sie zuerst Ihr Programm erfolgreich kompilieren.
​
./sum_loop
*/

#include <stdio.h>
int main() {
    int sum = 0;
    for (int i = 2; i < 1000; i += 8) {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}