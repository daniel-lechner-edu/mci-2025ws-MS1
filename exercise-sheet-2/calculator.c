#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        fprintf(stderr, "Usage: %s <num1> <operator> <num2>\n", argv[0]);
        fprintf(stderr, "Example: %s 7 + 4\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    char *op = argv[2];
    int num2 = atoi(argv[3]);
    int result;

    if (strcmp(op, "+") == 0) {
        result = add(num1, num2);
    } else if (strcmp(op, "-") == 0) {
        result = subtract(num1, num2);
    } else if (strcmp(op, "*") == 0) {
        result = multiply(num1, num2);
    } else if (strcmp(op, "/") == 0) {
        if (num2 == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            return 1;
        }
        result = divide(num1, num2);
    } else {
        fprintf(stderr, "Error: Unknown operator '%s'\n", op);
        fprintf(stderr, "Valid operators: +, -, *, /\n");
        return 1;
    }

    printf("%d\n", result);
    return 0;
}
