# Exam - Series

## Usage

### Compilation and Execution:

```bash
cc ./series.c ./series_io.c ./series_filter.c -Wall -Werror -o series
./series <Genre> <Length> <MinRating>
```

**Examples:**

```bash
./series Crime -45 8.9 # >=45 hours (negative = minimum)
./series Comedy 20 7.5 # <=20 hours (positive = maximum)
```

## Architecture

Code split into `series_io` (parsing/file handling) and `series_filter` (business logic) for separation of concerns. This improves readability and testability.
