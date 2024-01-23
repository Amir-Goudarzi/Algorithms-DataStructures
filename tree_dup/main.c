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
    node3->left = node8;


    return root;
}


void tree_dup(struct node *root) {

    if (root == NULL) {
        return;
    }

    tree_dup(root->left);
    tree_dup(root->right);
    struct node *new = new_element(root->key);
    new->left = root->left;
    root->left = new;

}

void print(struct node *root) {

    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d\n", root->key);
    print(root->right);
}


int main() {

    struct node *root = create_test_tree();
    tree_dup(root);
    print(root);

    return 0;
}