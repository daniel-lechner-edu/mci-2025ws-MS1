#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 50
#define MAX_LINE 256
#define MAX_NAME_LEN 50
#define MAX_COUNTRY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char country[MAX_COUNTRY_LEN];
    int population;
    double area;
    double density;
} City;

int read_cities(City cities[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, fp) && count < MAX_CITIES) {
        City city;

        if (sscanf(line, "%[^;];%[^;];%d;%lf", city.name, city.country, &city.population, &city.area) == 4) {
            city.density = city.population / city.area;
            cities[count++] = city;
        }
    }

    fclose(fp);
    return count;
}

void find_highest_density_city(const City cities[], int count, const char *country) {
    double max_density = -1;
    int max_idx = -1;

    for (int i = 0; i < count; i++) {
        if (strcmp(cities[i].country, country) == 0) {
            if (cities[i].density > max_density) {
                max_density = cities[i].density;
                max_idx = i;
            }
        }
    }

    if (max_idx == -1) {
        printf("Country '%s' not found\n", country);
    } else {
        printf("%s: %s with %.2f people per km2\n",
               cities[max_idx].country,
               cities[max_idx].name,
               cities[max_idx].density);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    City cities[MAX_CITIES];
    int count = read_cities(cities, "cities.csv");

    if (count == -1) {
        return 1;
    }

    for (int i = argc - 1; i >= 1; i--) {
        find_highest_density_city(cities, count, argv[i]);
    }

    return 0;
}
