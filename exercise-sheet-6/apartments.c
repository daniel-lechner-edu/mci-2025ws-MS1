/**
6.2 Klausur vom letzten Jahr: Apartmentsuche in Städten (33%)
Allgemeine Hinweise
Es sind alle Unterlagen (Foliensätze, Skripten) erlaubt, Sie dürfen auch Teile Ihrer eigenen Lösungen der Übungsblätter wiederverwenden.
Kommunikation mit anderen Studenten und/oder KIs (ChatGPT & Co.) ist in jeglicher Form verboten und führt zu einer negativen Beurteilung.
Lesen Sie die Aufgabe genau und vollständig durch, bevor Sie mit der Bearbeitung beginnen.
Zur Benotung wird die Funktionalität ihrer Lösung auf JupyterHub herangezogen.
Kommentieren Sie Ihren Code ausführlich (jede Funktion und auch jeden wichtigen Codeteil)
Kommentieren Sie am Anfang Ihrer Quelldatei, was an Ihrem abgegebenen Programm einwandfrei funktioniert, und was nicht funktioniert (und warum).
Wann immer von „zufälligen“ Werten gesprochen wird, grenzen Sie den möglichen Wertebereich sinnvoll ein.
Wenn keine konkreten Werte angegeben werden, dann wählen Sie selber einen sinnvollen Wert aus.
Aufgabe
Implementieren Sie ein Programm, welches für eine Liste von Wohnungen ausgibt, welche Wohnungen eine gegebene Mindestfläche und Mindestanzahl an Zimmer haben und in einer gegebenen Stadt verfügbar sind. Die Liste der Wohnungen finden Sie in der Datei apartments.csv im Ordner dieser Klausur. Darin enthalten ist eine Liste von 51 Wohnungen inklusive deren Stadt, der Adresse, der Fläche in Quadratmetern, der Anzahl der Zimmer und einer Liste von verfügbaren Extras. So gibt zum Beispiel der Datensatz Innsbruck;Pradl 5;88.5;3;Balkon:Garage die Stadt (Innsbruck), die Adresse (Pradl 5), die Fläche (88.5 Quadratmeter), die Anzahl der Zimmer (3) und die verfügbaren Extras (Balkon und Garage) an.

Benutzer:innen sollen als Kommandozeilenparameter die gewünschte Stadt, die gewünschte Mindestfläche, die gewünschte Mindestanzahl an Zimmern und eine optionale Liste von gewünschten Extras angeben können. Es soll dann eine Liste von Wohnungen ausgegeben werden, die in der angegebenen Stadt verfügbar sind, die gewünschte Mindestgröße und Mindestanzahl an Zimmern erfüllen und alle angebenen Extras haben. Diese Liste soll neben der Adresse auch die genaue Fläche der Wohnung (mit genau 1 Nachkommastelle!), Anzahl an Zimmern und die Extras enthalten.

Hier ein beispielhafter Programmaufruf inklusive Ausgabe:

Aufruf:
./apartments Innsbruck 85 3 Garage Balkon.
Ausgabe:
Pradl 5: 88.5 m2, 3 Zimmer, Balkon, Garage
Sillgasse 4: 95.0 m2, 3 Zimmer, Balkon, Garage
Innrain 15: 90.0 m2, 3 Zimmer, Balkon, Keller, Garage

Es gilt zu beachten:
Die Liste der Apartments in der Datei apartments.csv wurde von ChatGPT erstellt, daher können dort aufgeführte Daten von der Realität abweichen.
Die Reihenfolge der Ausgabe soll der umgekehrten Reihenfolge der Liste in der Datei apartments.csv entsprechen.
Sollte die Datei apartments.csv plötzlich mehr oder weniger als 51 Datensätze beinhalten, dann darf Ihr Programm nicht abstürzen. Überzählige Zeilen können aber ignoriert werden.
Ihr Programm sollte auch bei ungültigen Zeilen (z.B. bei fehlenden Daten) nicht abstürzen. Ungültige Zeilen können auch ignoriert werden.
Wenn die Datei apartments.csv nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Lesefehler" enthalten.
Werden keine oder zuwenig Kommandozeilenparameter angegeben, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
Wird eine nicht existierende Stadt angegeben, oder es konnten keine passenden Apartments gefunden werden, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Parameterfehler" enthalten.
Hilfestellung für eine mögliche Herangehensweise:
Hinweis: Sie müssen sich NICHT an diesen Ablauf halten - wichtig ist nur, dass Ihr Programm den oberhalb präsentierten Angaben gerecht wird. Sehen Sie den folgenden Abschnitt lediglich als Hilfestellung an, um die Aufgabe in kleinere Einheiten zerlegen zu können.
(1) Erstellen Sie zunächst die main()-Funktion, lesen sie die Kommandozeilenparameter ein und überprüfen Sie diese auf ihre Richtigkeit.

(2) Erstellen Sie eine Struktur mit passenden Feldern, um die Daten der Apartments speichern zu können.
(3) Implementieren Sie eine Funktion, welche die Daten der Apartments aus der Datei liest und in der zuvor erstellten Struktur speichert. Erzeugen Sie hierfür ein Array ausreichender Größe für 51 Datensätzen. Sie müssen die Array-Größe nicht dynamisch anpassen.
(4) Implementieren Sie eine Funktion, welche für die angegebenen Parameter die dazu passenden Apartments ausgibt.
(5) Führen Sie die in den Schritten 1-4 erstellten Bestandteile zu einem funktionsfähigen Programm zusammen.
Hinweis:
Die Datensätze wurden zufällig erstellt. Daher stimmen die Daten nicht mit den Daten von den realen Städten überein.
 */