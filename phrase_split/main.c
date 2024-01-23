#include <stdio.h>
#include <string.h>
#include <malloc.h>


void recursiveSplit(char v[], char **matrix, int pos, int *count, char ***m) {

    if (v[0] == '\0') {
        *m = matrix;
        return;
    }

    int i = 0;
    while (v[i] != ' ' && v[i] != '\0') {
        i++;
    }

    matrix[pos] = calloc(i + 1, sizeof(char));
    strncpy(matrix[pos], v, i);
    (*count)++;

    recursiveSplit(v + i + 1, matrix, pos + 1, count, m);

}


int phrase_split(char v[], char ***m) {

    int count = 0;
    char **matrix;

    for (int i = 0; i < strlen(v); i++) {
        if (v[i] == ' ') {
            count++;
        }
    }

    matrix = malloc((count + 1) * sizeof(char *));
    count = 0;

    recursiveSplit(v, matrix, 0, &count, m);

    return count;
}


int main() {

    char v[] = "This is a phrase to be split into sub-strings";
    char **m;
    int n, i;

    n = phrase_split(v, &m);

    for (i = 0; i < n; i++) {
        printf("String number %d = %s\n", i + 1, m[i]);
    }

    return 0;
}