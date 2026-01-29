#include "series.h"
#include "series_filter.h"
#include "series_io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Eingabefehler: 3 Parameter erforderlich\n");
    return 1;
  }

  const char *genre = argv[1];
  double length_param = atof(argv[2]);
  double min_rating = atof(argv[3]);

  Series series[MAX_SERIES];
  int count = read_series("series.csv", series, MAX_SERIES);

  if (count < 0) {
    return 1;
  }

  int found = filter_and_print(series, count, genre, length_param, min_rating);

  if (found == 0) {
    fprintf(stderr, "Parameterfehler: Keine passenden Serien gefunden\n");
    return 1;
  }

  return 0;
}
