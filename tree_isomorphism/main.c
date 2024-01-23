#include <stdio.h>
#include <string.h>
#include <malloc.h>


struct node {
    char *key;
    struct node *left;
    struct node *right;
};


struct node *new_element(char *val) {
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Error allocating memory!\n");
        exit(-1);
    }
    new->key = calloc((strlen(val) + 1), sizeof(char));
    strcpy(new->key, val);
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
    struct node *root = new_element("1");
    struct node *node1 = new_element("2");
    struct node *node2 = new_element("3");
    struct node *node3 = new_element("4");
    struct node *node4 = new_element("5");
    struct node *node5 = new_element("6");
    struct node *node8 = new_element("9");

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node3->left = node8;


    return root;
}


int tree_isomorphism(struct node *t1, struct node *t2) {

    if (t1 == NULL && t2 == NULL) {
        return 1;
    }
    if (t1 == NULL && t2 != NULL) {
        return 0;
    }
    if (t1 != NULL && t2 == NULL) {
        return 0;
    }


    if (strcmp(t1->key, t2->key)) {
        return 0;
    }

    if (!tree_isomorphism(t1->left, t2->left)) {
        return 0;
    }

    if (!tree_isomorphism(t1->right, t2->right)) {
        return 0;
    }

    return 1;
}


int main() {

    struct node *t1 = create_test_tree();
    struct node *t2 = create_test_tree();
    //strcpy(t2->left->right->key, "0");
    //t2->left->left->left = NULL;
    if (tree_isomorphism(t1, t2)) {
        printf("Identical!\n");
    } else {
        printf("Different!\n");
    }

    return 0;
}