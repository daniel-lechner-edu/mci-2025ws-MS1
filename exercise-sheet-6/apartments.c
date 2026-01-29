#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APARTMENTS 60
#define MAX_LINE 512
#define MAX_EXTRAS 10
#define MAX_EXTRA_LEN 30
#define MAX_CITY_LEN 50
#define MAX_ADDRESS_LEN 100

typedef struct {
    char city[MAX_CITY_LEN];
    char address[MAX_ADDRESS_LEN];
    double area;
    int rooms;
    char extras[MAX_EXTRAS][MAX_EXTRA_LEN];
    int extra_count;
} Apartment;

int read_apartments(Apartment apartments[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, fp) && count < MAX_APARTMENTS) {
        Apartment apt;
        char extras_str[MAX_LINE];

        char *token = strtok(line, ";");
        if (!token) continue;
        strncpy(apt.city, token, MAX_CITY_LEN - 1);
        apt.city[MAX_CITY_LEN - 1] = '\0';

        token = strtok(NULL, ";");
        if (!token) continue;
        strncpy(apt.address, token, MAX_ADDRESS_LEN - 1);
        apt.address[MAX_ADDRESS_LEN - 1] = '\0';

        token = strtok(NULL, ";");
        if (!token) continue;
        apt.area = atof(token);

        token = strtok(NULL, ";");
        if (!token) continue;
        apt.rooms = atoi(token);

        token = strtok(NULL, ";\n");
        if (!token) continue;
        strncpy(extras_str, token, MAX_LINE - 1);
        extras_str[MAX_LINE - 1] = '\0';

        apt.extra_count = 0;
        char *extra_token = strtok(extras_str, ":");
        while (extra_token && apt.extra_count < MAX_EXTRAS) {
            strncpy(apt.extras[apt.extra_count], extra_token, MAX_EXTRA_LEN - 1);
            apt.extras[apt.extra_count][MAX_EXTRA_LEN - 1] = '\0';
            apt.extra_count++;
            extra_token = strtok(NULL, ":");
        }

        apartments[count++] = apt;
    }

    fclose(fp);
    return count;
}

int has_all_extras(const Apartment *apt, char *required_extras[], int required_count) {
    for (int i = 0; i < required_count; i++) {
        int found = 0;
        for (int j = 0; j < apt->extra_count; j++) {
            if (strcmp(apt->extras[j], required_extras[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

void print_matching_apartments(const Apartment apartments[], int count, const char *city,
                               double min_area, int min_rooms, char *required_extras[], int required_count) {
    int found = 0;

    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(apartments[i].city, city) == 0 &&
            apartments[i].area >= min_area &&
            apartments[i].rooms >= min_rooms &&
            has_all_extras(&apartments[i], required_extras, required_count)) {

            printf("%s: %.1f m2, %d Zimmer", apartments[i].address, apartments[i].area, apartments[i].rooms);

            for (int j = 0; j < apartments[i].extra_count; j++) {
                printf(", %s", apartments[i].extras[j]);
            }
            printf("\n");

            found = 1;
        }
    }

    if (!found) {
        fprintf(stderr, "Parameterfehler\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    char *city = argv[1];
    double min_area = atof(argv[2]);
    int min_rooms = atoi(argv[3]);

    char **required_extras = &argv[4];
    int required_count = argc - 4;

    Apartment apartments[MAX_APARTMENTS];
    int count = read_apartments(apartments, "apartments.csv");

    if (count == -1) {
        return 1;
    }

    print_matching_apartments(apartments, count, city, min_area, min_rooms, required_extras, required_count);

    return 0;
}
