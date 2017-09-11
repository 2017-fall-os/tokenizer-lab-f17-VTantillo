#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vToc.h"

#define MAXBUF 1024

char buf[MAXBUF];

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

int isQuit(char *str) {
    char *quit = "quit";
    char *q;
    char *tmp;
    tmp = str;
    q = quit;

    while (*tmp != '\0') {
        if (*q == *tmp) {
            return 0;
        }
        tmp ++;
        q ++;
    }

    return 1;
}

int main() {
    int length;
    char *str;
    char **vector;

    vector = (char **)calloc(1, sizeof(char*));

    while (isQuit(str)) {
        free(vector);
        write(0, "$ ", 2);
        length = read(1, buf, MAXBUF);
        str = buf;
        vector = vToc(str, ' ');
        str = printVector(vector);
        write(0, str, (length - 1));
        write(0, "\n", 1);
        str = buf;
    }

    return 0;
}
