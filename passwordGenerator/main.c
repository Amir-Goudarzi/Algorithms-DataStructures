#include <stdio.h>
#include <malloc.h>

#define N 5

void digit(char *solution, int *mark, int n, int pos, int start, int end, int reps) {

    if (pos == N) {
        printf("%s\n", solution);
        return;
    }

    for (int i = start; i <= end; i++) {
        int index = i - start;
        if (mark[index] > 0) {
            mark[index]--;
            solution[pos] = (char) (i);
            digit(solution, mark, n, pos + 1, start, end, reps);
            mark[index]++;
        }
    }

}


void alphabetic(char *solution, int *mark, int n, int pos, int start, int end, int reps) {


    if (pos == 3) {
        start = (int) ('0');
        end = (int) ('9');
        int length = end - start + 1;
        int *mark_digits = malloc(length * sizeof(int));
        if (mark_digits == NULL) {
            printf("Error allocating memory!\n");
            exit(-1);
        }
        for (int i = 0; i < length; i++) {
            mark_digits[i] = n;
        }

        digit(solution, mark_digits, n, pos, '0', '9', n);
        return;

    }

    for (int i = start; i <= end; i++) {
        int index = i - start;
        if (mark[index] > 0) {
            mark[index]++;
            solution[pos] = (char) (i);
            alphabetic(solution, mark, n, pos + 1, start, end, reps);
            mark[index]--;
        }
    }


}


int main() {

    int n;
    printf("Enter integer n: \n");
    scanf("%d", &n);
    if (n > 3) {
        printf("Incorrect value for n!\n");
        exit(-1);
    }

    char solution[N + 1];
    solution[N] = '\0';

    int start = (int) ('A');
    int end = (int) ('Z');
    int length = end - start + 1;

    int *mark = malloc(length * sizeof(int));
    if (mark == NULL) {
        printf("Error allocating memory!\n");
        exit(-1);
    }
    for (int i = 0; i < length; i++) {
        mark[i] = n;
    }


    alphabetic(solution, mark, n, 0, 'A', 'Z', n);

    return 0;
}
