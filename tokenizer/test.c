#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vToc.h"

#define MAXBUF 1024

char *printVector(char **vec) {
    char *string = (char *)malloc(MAXBUF);
    char *tmp;
    tmp = string;
    int i, j;
    i = 0;
    while(vec[i] != '\0')  {
        j = 0;
        while(vec[i][j] != '\0'){
            *tmp = vec[i][j];
            tmp ++;
            j ++;
        }
        *tmp = '\n';
        tmp ++;
        i ++;
    }
    *tmp = '\0';
    return string;
}

// Test case 1 for the string "Hello my dog's name is Darwin"
void testCase(char *testStr, int actualWords) {
    char *output;
    int numWords;       // Number of words my method finds.

    numWords = countWords(testStr, ' ');

    printf("\n%s%s\n", "Testing: ", testStr);
    printf("%s\n", "Word count:");
    if (actualWords == numWords) {
        printf("%s\n\n", "Pass");
    } else {
        printf("%s\n\n", "Fail");
    }
    char **vector;

    vector = vToc(testStr, ' ');

    printf("%s\n", "Tokens:");
    output = printVector(vector);
    printf("%s\n", output);
}

void runCases() {
    testCase("Hello my dog's name is Darwin", 6);
    testCase("     Hello   World!    ", 2);
    testCase("", 0);
    testCase("         ", 0);
    testCase(" HelloWorld!", 1);
}

int main() {
    runCases();
    return 0;
}
