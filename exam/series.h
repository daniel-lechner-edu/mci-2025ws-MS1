#ifndef SERIES_H
#define SERIES_H

#define MAX_SERIES 100
#define MAX_NAME 100
#define MAX_GENRES 5
#define MAX_GENRE_LEN 50
#define MAX_LINE 500
#define MAX_GENRE_STR 200
#define CSV_FIELD_COUNT 4
#define MINUTES_PER_HOUR 60.0

typedef struct {
  char name[MAX_NAME];
  char genres[MAX_GENRES][MAX_GENRE_LEN];
  int genre_count;
  int seasons;
  int episodes;
  double avg_duration;
  double rating;
} Series;

#endif
