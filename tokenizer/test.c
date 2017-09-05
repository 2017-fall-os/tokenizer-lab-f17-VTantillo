#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vToc.h"

#define MAXBUF 1024

int main() {
    // Read in a string
    // Pass to tokenizer

    char *str = "Oh hello.";

    char **vector;
    vector = vToc(str, ' ');
    return 0;
}
