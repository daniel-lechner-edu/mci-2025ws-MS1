#ifndef SERIES_FILTER_H
#define SERIES_FILTER_H

#include "series.h"

int has_genre(Series *s, const char *genre);
double calc_total_hours(Series *s);
int meets_length_requirement(double total_hours, double length_param);
void print_series(Series *s);
int filter_and_print(
    Series *series,
    int count,
    const char *genre,
    double length_param,
    double min_rating
);

#endif
