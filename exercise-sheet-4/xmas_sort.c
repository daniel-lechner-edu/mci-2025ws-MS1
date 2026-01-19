/**
4.4 Sortieren von Geschenken (25%)
Man stelle sich einen Weihnachtswichtel vor, welcher vor n Geschenken steht, die unterschiedliche Größen haben dürfen. Die Geschenke sind in einer von links nach rechts verlaufenden Reihe aufgestellt. Ganz links steht der Weihnachtswichtel und möchte die Geschenke von links nach rechts der Größe nach aufsteigend sortieren. Dazu vergleicht er die beiden Geschenke, vor denen er gerade steht. Stellt er fest, dass sie in der richtigen Reihenfolge sind, so macht er einen Schritt nach rechts. Stellt er hingegen fest, dass die Reihenfolge nicht stimmt, so vertauscht er die beiden Geschenke und macht einen Schritt nach links. Falls er nicht weiter nach links gehen kann (wenn beispielsweise der erste Vergleich zum Ergebnis führte, dass sich das erste und zweite Geschenk in der falschen Reihenfolge befanden), macht er einen Schritt nach rechts. Dies wiederholt er ständig. Fertig ist er, wenn er am ganz rechts stehenden Geschenk ankommt. Da sich rechts daneben kein weiteres Geschenk mehr befindet, kann kein Vergleich mehr stattfinden.

Implementieren Sie den Sortieralgorithmus, der hier beschrieben ist. Die n Geschenke sollen dabei n Integer sein. Im Ordner dieses Übungsblattes finden Sie die Datei xmas_sort.h, welche die Funktionsdeklaration für diesen Algorithmus enthält. Ihre Implementierung soll in der Datei xmas_sort.c erfolgen. Die Funktion sollen anschließend durch Einbindung der Header-Datei xmas_sort.h in jedem beliebigen C-Programm verwendbar sein (selbe Vorgehensweise wie bei Übungsaufgabe 3.3, auch hier sollte wieder keine main()-Funktion enthalten sein). Sie können (und sollten) dies selbstverständlich testen, für die Abgabe ist jedoch nur die Datei xmas_sort.c relevant. Achten Sie darauf, dass Ihre Abgabe kompilierbar und ausführbar ist, nur so können dafür Punkte vergeben werden. Änderungen an der Datei xmas_sort.h sind nicht gestattet. Die Datei xmas_sort_test.c, die Sie auch im Ordner des Übungszettel finden, wird von den Validier-Funktion benötigt, um Ihre Abgabe zu testen.
 */

#include "xmas_sort.h"

void xmas_sort(int* array, const int n) {
    if (n <= 1) {
        return;
    }

    int pos = 0;

    while (pos < n - 1) {
        if (array[pos] > array[pos + 1]) {
            int temp = array[pos];
            array[pos] = array[pos + 1];
            array[pos + 1] = temp;

            if (pos > 0) {
                pos--;
            } else {
                pos++;
            }
        } else {
            pos++;
        }
    }
}
