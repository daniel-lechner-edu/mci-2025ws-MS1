#include "my_string.h"
#include <stddef.h>

int string_cmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }
    return 0;
}

unsigned int string_len(const char* str) {
    unsigned int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void string_rev(char* str) {
    unsigned int len = string_len(str);
    for (unsigned int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

const char *string_chr(const char* str, const char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}
