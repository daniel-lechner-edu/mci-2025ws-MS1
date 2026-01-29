/**
6.4 Klausur aus den Vorjahren: Länder, Städte und Bevölkerungsdichte
Implementieren Sie ein Programm, welches für eine Liste von Ländern jeweils die Stadt mit der größten Bevölkerungsdiche ausgibt. Verwenden Sie dazu die Datei cities.csv, die Sie im Ordner dieser Klausur finden. Diese enthält 40 Datensätze von Städten, in was für einem Land diese Städte liegen, die Anzahl der Bewohner und die Größe der Fläche, die die Städte einnehmen. So gibt zum Beispiel der Datensatz Vienna;Austria;2400000;613.5 neben der Stadt ("Vienna") und dem Land ("Austria") auch die Bevölkerungsgröße (2400000 Bewohner) und die Größe der Fläche der Stadt (613.5  𝑘𝑚2
 ) an.

Der Benutzer soll als Kommandozeilenparameter eine beliebig lange Liste von Ländern angeben können. Es soll dann für jedes angegebene Land die Stadt mit der größten Bevölkerungsdichte (Bewohner pro  𝑘𝑚2
 ) (mit genau 2 Nachkommastellen!) ausgegeben werden. Hier ein beispielhafter Programmaufruf inklusive Ausgabe:

Aufruf:
./cities Australia Italy.
Ausgabe:
Italy: Asti with 3400.57 people per km2
Australia: Richmond with 2528.23 people per km2

Es gilt zu beachten:
Die Reihenfolge der Ausgabe soll der umgekehrten Reihenfolge der Eingabeparameter entsprechen. Wird also Australia zuerst eingegeben, soll auch dessen Ausgabe als letztes erscheinen (siehe Ausgabe oben).
Sollte die Datei cities.csv plötzlich mehr oder weniger als 40 Datensätze beinhalten, dann darf Ihr Programm nicht abstürzen. Überzählige Zeilen können aber ignoriert werden.
Ihr Programm sollte auch bei ungültigen Zeilen (z.B. bei fehlenden Daten) nicht abstürzen. Ungültige Zeilen können auch ignoriert werden.
Wenn die Datei cities.csv nicht zum Lesen geöffnet werden kann, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Lesefehler" enthalten.
Wird kein Kommandozeilenparameter angegeben, dann soll eine Fehlermeldung auf stderr ausgegeben, und das Programm mit einem Exit-Code ungleich 0 beendet werden. Wichtig: Die Fehlermeldung muss das Wort "Eingabefehler" enthalten.
Wird ein Land, welches im Datensatz nicht existiert, als Kommandozeilenparameter angegeben, soll dies dem Nutzer durch die Nachricht Country '<Eingabe aus Eingabeparameter>' not found mitgeteilt werden (wie im folgenden Beispiel):

Aufruf:
./cities Australia China Italy.
Ausgabe:
Italy: Asti with 3400.57 people per km2
Country 'China' not found
Australia: Richmond with 2528.23 people per km2

Sorgen Sie dafür, dass bei Beendigung des Programms alle benötigten Ressourcen explizit wieder freigegeben werden.

Vermeiden Sie Umlaute, Sonderzeichen o.ä. so weit wie möglich, um Kompatibilitätsproblemen zwischen Windows und Linux vorzubeugen.
Hilfestellung für eine mögliche Herangehensweise:
Hinweis: Sie müssen sich NICHT an diesen Ablauf halten - wichtig ist nur, dass Ihr Programm den oberhalb präsentierten Angaben gerecht wird. Sehen Sie den folgenden Abschnitt lediglich als Hilfestellung an, um die Aufgabe in kleinere Einheiten zerlegen zu können.
(1) Erstellen Sie zunächst die main()-Funktion, lesen sie die Kommandozeilenparameter ein und überprüfen Sie diese auf ihre Richtigkeit.

(2) Erstellen Sie eine Struktur mit passenden Feldern, um die Daten der Städte speichern zu können.
(3) Implementieren Sie eine Funktion, welche die Daten der Städte aus der Datei liest und in der zuvor erstellten Struktur speichert. Erzeugen Sie hierfür ein Array ausreichender Größe für 40 Datensätzen. Sie müssen die Array-Größe nicht dynamisch anpassen.
(4) Implementieren Sie eine Funktion, welche für ein gegebenes Land die Stadt mit der größten Bevölkerungsdichte und die Bevölkerungsdichte selber zurückgibt.
(5) Führen Sie die in den Schritten 1-4 erstellten Bestandteile zu einem funktionsfähigen Programm zusammen.
Hinweis:
Die Datensätze wurden zufällig erstellt. Daher stimmen die Daten nicht mit den Daten von den realen Städten überein.
 */