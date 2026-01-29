#include "series_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_next_token(char **saveptr, int line_num) {
  char *token = strtok_r(NULL, ";", saveptr);
  if (!token) {
    fprintf(stderr, "Zeilenfehler in Zeile %d\n", line_num);
  }
  return token;
}

void parse_genres(char *genre_str, Series *s) {
  char *saveptr;
  char *token = strtok_r(genre_str, ",", &saveptr);
  s->genre_count = 0;
  while (token && s->genre_count < MAX_GENRES) {
    strcpy(s->genres[s->genre_count++], token);
    token = strtok_r(NULL, ",", &saveptr);
  }
}

int parse_series_line(char *line, Series *s, int line_num) {
  char line_copy[MAX_LINE];
  strcpy(line_copy, line);

  char *saveptr;
  char *token = strtok_r(line_copy, ";", &saveptr);
  if (!token) {
    fprintf(stderr, "Zeilenfehler in Zeile %d\n", line_num);
    return 0;
  }
  strcpy(s->name, token);

  token = get_next_token(&saveptr, line_num);
  if (!token)
    return 0;
  char genre_str[MAX_GENRE_STR];
  strcpy(genre_str, token);

  char *fields[CSV_FIELD_COUNT];
  for (int i = 0; i < CSV_FIELD_COUNT; i++) {
    fields[i] = get_next_token(&saveptr, line_num);
    if (!fields[i])
      return 0;
  }

  s->seasons = atoi(fields[0]);
  s->episodes = atoi(fields[1]);
  s->avg_duration = atof(fields[2]);
  s->rating = atof(fields[3]);

  parse_genres(genre_str, s);

  return 1;
}

int read_series(const char *filename, Series *series, int max_series) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Lesefehler: Datei konnte nicht geoeffnet werden\n");
    return -1;
  }

  char line[MAX_LINE];
  int count = 0;
  int line_num = 0;

  while (fgets(line, sizeof(line), file) && count < max_series) {
    line_num++;

    if (parse_series_line(line, &series[count], line_num)) {
      count++;
    }
  }

  fclose(file);
  return count;
}
