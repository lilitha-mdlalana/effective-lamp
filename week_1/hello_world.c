#include "../lib/mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *name = get_string("What is your name? ");
    if(name == NULL){
        fprintf(stderr, "Error reading input.\n");
    }
    printf("Hello, ", name);
    //todo:fix bug

    free(name);
    return 0;
}