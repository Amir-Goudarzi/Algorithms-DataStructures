#include <stdio.h>
#include <malloc.h>


void checkAndPrint(int **solution, int size) {

    int s[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int flags[8] = {0};
    int i, j, k, flag = 1;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < size; j++) {
            k = 0;
            while (solution[j][k] != 0) {
                if (solution[j][k] == s[i]) {
                    flags[i] = 1;
                }
                k++;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        if (flags[i] == 0) {
            flag = 0;
            break;
        }
    }

    if (!flag) {
        return;
    }

    for (i = 0; i < size; i++) {
        j = 0;
        while (solution[i][j] != 0) {
            printf("%d ", solution[i][j]);
            j++;
        }
        printf("\n");
    }
    printf("\n\n");

}


void combination(int m[][9], int **solution, int *mark, int n, int k, int pos, int start) {


    if (pos >= k) {
        checkAndPrint(solution, k);
        return;
    }

    for (int i = start; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            int count = 0;
            while (m[i][count] != 0) {
                count++;
            }
            solution[pos] = malloc((count + 1) * sizeof(int));
            count = 0;
            while (m[i][count] != 0) {
                solution[pos][count] = m[i][count];
                count++;
            }
            solution[pos][count] = 0;
            combination(m, solution, mark, n, k, pos + 1, i + 1);
            mark[i] = 0;
        }
    }

}


void cover(int m[][9], int n, int k) {

    int **solution = malloc(k * sizeof(int *));
    int *mark = calloc(n - 1, sizeof(int));


    combination(m, solution, mark, n, k, 0, 0);

}



int main() {

    int m[][9] = {{1,2,3,0,0,0,0,0,0},
                  {2,3,7,0,0,0,0,0,0},
                  {7,8,0,0,0,0,0,0,0},
                  {3,4,0,0,0,0,0,0,0},
                  {4,5,6,0,0,0,0,0,0}};

    cover(m, 5, 3);

    return 0;
}