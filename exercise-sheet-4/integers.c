/**
4.1 Ausgabe in Datei (33%)
Implementieren Sie ein Programm welches zeilenweise von der Kommandozeile einliest, dabei alle Zahlen aus der Eingabe filtert und diese dann in eine Datei "integers_output.txt" schreibt (führende Nullen dürfen nicht gelöscht werden). Als Zahlen werden hierbei alle Ziffernfolgen angesehen (d.h. Die Eingabe 4,5 würde in die Zahlen 4 und 5 aufgeteilt werden). Es sollen solange Zeilen eingelesen werden, bis eine leere Zeile eingegeben wird. Hier ein Beispiel für einen möglichen Programmablauf:

> Geben Sie Ihren Text ein:
    Im Jahr 2019 haben bereits 50 Studenten mehr als 2h gelernt.
    23 davon sogar länger als 4,5h.
    Viele lernten erst eine Stunde lang.
    Niemand lernte mehr als 10h.
    ``
> Ende der Eingabe erreicht.

Die Ausgabedatei sollte für obige Eingabe exakt so aussehen:
2019 50 2
23 4 5
``
10

Die gefundenen Zahlen aus jeder Eingabezeile sollen also durch ein Leerzeichen getrennt in die entsprechende Zeile der Ausgabedatei geschrieben werden. Wird in einer Eingabezeile keine Zahl gefunden, so soll in der Ausgabedatei stattdessen eine leere Zeile eingefügt werden.

Implementieren Sie Ihr Programm in der Datei integers.c.
 */

 