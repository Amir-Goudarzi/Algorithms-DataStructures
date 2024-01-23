#include <stdio.h>
#include <malloc.h>


typedef struct node_s {
    int key;
    struct node_s *left;
    struct node_s *right;
} node_t;


node_t *new(int val) {

    node_t *new = malloc(sizeof(node_t));
    new->key = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}


node_t *createTestBST() {

    node_t *root = new(12);
    root->left = new(5);
    root->left->left = new(2);
    root->left->right = new(9);
    root->right = new(18);
    root->right->left = new(15);
    root->right->left->right = new(17);
    root->right->right = new(19);


    return root;
}



void visitBST(node_t *root) {

    if (root == NULL) {
        return;
    }

    printf("%d\n", root->key);
    visitBST(root->left);
    visitBST(root->right);

}


void searchBST(node_t *root, int **Path, int *path, int value, int pos, int *size) {

    if (root == NULL) {
        printf("Error! key %d not found in the tree!\n", value);
        exit(-1);
    }

    path = realloc(path, (pos + 1) * sizeof(int));
    if (path == NULL) {
        printf("Error allocating memory!\n");
        exit(-1);
    }

    path[pos] = root->key;

    if (value == root->key) {
        *Path = path;
        *size = pos + 1;
        return;
    }

    if (value > root->key) {
        searchBST(root->right, Path, path, value, pos + 1, size);
    } else {
        searchBST(root->left, Path, path, value, pos + 1, size);
    }

}


int distance(node_t *root, int key1, int key2) {

    int *path1 = malloc(sizeof(int));
    int *path2 = malloc(sizeof(int));
    int size1, size2;

    searchBST(root, &path1, path1, key1, 0, &size1);
    searchBST(root, &path2, path2, key2, 0, &size2);


    int index = 0, difference;
    while (path1[index] == path2[index]) {
        index++;
    }

    free(path1);
    free(path2);

    difference = (size1 - index) + (size2 - index);
    return difference;
}


int main() {

    node_t *root = createTestBST();

    printf("Distance between nodes with keys 17 and 9: %d\n", distance(root, 17, 9));
    printf("Distance between nodes with keys 12 and 19: %d\n", distance(root, 12, 19));

    return 0;
}