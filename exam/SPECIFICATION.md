# Suche von Serien

## Allgemeine Hinweise

- Es sind alle Unterlagen (Foliensätze, Skripten) erlaubt, Sie dürfen auch Teile Ihrer eigenen Lösungen der Übungsblätter wiederverwenden.
- Kommunikation mit anderen Studenten und/oder KIs (ChatGPT & Co.) ist in jeglicher Form verboten und führt zu einer negativen Beurteilung.
- Lesen Sie die Aufgabe genau und vollständig durch, bevor Sie mit der Bearbeitung beginnen.
- Zur Benotung wird die Funktionalität ihrer Lösung auf JupyterHub herangezogen.
- Kommentieren Sie Ihren Code ausführlich (jede Funktion und auch jeden wichtigen Codeteil)
- Kommentieren Sie am Anfang Ihrer Quelldatei, was an Ihrem abgegebenen Programm einwandfrei funktioniert, und was nicht funktioniert (und warum).
- Wann immer von „zufälligen" Werten gesprochen wird, grenzen Sie den möglichen Wertebereich sinnvoll ein.
- Wenn keine konkreten Werte angegeben werden, dann wählen Sie selber einen sinnvollen Wert aus.

## Aufgabe

Implementieren Sie ein Programm, welches Serien auswertet, die auf einer Streaming-Plattform verfügbar sind.

Eine Liste mit den Daten aller auf der Streaming-Platform verfügbaren Serien finden Sie in der Datei `series.csv` im Ordner dieser Klausur. Darin enthalten ist eine Liste von 55 Serien, inklusive der zugeordneten Genres, der Anzahl der Staffeln, die Gesamtanzahl aller Episoden, die durchschnittliche Dauer einer Episode und die Bewertung der Serie laut Internet Movie Database (IMDb). So handelt zum Beispiel der Datensatz `Breaking Bad;Drama,Crime,Thriller;5;62;47.0;9.5` über die Serie "Breaking Bad", die den Genres "Drama", "Crime" und "Thriller" zugeordnet ist, 5 Staffeln hat mit insgesamt 62 Episoden, die durchschnittliche Länge einer Episode ist 47.0 Minuten und laut IMDb wird die Serie mit 9.5 Sternen bewertet.

Jede Serie muss mindestens einem Genre und kann bis zu 5 Genres zugeordnet sein.

Benutzer:innen geben als Kommandozeilenparameter ein Genre und die gewünschte minimale bzw. maximale Gesamtlänge (Anzahl Episoden x durchschnittlicher Episodenlänge) in Stunden und die Mindestbewertung laut IMDb an. Es soll dann eine Liste von Serien ausgegeben werden, die dem angebenen Genre zugeordnet sind, die gewünschte Gesamtlänge erfüllen und deren IMDb-Bewertung mindestens der angegebenen entspricht. Diese Liste soll neben dem Namen der Serie auch die Anzahl der Staffeln, die Gesamtlänge in Stunden (mit genau 2 Nachkommastellen!) und die IMDb-Bewertungen enthalten.

Die Angabe der Gesamtlänge funktioniert so: Wird eine negative Zahl angegeben, so wird der Betrag dieser Zahl als untere Grenze der Gesamtlänge interpretiert. Wird hingegen eine positive Zahl angegeben, dann wird die Zahl als obere Grenze der Gesamtlänge interpretiert.

Hier ein beispielhafter Programmaufruf inklusive Ausgabe:

Aufruf:

```txt
./series Crime -45 8.9
```

Ausgabe:

```txt
Fargo: 5 Staffeln, 45.73 Stunden, 8.9 Sterne
Better Call Saul: 6 Staffeln, 48.51 Stunden, 9 Sterne
Breaking Bad: 5 Staffeln, 48.56 Stunden, 9.5 Sterne
```

## Es gilt zu beachten

- Die Liste der Serien in der Datei `series.csv` wurde von ChatGPT erstellt, daher können dort aufgeführte Daten von der Realität abweichen.
- Die Reihenfolge der Ausgabe soll der umgekehrten Reihenfolge der Liste in der Datei `series.csv` entsprechen.
- Sollte die Datei `series.csv` plötzlich mehr oder weniger als 55 Datensätze beinhalten, dann darf Ihr Programm nicht abstürzen. Überzählige Zeilen können aber ignoriert werden.
- Ihr Programm sollte auch bei ungültigen Zeilen (z.B. bei fehlenden Daten) nicht abstürzen. Ungültige Zeilen sollen ignoriert werden und Ihr Programm mit den restlichen Daten ganz normal weiterarbeiten. Für jede ungültige Zeile soll eine Fehlermeldung auf `stderr` ausgegeben werden, die das Wort `"Zeilenfehler"` enthält.
- Wenn die Datei `series.csv` nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf `stderr` ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort `"Lesefehler"` enthalten.
- Werden keine oder zuwenig Kommandozeilenparameter angegeben, dann soll eine Fehlermeldung auf `stderr` ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort `"Eingabefehler"` enthalten.
- Wird ein nicht existierendes Genre angegeben, oder es konnten keine passenden Serien gefunden werden, dann soll eine Fehlermeldung auf `stderr` ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort `"Parameterfehler"` enthalten.

## Hilfestellung für eine mögliche Herangehensweise

Hinweis: Sie müssen sich NICHT an diesen Ablauf halten - wichtig ist nur, dass Ihr Programm den oberhalb präsentierten Angaben gerecht wird. Sehen Sie den folgenden Abschnitt lediglich als Hilfestellung an, um die Aufgabe in kleinere Einheiten zerlegen zu können.

1. Erstellen Sie zunächst die main()-Funktion, lesen sie die Kommandozeilenparameter ein und überprüfen Sie diese auf ihre Richtigkeit.

2. Erstellen Sie eine Struktur mit passenden Feldern, um die Daten der Serien speichern zu können.

3. Implementieren Sie eine Funktion, welche die Daten der Serien aus der Datei liest und in der zuvor erstellten Struktur speichert. Den für das Speichern der Daten notwendigen Speicherplatz können Sie für die 55 Datensätze statisch allokieren. Die Verwendung von dynamischer Speicherverwaltung ist dafür nicht zwingend vorgesehen (aber auch nicht verboten ;))

4. Implementieren Sie eine Funktion, welche für die angegebenen Parameter die dazu passenden Serien ausgibt.

5. Führen Sie die in den Schritten 1-4 erstellten Bestandteile zu einem funktionsfähigen Programm zusammen.

```%%bash

# Schreiben Sie in diese Zelle den Befehl der dafür nötig ist um Ihr Programm zu kompilieren.
# Beachten Sie dabei, dass der Name Ihrer Quellcode-Datei "series.c" sein sollte.
# Beachten Sie dabei, dass der Name Ihres ausführbaren Programms "series" sein sollte.

# DEINE ANTWORT HIER

cc ./series.c ./series_io.c ./series_filter.c -Wall -Werror -o series && ./series Crime -45 8.9
```
