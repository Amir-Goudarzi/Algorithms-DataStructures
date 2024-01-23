#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define FILE_NAME "../input.txt"


void arrangement(char *solution, char **data, int pos, int n) {

    if (pos >= n) {
        printf("%s\n", solution);
        return;
    }

    for (int i = 0; i < strlen(data[pos]); i++) {
        solution[pos] = data[pos][i];
        arrangement(solution, data, pos + 1, n);
    }

}


int main() {

    FILE *fin;
    fin = fopen(FILE_NAME, "r");
    if (fin == NULL) {
        exit(-1);
    }

    int n = fgetc(fin) - '0';

    char **data;
    data = malloc(n * sizeof(char **));
    for (int i = 0; i < n; i++) {
        data[i] = malloc(sizeof(char *));
    }


    int i = 0;
    while (!feof(fin)) {
        fscanf(fin, "%s", data[i]);
        i++;
    }

    char *solution;
    solution = calloc(n + 1, sizeof(char));


    arrangement(solution, data, 0, n);


    return 0;
}