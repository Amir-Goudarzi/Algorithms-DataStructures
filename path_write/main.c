#include <stdio.h>
#include <malloc.h>


struct node {
    int key;
    struct node *left;
    struct node *right;
};


struct node *new_element(int val) {
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Error allocating memory!\n");
        exit(-1);
    }

    new->key = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct node *create_test_tree() {

    /*               1
               2          3
           4      5    6
       9
    */
    struct node *root = new_element(1);
    struct node *node1 = new_element(2);
    struct node *node2 = new_element(3);
    struct node *node3 = new_element(4);
    struct node *node4 = new_element(5);
    struct node *node5 = new_element(6);
    struct node *node8 = new_element(9);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node3->right = node8;


    return root;
}


void path_writer(struct node *root, int height, int pos, int *path) {

    if (root == NULL) {
        return;
    }

    path[pos] = root->key;

    path_writer(root->left, height, pos + 1, path);
    path_writer(root->right, height, pos + 1, path);
    printf("%d, path: ", root->key);
    for (int i = 0; i <= pos; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

}



void path_write(struct node *root, int height) {
    int *path;
    path = malloc(height * sizeof(int));
    path_writer(root, height, 0, path);
}



int main() {

    struct node *root = create_test_tree();
    path_write(root, 4);

    return 0;
}
