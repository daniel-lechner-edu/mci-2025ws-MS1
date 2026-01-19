/**
4.2 Strukturen (25%)
Im Ordner dieses Übungsblattes finden die die Datei "persons_input.txt". In dieser Datei finden sich Datensätze für Personen in folgender Form: Vorname;Nachname;Alter;Hobbies. Dabei kann eine Person bis zu 5 Hobbies haben, die durch , getrennt sind. Hier ein beispielhafter Datensatz: Max;Mustermann;21;Rodeln,Musik,Kochen. Die einzelnen Datensätze sind durch Zeilenumbrüche voneinander getrennt.

Ihre Aufgabe ist es, alle Datensätze aus der Datei einzulesen und in eine dafür geeignete Struktur zu speichern. Anschließend geben Sie bitte die Nachnamen aller Personen aus, die zwischen 20 und (inklusive) 30 Jahre alt sind und die Tanzen zu ihren Hobbies zählen.

Sie können davon ausgehen, dass die einzulesende Datei nicht mehr als 20 Zeilen mit Daten beinhaltet. Sie sollten allerdings nie blind davon ausgehen, sondern auch entsprechende Schutzmechanismen integrieren, falls die Datei doch mehr Zeilen enthaltet. In diesem Fall sollte Ihr Programm nicht abstürzen oder sonstiges undefiniertes Verhalten zeigen, sie können aber die zusätzlichen Zeilen ignorieren.

Desweiteren sollten Sie auch nie darauf vertrauen, dass die Struktur der Daten immer korrekt ist, sondern Schutzmaßnahmen implementieren, die dafür sorgen, dass Ihr Programm nicht abstürzen oder sonstiges undefiniertes Verhalten zeigen, wenn die Struktur der Daten nicht korrekt ist.

Implementieren Sie Ihr Programm in der Datei persons.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 20
#define MAX_HOBBIES 5
#define MAX_NAME_LEN 100
#define MAX_HOBBY_LEN 50
#define MAX_LINE_LEN 512

typedef struct {
    char firstname[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
    int age;
    char hobbies[MAX_HOBBIES][MAX_HOBBY_LEN];
    int hobby_count;
} Person;

int parse_person(char *line, Person *person) {
    char *token;
    char *rest = line;
    int field = 0;

    person->hobby_count = 0;

    while ((token = strtok_r(rest, ";", &rest)) != NULL) {
        if (field == 0) {
            strncpy(person->firstname, token, MAX_NAME_LEN - 1);
            person->firstname[MAX_NAME_LEN - 1] = '\0';
        } else if (field == 1) {
            strncpy(person->lastname, token, MAX_NAME_LEN - 1);
            person->lastname[MAX_NAME_LEN - 1] = '\0';
        } else if (field == 2) {
            person->age = atoi(token);
        } else if (field == 3) {
            char *hobby_rest = token;
            char *hobby;
            while ((hobby = strtok_r(hobby_rest, ",", &hobby_rest)) != NULL) {
                if (person->hobby_count < MAX_HOBBIES) {
                    strncpy(person->hobbies[person->hobby_count], hobby, MAX_HOBBY_LEN - 1);
                    person->hobbies[person->hobby_count][MAX_HOBBY_LEN - 1] = '\0';
                    person->hobby_count++;
                }
            }
        }
        field++;
    }

    return field >= 3;
}

int has_hobby(Person *person, const char *hobby) {
    for (int i = 0; i < person->hobby_count; i++) {
        if (strcmp(person->hobbies[i], hobby) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file = fopen("persons_input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Person persons[MAX_PERSONS];
    int person_count = 0;
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, file) && person_count < MAX_PERSONS) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (parse_person(line, &persons[person_count])) {
            person_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < person_count; i++) {
        if (persons[i].age >= 20 && persons[i].age <= 30 && has_hobby(&persons[i], "Tanzen")) {
            printf("%s\n", persons[i].lastname);
        }
    }

    return 0;
}