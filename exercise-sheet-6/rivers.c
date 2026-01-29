#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEAKS 60
#define MAX_LINE 256
#define MAX_NAME_LEN 50
#define MAX_COUNTRY_LEN 50
#define MAX_CONTINENT_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int height;
    char country[MAX_COUNTRY_LEN];
    char continent[MAX_CONTINENT_LEN];
} Peak;

int read_peaks(Peak peaks[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, fp) && count < MAX_PEAKS) {
        Peak peak;

        if (sscanf(line, "%[^:]:%d:%[^:]:%[^\n]", peak.name, &peak.height, peak.country, peak.continent) == 4) {
            peaks[count++] = peak;
        }
    }

    fclose(fp);
    return count;
}

void find_highest_and_difference(const Peak peaks[], int count, const char *continent) {
    int max_height = -1;
    int min_height = 999999;
    int max_idx = -1;
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(peaks[i].continent, continent) == 0) {
            found = 1;
            if (peaks[i].height > max_height) {
                max_height = peaks[i].height;
                max_idx = i;
            }
            if (peaks[i].height < min_height) {
                min_height = peaks[i].height;
            }
        }
    }

    if (!found) {
        printf("Continent %s not found\n", continent);
    } else {
        int difference = max_height - min_height;
        printf("%s: %s (%s) with %d m, Difference: %d m\n",
               peaks[max_idx].continent,
               peaks[max_idx].name,
               peaks[max_idx].country,
               peaks[max_idx].height,
               difference);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    Peak peaks[MAX_PEAKS];
    int count = read_peaks(peaks, "peaks.csv");

    if (count == -1) {
        return 1;
    }

    for (int i = argc - 1; i >= 1; i--) {
        find_highest_and_difference(peaks, count, argv[i]);
    }

    return 0;
}
