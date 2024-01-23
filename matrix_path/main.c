#include <stdio.h>
#include <malloc.h>


void findMax(int **solution, int *optimal, int sum, int pos, int n) {

    static int max = 0;
    static int size = 0;

    if (sum < max || (sum == max && size < pos)) {
        return;
    }

    size = pos;
    max = sum;
    for (int i = 0; i <= pos; i++) {
        optimal[i] = *solution[i];
    }
    optimal[n * n + 1] = sum;
    optimal[n * n] = size;


}


void matrixPath(int **mat, int **solution, int *optimal, int n, int i, int j, int sum, int pos) {

    if (i >= n || j >= n || i < 0 || j < 0) {
        return;
    }

    solution = realloc(solution, (pos + 1) * sizeof(int *));
    if (solution == NULL) {
        printf("%d\n", pos);
        printf("Memory allocation error!\n");
        exit(-1);
    }

    solution[pos] = &mat[i][j];
    sum += mat[i][j];


    if (i == n - 1 && j == n - 1) {
        findMax(solution, optimal, sum, pos, n);
        return;
    }

    int Break;

    for (int row = -1; row <= 1; row++) {

        for (int column = -1; column <= 1; column++) {

            if (!(i + row >= n || j + column >= n || i + row < 0 || j + column < 0)) {

                Break = 0;
                if (!(row == 0 && column == 0)) {
                    for (int index = 0; index <= pos; index++) {
                        if (solution[index] == &(mat[i + row][j + column])) {
                            Break = 1;
                            break;
                        }
                    }
                    if (!Break) {
                        matrixPath(mat, solution, optimal, n, i + row, j + column, sum, pos + 1);
                    }
                }
            }
        }
    }


}


int main() {

    int n = 3;
    int **mat = malloc(n * sizeof(int *));
    if (mat == NULL) {
        printf("Memory allocation error!\n");
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
        if (mat[i] == NULL) {
        printf("Memory allocation error!\n");
        exit(-1);
    }
    }

    // The test matrix:
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = -3;
    mat[1][0] = 9;
    mat[1][1] = -9;
    mat[1][2] = 7;
    mat[2][0] = 0;
    mat[2][1] = 1;
    mat[2][2] = 4;

    int **solution = malloc(sizeof(int *));
    if (solution == NULL) {
        printf("Memory allocation error!\n");
        exit(-1);
    }

    int optimal[n * n + 2];

    matrixPath(mat, solution, optimal, n, 0, 0, 0, 0);

    printf("Sum: %d\nPath: ", optimal[n * n + 1]);
    for (int index = 0; index <= optimal[n * n]; index++) {
        printf("%d ", optimal[index]);
    }

    return 0;
}