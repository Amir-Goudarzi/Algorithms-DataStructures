#include <stdio.h>
#include <malloc.h>


typedef struct list_s {
    int value;
    struct list_s *next;
} list_t;


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



void split(list_t **head, int threshold, list_t **head1, list_t **head2) {

    list_t *Head = *head, *Head1, *Head2, *temp;
    int flag1 = 1, flag2 = 1, Flag1 = 1, Flag2 = 1;

    while (Head != NULL) {

        if (Head->value >= threshold) {

            if (flag1) {
                Head1 = new_element(Head->value);
                flag1 = 0;
            } else {
                Head1->next = new_element(Head->value);
                Head1 = Head1->next;
            }

        } else {

            if (flag2) {
                Head2 = new_element(Head->value);
                flag2 = 0;
            } else {
                Head2->next = new_element(Head->value);
                Head2 = Head2->next;
            }

        }

        if (!flag1 && Flag1) {
            *head1 = Head1;
            Flag1 = 0;
        }

        if (!flag2 && Flag2) {
            *head2 = Head2;
            Flag2 = 0;
        }

        temp = Head->next;
        free(Head);
        Head = temp;

    }

}



int main() {

    list_t *head = createTestList();


    visitList(head);
    list_t *head1, *head2;
    split(&head, 18, &head1, &head2);
    visitList(head1);
    visitList(head2);


    return 0;
}