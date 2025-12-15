/** 3.3 String-Funktionen (37%)
Im Ordner dieses Übungsblattes finden Sie die Datei my_string.h welche einige Funktionsdeklarationen enthält. Ihre Aufgabe ist es nun diese Funktionen anhand der folgenden Beschreibungen zu implementieren. Diese Implementierung soll in der Datei my_string.c erfolgen. Die Funktionen sollen anschließend durch Einbindung der Header-Datei my_string.h in jedem beliebigen C-Programm verwendbar sein (selbe Vorgehensweise wie bei Übungsaufgabe 2.2). Sie können (und sollten) dies selbstverständlich testen, für die Abgabe ist jedoch nur die Datei my_string.c relevant. Damit Sie den Code von my_string.c in einem anderen Programm einbinden können, darf darin keine main()-Funktion enthalten sein. Achten Sie darauf, dass Ihre Abgabe kompilierbar und ausführbar ist, nur so können dafür Punkte vergeben werden. Änderungen an der Datei my_string.h sind nicht gestattet. Die Datei string_test.c, die Sie auch im Ordner des Übungszettel finden, wird von den Validier-Funktion benötigt, um Ihre Abgabe zu testen.

Folgende Funktionen sollen implementiert werden:

int string_cmp(const char* str1, const char* str2)
Diese Funktion soll die Zeichenketten str1 und str2 vergleichen. Sind die beiden Zeichenketten gleich, dann soll 1 zurückgegeben werden, ansonsten 0.


unsigned int string_len(const char* str)
Diese Funktion soll die Länge (=Anzahl von Zeichen) einer Zeichenkette str als Integer zurückgeben. Das Nullterminierungszeichen soll dabei nicht mitgezählt werden.


void string_rev(char* str)
Diese Funktion soll eine Zeichenkette str umkehren. Beachten Sie, dass hier Call-by-Reference verwendet wird und der umgedrehte String über das Funktionsargument str zurück gegeben werden soll (in so einem Fall redet man auch von einem, In-Out Argument).


const char *string_chr(const char* str, const char c)
Diese Funktion soll eine Zeichenkette str nach einem Zeichen c durchsuchen. Wird das gesuchte Zeichen gefunden, so soll ein Pointer darauf zurückgegeben werden. Nur das erste Auftreten von c in str soll dabei beachtet werden. Enthält str das Zeichen c nicht, dann soll NULL zurückgegeben werden.

*/