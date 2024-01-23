#include <stdio.h>
#include <malloc.h>
#include <string.h>


void printSubStrings(char *str, int n, int *length, int pos) {

    if (pos >= n) {
        return;
    }

    int i;
    for (i = 0; i < length[pos]; i++) {
        printf("%c", str[i]);
    }
    printf(" ");

    printSubStrings(str + i, n, length, pos + 1);

}


void arrangement(int *solution, int *length, int n, int pos, int sum, char *str, int *flag) {

    if (sum == strlen(str)) {

        *flag = 1;

        printSubStrings(str, pos, solution, 0);
        printf("\n");

        return;
    }


    for (int i = 0; i < n; i++) {
        if (sum + length[i] > strlen(str)) {
            continue;
        }
        solution = realloc(solution, (pos + 1) * sizeof(int));
        solution[pos] = length[i];
        arrangement(solution, length, n, pos + 1, sum + solution[pos], str, flag);
    }


}



void string_split(char *str, int n, int *length) {

    int *solution;
    int flag = 0;
    arrangement(solution, length, n, 0, 0, str, &flag);
    if (flag == 0) {
        printf("Error! no sub-string could be generated with the values provided.\n");
    }

}


int main() {

    char str1[] = "Hello";
    int n1 = 2;
    int length1[2] = {2, 3};

    //printf("Substrings for the string \"%s\" are:\n\n", str1);
    //string_split(str1, n1, length1);
    //printf("\n\n");

    char str2[] = "Hello";
    int n2 = 2;
    int length2[2] = {3, 4};

    //printf("Substrings for the string \"%s\" are:\n", str2);
    //string_split(str2, n2, length2);
    //printf("\n\n");

    char str3[] = "sampleTest";
    int n3 = 3;
    int length3[3] = {2, 3, 6};

    //printf("Substrings for the string \"%s\" are:\n", str3);
    //string_split(str3, n3, length3);
    //printf("\n\n");

    return 0;
}