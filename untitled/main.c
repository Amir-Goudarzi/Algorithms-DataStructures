#include <stdio.h>

int f(int[], int);

int f(int v[], int n) {
    int r, l;
    l = 0;
    while (n != 0) {
        r = n & 1;
        n = n >> 1;
        v[l++] = r;
    }
    return l;
}

int main() {
    int i, l, v[32];
    l = f(v, 23);
    for (i = l - 1; i >= 0; i--) {
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
