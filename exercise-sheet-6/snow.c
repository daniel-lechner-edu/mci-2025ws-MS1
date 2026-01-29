/**
6.3 Schneefall (34%)
Implementieren Sie ein Programm, welches Schneefall-Daten für verschiedene Tiroler Ortschaften aus Dateien einliest, verarbeitet und in bestimmter Form wieder in eine Datei ausgibt. Sie finden im Ordner dieses Übungsblattes den Unterordner snow_data. In diesem Ordner gibt es genau 8 Textdokumente, wobei jedes dieser Dokumente Schneefall-Daten für 8 verschiedene Tiroler Ortschaften im Format Ortsname;Schneefall-Menge (in cm) enthält. In Datei 1.txt befinden sich die Datensätze für Tag 1, in Datei 2.txt jene von Tag 2, und so weiter. Der Benutzer soll einen bestimmten Ort und einen bestimmten Tag angeben können. Als Ausgabe sollen dann die jeweiligen Schneefall-Mengen von diesem Ort an allen vorherigen Tagen (inklusive des angegebenen Tages), sowie die Summe dieser Schneefall-Mengen, in ein Textdokument geschrieben werden. Hier ein beispielhafter Programmablauf:

> Geben Sie einen Ort an:
Ischgl
> Geben Sie einen Tag an:
3
> Die Ergebnisse Ihrer Anfrage wurden erfolgreich in eine Datei geschrieben.

So sollte der Inhalt der Ausgabedatei für obige Eingaben aussehen:
Tag 1: 5
Tag 2: 23
Tag 3: 3
Summe: 31

Es gilt zu beachten:

Wird eine Ortschaft angegeben zu welcher keine Datensätze existieren, dann soll keine Ausgabedatei erzeugt werden. Zudem soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet, werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
Als korrekte Eingabe für den Tag sollen nur Integer-Werte zwischen 1 und 8 akzepiert werden (Eingaben wie 3xyz oder 4.0 werden nicht akzeptiert). Bei jeglichen anderen Eingaben soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet, werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
Die Ausgabedatei soll ebenfalls im Ordner snow_data angelegt werden. Sie soll im Format Ortsname_Tag.txt benannt werden. Für obiges Beispiel wäre dies Ischgl_3.txt.
Wenn eine Eingabedatei nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet, werden. Wichtig: Die Fehlermeldung muss das Wort "Lesefehler" enthalten.
Wenn die Ausgabedatei nicht zum Schreiben geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet, werden. Wichtig: Die Fehlermeldung muss das Wort "Schreibfehler" enthalten.
Der Inhalt der Ausgabedatei soll wie im obigen Beispiel formatiert werden. Wichtig dabei ist, dass jeder Eintrag in eine neue Zeile geschrieben wird und jede Zeile (außer jener mit der Summe) sowohl die Nummer des Tages als auch die entsprechende Schneefall-Menge enthält.
Falls Sie während Ihrer Implementierung eine Zeichenkette mit einem Integer konkatenieren möchten, dann können Sie dazu beispielsweise die Funktion sprintf aus der Header-Datei stdio.h verwenden.
Sobald das Lesen von bzw. das Schreiben in eine Datei abgeschlossen ist, muss diese durch den entsprechenden Befehl wieder geschlossen werden.
 */