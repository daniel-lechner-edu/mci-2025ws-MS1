#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Missing argument\n");
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d", i);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            } else {
                printf("\t");
            }
        }
    }

    if (count % 10 != 0) {
        printf("\n");
    }

    return 0;
}
