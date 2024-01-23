#include <stdio.h>
#include <malloc.h>

#define n 4
#define m 5

void checkAndPrint(int mat[n][m], int *solution, int k) {

    int flag = 1, i, j;
    int bulbs[m] = {0};

    for (i = 0; i < k; i++) {
        for (j = 0; j < m; j++) {
            if (mat[solution[i]][j]) {
                bulbs[j] = 1;
            }
        }
    }

    for (i = 0; i < m; i++) {
        if (!bulbs[i]) {
            flag = 0;
        }
    }

    if (flag) {
        for (i = 0; i < k; i++) {
            printf("%d ",solution[i]);
        }
        printf("\n");
    }

}


void combinations(int mat[n][m], int *solution, int start, int pos, int k) {

    if (pos >= k) {
        checkAndPrint(mat, solution, pos);
        return;
    }

    for (int i = start; i < n; i++) {
        solution[pos] = i;
        combinations(mat, solution, i + 1, pos + 1, k);
    }

}


int main() {


    int mat[n][m] = {{1,1,0,0,1},
                     {1,0,1,0,0},
                     {0,1,1,1,0},
                     {1,0,0,1,0}};

    for (int j = 1; j <= n; j++) {
        int *solution = malloc(j * sizeof(int));
        combinations(mat, solution, 0, 0, j);
    }

    return 0;
}