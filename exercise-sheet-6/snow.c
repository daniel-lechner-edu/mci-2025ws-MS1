#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_LOCATION_LEN 50

int is_valid_day(const char *input) {
    if (!input || strlen(input) == 0) return 0;

    for (int i = 0; input[i]; i++) {
        if (!isdigit(input[i])) return 0;
    }

    int day = atoi(input);
    return day >= 1 && day <= 8;
}

int location_exists(const char *location) {
    FILE *fp = fopen("snow_data/1.txt", "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        exit(1);
    }

    char line[MAX_LINE];
    int found = 0;

    while (fgets(line, MAX_LINE, fp)) {
        char loc[MAX_LOCATION_LEN];
        int snowfall;

        if (sscanf(line, "%[^;];%d", loc, &snowfall) == 2) {
            if (strcmp(loc, location) == 0) {
                found = 1;
                break;
            }
        }
    }

    fclose(fp);
    return found;
}

int get_snowfall(const char *location, int day) {
    char filename[50];
    sprintf(filename, "snow_data/%d.txt", day);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        exit(1);
    }

    char line[MAX_LINE];
    int snowfall = 0;
    int found = 0;

    while (fgets(line, MAX_LINE, fp)) {
        char loc[MAX_LOCATION_LEN];
        int snow;

        if (sscanf(line, "%[^;];%d", loc, &snow) == 2) {
            if (strcmp(loc, location) == 0) {
                snowfall = snow;
                found = 1;
                break;
            }
        }
    }

    fclose(fp);

    if (!found) {
        fprintf(stderr, "Eingabefehler\n");
        exit(1);
    }

    return snowfall;
}

void write_output(const char *location, int day, int snowfalls[]) {
    char filename[100];
    sprintf(filename, "snow_data/%s_%d.txt", location, day);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Schreibfehler\n");
        exit(1);
    }

    int sum = 0;
    for (int i = 1; i <= day; i++) {
        fprintf(fp, "Tag %d: %d\n", i, snowfalls[i-1]);
        sum += snowfalls[i-1];
    }
    fprintf(fp, "Summe: %d\n", sum);

    fclose(fp);
}

int main() {
    char location[MAX_LOCATION_LEN];
    char day_input[MAX_LINE];

    printf("> Geben Sie einen Ort an:\n");
    if (!fgets(location, MAX_LOCATION_LEN, stdin)) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    location[strcspn(location, "\n")] = '\0';

    if (!location_exists(location)) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    printf("> Geben Sie einen Tag an:\n");
    if (!fgets(day_input, MAX_LINE, stdin)) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    day_input[strcspn(day_input, "\n")] = '\0';

    if (!is_valid_day(day_input)) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    int day = atoi(day_input);

    int snowfalls[8];
    for (int i = 1; i <= day; i++) {
        snowfalls[i-1] = get_snowfall(location, i);
    }

    write_output(location, day, snowfalls);

    printf("> Die Ergebnisse Ihrer Anfrage wurden erfolgreich in eine Datei geschrieben.\n");

    return 0;
}
