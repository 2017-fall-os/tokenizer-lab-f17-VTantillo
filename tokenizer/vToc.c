#include <stdlib.h>
#include <unistd.h>

#include "vToc.h"

#define MAXBUF 1024


/*
 * Tokenizes the given string and returns an array of each token.
 */
char **vToc(char *str, char delim) {
    char **vector;
    char *tmp;
    int i, j;       // counters
    int numTokens;  // number of tokens in the string
    int len;        // length of the word being processed
    int letters;    // number of characters that have been processed

    numTokens = countWords(str, delim);
    vector = (char **)calloc((numTokens + 1), sizeof(char *));

    i = 0;
    tmp = str;
    while(i < numTokens) {
        // find the beginning of the token
        while(*tmp == delim || *tmp == '\0') {
            tmp++;
        }
        // find length of token
        len = wordLength(tmp, delim);
        // create storage for the token
        vector[i] = (char *)malloc(len + 1);
        // copy token
        j = 0;
        while (j < len) {
            vector[i][j] = *tmp;
            j++;
            tmp++;
        }
        vector[i][j + 1] = '\0';
    }
    vector[i+1] = '\0';
    return vector;
}

/*
 * Given a pointer to the string, the function returns the number of words in the string
 * seperated by the delimeter.
 */
int countWords(char *str, char delim) {
    // todo: Still need to take into consideration if there are mulitple spaces next to
    // eachother or at the beginning or the end of a string.

    int words = 0;

    char *cur;
    cur = str;

    while(*cur != '\0') {
        if (*cur == delim) {
            words ++;
        }
        cur++;
    }
    words++;    // If at the end of the sentence, need to add another word.

    return words;
}

/*
 * Given a pointer to the beginning of a word, the function returns the length of the word up to
 * the delimeter but not including.
 */
int wordLength(char *str, char delim) {
    int length = 0;

    char *cur;
    cur = str;

    while(*cur != delim && *cur != '\0') {
        length ++;
        cur++;
    }

    return length;
}
