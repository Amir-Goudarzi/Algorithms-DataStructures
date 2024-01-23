#include <stdio.h>
#include <malloc.h>


void matrix_path(int **mat, int **solution, int n, int i, int j, int sum, int pos) {

    solution = realloc(solution, (pos + 1) * sizeof(int *));
    if (solution == NULL) {
        printf("%d\n", pos);
        printf("Memory allocation error!\n");
        exit(-1);
    }

    solution[pos] = &mat[i][j];
    sum += mat[i][j];

    if (i ==  n - 1 && j == n - 1) {
        printf("sum: %d\npath:\n", sum);
        for (int index = 0; index <= pos; index++) {
            printf("%d ", *solution[index]);
        }
        return;
    }

    int flag = 0, maxr, maxc, max;
    for (int row = -1; row <= 1; row++) {
        for (int column = -1; column <= 1; column++) {

            if (!(i + row >= n || j + column >= n || i + row < 0 || j + column < 0)) {

                int Break = 0;
                if (!(row == 0 && column == 0)) {
                    if (flag == 0) {
                        flag = 1;
                        max = mat[i + row][j + column];
                        maxr = row;
                        maxc = column;
                    } else {
                        if (mat[i + row][j + column] > max) {
                            for (int index = 0; index <= pos; index++) {
                                if (solution[index] == &mat[i + row][j + column]) {
                                    Break = 1;
                                    break;
                                }
                            }
                            if (!Break) {
                                max = mat[i + row][j + column];
                                maxr = row;
                                maxc = column;
                            }
                        }
                    }
                }
            }
        }
    }


    matrix_path(mat, solution, n, i + maxr, j + maxc, sum, pos + 1);

}


int main() {

    int n = 3;
    int **mat = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
    }


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
    matrix_path(mat, solution, n, 0, 0, 0, 0);

    return 0;
}