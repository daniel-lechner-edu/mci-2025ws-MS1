#include "series_filter.h"
#include <stdio.h>
#include <string.h>

int has_genre(Series *s, const char *genre) {
  for (int i = 0; i < s->genre_count; i++) {
    if (strcmp(s->genres[i], genre) == 0) {
      return 1;
    }
  }
  return 0;
}

double calc_total_hours(Series *s) {
  return (s->episodes * s->avg_duration) / MINUTES_PER_HOUR;
}

int meets_length_requirement(double total_hours, double length_param) {
  if (length_param < 0) {
    return total_hours >= -length_param;
  }
  return total_hours <= length_param;
}

void print_series(Series *s) {
  double total_hours = calc_total_hours(s);
  printf(
      "%s: %d Staffeln, %.2f Stunden, %.1f Sterne\n", s->name, s->seasons,
      total_hours, s->rating
  );
}

int filter_and_print(
    Series *series,
    int count,
    const char *genre,
    double length_param,
    double min_rating
) {
  int found = 0;

  for (int i = count - 1; i >= 0; i--) {
    if (!has_genre(&series[i], genre)) {
      continue;
    }

    if (series[i].rating < min_rating) {
      continue;
    }

    double total_hours = calc_total_hours(&series[i]);

    if (!meets_length_requirement(total_hours, length_param)) {
      continue;
    }

    print_series(&series[i]);
    found++;
  }

  return found;
}
