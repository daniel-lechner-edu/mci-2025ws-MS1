#ifndef SERIES_IO_H
#define SERIES_IO_H

#include "series.h"

char *get_next_token(char **saveptr, int line_num);
void parse_genres(char *genre_str, Series *s);
int parse_series_line(char *line, Series *s, int line_num);
int read_series(const char *filename, Series *series, int max_series);

#endif
