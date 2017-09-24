#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vToke.h"

#define MAXBUF 2000

int main(int argc, char const *argv[]) {
    char *string = "Hi I'm vic";
    char **tokens;

    int numTokens;
    int i;
    numTokens = countTokens(string, ' ');
    printf("%d\n", numTokens);

    tokens = vToke(string, ' ');
    for (i = 0; tokens[i]; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}
