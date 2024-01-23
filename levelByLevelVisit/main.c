#include <stdio.h>
#include <malloc.h>

#define N 2


struct node {
    int key;
    struct node *child[N];
};

struct node *new() {
    struct node *new;
    new = malloc(sizeof(struct node));
    for (int i = 0; i < N; i++) {
        new->child[i] = NULL;
    }
    return new;
}

struct node *create_test_tree() {

    struct node *root;
    root = new();
    root->key = 1;
    struct node *l1;
    l1 = new();
    l1->key = 2;
    struct node *l2;
    l2 = new();
    l2->key = 3;
    struct node *r1;
    r1 = new();
    r1->key = 4;
    struct node *r2;
    r2 = new();
    r2->key = 6;
    struct node *lr1;
    lr1 = new();
    lr1->key = 5;
    struct node *rr2;
    rr2 = new();
    rr2->key = 10;


    root->child[0] = l1;
    root->child[1] = r1;
    l1->child[0] = l2;
    r1->child[0] = lr1;
    r1->child[1] = r2;
    r2->child[1] = rr2;

    return root;
}



void levelByLevel_visit(struct node *root, int l1, int l2, int level) {

    if (root == NULL) {
        return;
    }


    if (level >= l1 && level <= l2) {
        printf("%d\n", root->key);
    }

    for (int i = 0; i < N; i++) {
        levelByLevel_visit(root->child[i], l1, l2, level + 1);
    }


}


int main() {

    struct node *test_tree;
    test_tree = create_test_tree();
    levelByLevel_visit(test_tree, 0, 3, 0);

    return 0;
}