#include <stdio.h>
#include <malloc.h>


typedef struct list_s {
    int value;
    struct list_s *next;
} list_t;



list_t *new_element(int key);
list_t *createTestList();

void visitList(list_t *head);

list_t *recursiveSplit2(list_t *head, int threshold, list_t *head1, list_t *head2);
list_t *recursiveSplit1(list_t *head, int threshold, list_t *head1, list_t *head2);

void freeList(list_t *head);

void split(list_t **head, int threshold, list_t **head1, list_t **head2);



int main() {

    list_t *head = createTestList();

    visitList(head);
    list_t *head1, *head2;
    split(&head, 18, &head1, &head2);
    visitList(head1);
    visitList(head2);


    return 0;
}


list_t *new_element(int key) {

    list_t *new;
    new = malloc(sizeof(list_t));
    new->value = key;
    new->next = NULL;

    return new;
}



list_t *createTestList() {

    list_t *head;
    head = new_element(7);
    list_t *p = head;
    p->next = new_element(8);
    p = p->next;
    p->next = new_element(25);
    p = p->next;
    p->next = new_element(2);
    p = p->next;
    p->next = new_element(9);
    p = p->next;
    p->next = new_element(-5);
    p = p->next;
    p->next = new_element(10);
    p = p->next;
    p->next = new_element(37);

    return head;

}


void visitList(list_t *head) {

    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", head->value);
    visitList(head->next);

}

list_t *recursiveSplit1(list_t *head, int threshold, list_t *head1, list_t *head2) {

    if (head == NULL) {
        return NULL;
    }

    if (head->value < threshold) {
        return recursiveSplit1(head->next, threshold, head1, head2);
    }

    head1 = new_element(head->value);
    head1->next = recursiveSplit1(head->next, threshold, head1->next, head2);
    return head1;

}


list_t *recursiveSplit2(list_t *head, int threshold, list_t *head1, list_t *head2) {

    if (head == NULL) {
        return NULL;
    }

    if (head->value >= threshold) {
        return recursiveSplit2(head->next, threshold, head1, head2);
    }


    head2 = new_element(head->value);
    head2->next = recursiveSplit2(head->next, threshold, head1, head2->next);
    return head2;

}

void freeList(list_t *head) {

    if (head == NULL) {
        return;
    }

    list_t *temp;
    temp = head->next;
    free(head);
    head = temp;
    freeList(head);

}



void split(list_t **head, int threshold, list_t **head1, list_t **head2) {

    *head1 = recursiveSplit1(*head, threshold, *head1, *head2);
    *head2 = recursiveSplit2(*head, threshold, *head1, *head2);
    freeList(*head);

}
