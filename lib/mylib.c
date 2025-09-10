#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line of text from stdin safely
char *get_string(const char *prompt) {
    // Print the prompt if given
    if (prompt != NULL) {
        printf("%s", prompt);
    }

    size_t size = 64;   // initial buffer size
    char *str = malloc(size);
    if (str == NULL) {
        return NULL; // memory allocation failed
    }

    int c;
    size_t len = 0;

    // Read character by character
    while ((c = getchar()) != '\n' && c != EOF) {
        // Grow buffer if needed
        if (len + 1 >= size) {
            size *= 2;
            char *new_str = realloc(str, size);
            if (new_str == NULL) {
                free(str);
                return NULL;
            }
            str = new_str;
        }
        str[len++] = (char)c;
    }

    str[len] = '\0'; // Null-terminate the string
    return str;
}
