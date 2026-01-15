/**
4.2 Strukturen (25%)
Im Ordner dieses Übungsblattes finden die die Datei "persons_input.txt". In dieser Datei finden sich Datensätze für Personen in folgender Form: Vorname;Nachname;Alter;Hobbies. Dabei kann eine Person bis zu 5 Hobbies haben, die durch , getrennt sind. Hier ein beispielhafter Datensatz: Max;Mustermann;21;Rodeln,Musik,Kochen. Die einzelnen Datensätze sind durch Zeilenumbrüche voneinander getrennt.

Ihre Aufgabe ist es, alle Datensätze aus der Datei einzulesen und in eine dafür geeignete Struktur zu speichern. Anschließend geben Sie bitte die Nachnamen aller Personen aus, die zwischen 20 und (inklusive) 30 Jahre alt sind und die Tanzen zu ihren Hobbies zählen.

Sie können davon ausgehen, dass die einzulesende Datei nicht mehr als 20 Zeilen mit Daten beinhaltet. Sie sollten allerdings nie blind davon ausgehen, sondern auch entsprechende Schutzmechanismen integrieren, falls die Datei doch mehr Zeilen enthaltet. In diesem Fall sollte Ihr Programm nicht abstürzen oder sonstiges undefiniertes Verhalten zeigen, sie können aber die zusätzlichen Zeilen ignorieren.

Desweiteren sollten Sie auch nie darauf vertrauen, dass die Struktur der Daten immer korrekt ist, sondern Schutzmaßnahmen implementieren, die dafür sorgen, dass Ihr Programm nicht abstürzen oder sonstiges undefiniertes Verhalten zeigen, wenn die Struktur der Daten nicht korrekt ist.

Implementieren Sie Ihr Programm in der Datei persons.c.
 */