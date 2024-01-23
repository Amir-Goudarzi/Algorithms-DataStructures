#include <stdio.h>
#include <malloc.h>


void combinations(int *vet, int *solution, int *mark, int n, int m, int k, int pos, int *count, int start) {

    if (pos >= k) {
        for (int i = 0; i < pos; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        (*count)++;
        return;
    }


    for (int i = start; i < n; i++) {
        if (mark[vet[i] - 1] == 0) {
            mark[vet[i] - 1] = 1;
            solution[pos] = i;
            combinations(vet, solution, mark, n, m, k, pos + 1, count, i + 1);
            mark[vet[i] - 1] = 0;
        }
    }

}


int birthday(int *vet, int n, int m, int k) {

    int *solution = malloc(k * sizeof(int));
    int *mark = calloc(m, sizeof(int));

    int count = 0;
    combinations(vet, solution, mark, n, m, k, 0, &count, 0);
    return count;

}


int main() {

    int vet1[] = {2,1,1,4,3};
    int n1 = 5, m1 = 4, k1 = 3;

    printf("\nTotal number of possibilities for the selected "
           "values: %d\n\n\n", birthday(vet1, n1, m1, k1));

    int vet2[] = {1,2,3,1,2,3};
    int n2 = 6, m2= 3, k2= 2;

    printf("\nTotal number of possibilities for the selected "
           "values: %d\n\n\n", birthday(vet2, n2, m2, k2));

    return 0;
}