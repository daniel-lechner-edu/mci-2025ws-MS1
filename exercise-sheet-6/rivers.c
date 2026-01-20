/**
6.5 Klausur aus den Vorjahren: Berggipfel und Höhen
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
Implementieren Sie ein Programm, welches für eine Liste von Kontinenten angibt, welcher Berggipfel die größte Höhe auf einem gegebenen Kontinent hat. Zusätzlich soll auch die Differenz zum kleinsten Gipfel auf denselben Kontinent ausgegeben werden. Verwenden Sie dazu die Datei peaks.csv, die Sie im Ordner dieser Klausur finden. Darin enthalten ist eine Liste von 55 Berggipfeln inklusive deren Höhe in Metern, das Land, in dem sich der Gipfel befindet, und der Kontinent, auf dem sich das Land befindet. So gibt zum Beispiel der Datensatz Mount Everest:8848:Nepal:Asia den Namen des Gipfels (Mount Everest), die Höhe (8848 Meter), das Land (Nepal) und den Kontinent (Asia) an.

Benutzer:innen sollen als Kommandozeilenparameter eine Liste von Kontinenten angeben können. Es soll dann für jeden angegebenen Kontinent der höchste Berggipfel inklusive seiner Höhe, dem Land und die Höhendifferenz zum kleinsten Gipfel auf denselben Kontinent in umgekehrter Reihenfolg ausgegeben werden.

Hier ein beispielhafter Programmaufruf inklusive Ausgabe:

Aufruf:
./peaks Asia Africa.
Ausgabe:
Africa: Kibo (Tanzania) with 5895 m, Difference: 1345 m
Asia: Mount Everest (Nepal) with 8848 m, Difference: 3711 m

Es gilt zu beachten:
Die Liste der Berggipfel in der Datei peaks.csv wurde von ChatGPT erstellt, daher alle Angaben ohne Gewähr.
Sollte die Datei peaks.csv plötzlich mehr oder weniger als 55 Datensätze beinhalten, dann darf Ihr Programm nicht abstürzen. Überzählige Zeilen können aber ignoriert werden.
Ihr Programm sollte auch bei ungültigen Zeilen (z.B. bei fehlenden Daten) nicht abstürzen. Ungültige Zeilen können auch ignoriert werden.
Wenn die Datei peaks.csv nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Lesefehler" enthalten.
Wird kein Kommandozeilenparameter angegeben, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
Wird ein Kontinent, welches im Datensatz nicht existiert, als Kommandozeilenparameter angegeben, soll dies dem Nutzer durch die Nachricht Continent '<Eingabe aus Eingabeparameter>' not found mitgeteilt werden (wie im folgenden Beispiel):
Aufruf:
./rivers Asia Arctica Africa.
Ausgabe:
Africa: Kibo (Tanzania) with 5895 m, Difference: 1345 m
Continent Arctica not found
Asia: Mount Everest (Nepal) with 8848 m, Difference: 3711 m

Wenn ein Kommandozeilenargument ein Leerzeichen enthält, dann müssen Sie dieses Argument in der Konsole mit " umgeben (z.B. "South America"). Ansonsten wird es als mehrere Argumente gewertet.
Hilfestellung für eine mögliche Herangehensweise:
Hinweis: Sie müssen sich NICHT an diesen Ablauf halten - wichtig ist nur, dass Ihr Programm den oberhalb präsentierten Angaben gerecht wird. Sehen Sie den folgenden Abschnitt lediglich als Hilfestellung an, um die Aufgabe in kleinere Einheiten zerlegen zu können.
(1) Erstellen Sie zunächst die main()-Funktion, lesen sie die Kommandozeilenparameter ein und überprüfen Sie diese auf ihre Richtigkeit.

(2) Erstellen Sie eine Struktur mit passenden Feldern, um die Daten der Berggipfel speichern zu können.
(3) Implementieren Sie eine Funktion, welche die Daten der Berggipfel aus der Datei liest und in der zuvor erstellten Struktur speichert. Erzeugen Sie hierfür ein Array ausreichender Größe für 55 Datensätzen. Sie müssen die Array-Größe nicht dynamisch anpassen.
(4) Implementieren Sie eine Funktion, welche für einen gegebenen Kontinent den höchsten und den niedrigsten Berggipfel zurückgibt.
(5) Führen Sie die in den Schritten 1-4 erstellten Bestandteile zu einem funktionsfähigen Programm zusammen.
 */