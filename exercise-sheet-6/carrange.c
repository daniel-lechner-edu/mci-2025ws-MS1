#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 40
#define MAX_LINE 256
#define MAX_COLORS 10
#define MAX_COLOR_LEN 20
#define MAX_BRAND_LEN 50
#define MAX_MODEL_LEN 50

typedef struct {
    char brand[MAX_BRAND_LEN];
    char model[MAX_MODEL_LEN];
    double consumption;
    double tank_size;
    char colors[MAX_COLORS][MAX_COLOR_LEN];
    int color_count;
    double range;
} Car;

int read_cars(Car cars[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Lesefehler\n");
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, MAX_LINE, fp) && count < MAX_CARS) {
        Car car;
        char colors_str[MAX_LINE];

        char *token = strtok(line, ":");
        if (!token) continue;
        strncpy(car.brand, token, MAX_BRAND_LEN - 1);
        car.brand[MAX_BRAND_LEN - 1] = '\0';

        token = strtok(NULL, ":");
        if (!token) continue;
        strncpy(car.model, token, MAX_MODEL_LEN - 1);
        car.model[MAX_MODEL_LEN - 1] = '\0';

        token = strtok(NULL, ":");
        if (!token) continue;
        car.consumption = atof(token);

        token = strtok(NULL, ":");
        if (!token) continue;
        car.tank_size = atof(token);

        token = strtok(NULL, ":\n");
        if (!token) continue;
        strncpy(colors_str, token, MAX_LINE - 1);
        colors_str[MAX_LINE - 1] = '\0';

        car.range = (car.tank_size / car.consumption) * 100.0;

        car.color_count = 0;
        char *color_token = strtok(colors_str, ",");
        while (color_token && car.color_count < MAX_COLORS) {
            strncpy(car.colors[car.color_count], color_token, MAX_COLOR_LEN - 1);
            car.colors[car.color_count][MAX_COLOR_LEN - 1] = '\0';
            car.color_count++;
            color_token = strtok(NULL, ",");
        }

        cars[count++] = car;
    }

    fclose(fp);
    return count;
}

int has_color(const Car *car, const char *color) {
    for (int i = 0; i < car->color_count; i++) {
        if (strcmp(car->colors[i], color) == 0) {
            return 1;
        }
    }
    return 0;
}

void print_matching_cars(const Car cars[], int count, double min_range, const char *color) {
    int found = 0;

    for (int i = count - 1; i >= 0; i--) {
        if (cars[i].range >= min_range && has_color(&cars[i], color)) {
            printf("%s %s: %.2f km\n", cars[i].brand, cars[i].model, cars[i].range);
            found = 1;
        }
    }

    if (!found) {
        fprintf(stderr, "Parameterfehler\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Eingabefehler\n");
        return 1;
    }

    double min_range = atof(argv[1]);
    char *color = argv[2];

    Car cars[MAX_CARS];
    int count = read_cars(cars, "cars.csv");

    if (count == -1) {
        return 1;
    }

    print_matching_cars(cars, count, min_range, color);

    return 0;
}
