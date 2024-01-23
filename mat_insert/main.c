#include <stdio.h>
#include <malloc.h>


typedef struct columns_s {
    int c;
    double val;
    struct columns_s *next_column;
} columns_t;


typedef struct rows_s {
    int r;
    columns_t *next_column;
    struct rows_s *next_row;
} rows_t;


typedef struct matr_s {
    int r;
    int c;
    rows_t *next_row;
} matr_t;



columns_t *new_column(int c, double val) {
    columns_t *new;
    new = malloc(sizeof(columns_t));
    new->c = c;
    new->val = val;
    new->next_column = NULL;
    return new;
}


rows_t *new_row(int r) {
    rows_t *new;
    new = malloc(sizeof(rows_t));
    new->r = r;
    new->next_column = NULL;
    new->next_row = NULL;
    return new;
}


matr_t *new_matrix(int r, int c) {
    matr_t *new;
    new = malloc(sizeof(matr_t));
    new->r = r;
    new->c = c;
    new->next_row = NULL;
    return new;
}


matr_t *createTestMatrix() {

    matr_t *m = new_matrix(4, 5);
    rows_t *row_zero = new_row(0);
    rows_t *row_two = new_row(2);
    rows_t *row_three = new_row(3);
    columns_t *column_two = new_column(2, 12.75);
    columns_t *column_zero = new_column(0, -2.5);
    columns_t *column_one = new_column(1, 3.15);
    columns_t *column_four = new_column(4, 2.75);

    m->next_row = row_zero;
    row_zero->next_row = row_two;
    row_two->next_row = row_three;
    row_zero->next_column = column_two;
    row_two->next_column = column_zero;
    column_zero->next_column = column_one;
    row_three->next_column = column_four;

    return m;
}

void recursive_visit(rows_t *row) {

    if (row == NULL) {
        return;
    }

    columns_t *p = row->next_column;
    while (p != NULL) {
        printf("row: %d column: %d value: %.2f\n", row->r, p->c, p->val);
        p = p->next_column;
    }

    recursive_visit(row->next_row);

}


void visit_m(matr_t *m) {
    recursive_visit(m->next_row);
}


void recursive_insert(rows_t *row, int c, float value) {

    columns_t *p = row->next_column;
    columns_t *q;

    if (p == NULL) {

        columns_t *new = new_column(c, value);
        row->next_column = new;
        return;

    }

    while (p != NULL) {

        if (c < p->c) {

            columns_t *new = new_column(c, value);
            new->next_column = p;
            row->next_column = new;
            return;

        }

        if (c == p->c) {

            p->val = value;
            return;

        }

        if (c > p->c) {

            q = p->next_column;

            if (q != NULL) {

                if (c < q->c) {

                    columns_t *new = new_column(c, value);
                    new->next_column = q;
                    p->next_column = new;
                    return;

                }

            } else {

                columns_t *new = new_column(c, value);
                p->next_column = new;
                return;

            }

        }

        p = p->next_column;

    }

}

void mat_insert(matr_t *m, int r, int c, float value) {

    rows_t *p = m->next_row;
    rows_t *q;

    if (p == NULL) {

        rows_t *new = new_row(r);
        m->next_row = new;
        recursive_insert(new, c, value);
        return;

    }


    while (p != NULL) {

        if (r < p->r) {

            rows_t *new = new_row(r);
            new->next_row = p;
            m->next_row = new;
            recursive_insert(new, c, value);
            return;

        }

        if (r == p->r) {
            recursive_insert(p, c, value);
            return;
        }

        if (r > p->r) {

            q = p->next_row;
            if (q != NULL) {

                if (r < q->r) {

                    rows_t *new = new_row(r);
                    new->next_row = q;
                    p->next_row = new;
                    recursive_insert(new, c, value);
                    return;

                }

            } else {

                rows_t *new = new_row(r);
                p->next_row = new;
                recursive_insert(new, c, value);
                return;

            }

        }
        p = p->next_row;
    }

}

int main() {

    matr_t *m;
    m = createTestMatrix();

    visit_m(m);
    mat_insert(m, 1, 1, 4);
    printf("\n\nAdded value '4.00' to row 1 column 1:\n\n");
    visit_m(m);
    mat_insert(m, 0, 0, 7);
    printf("\n\nAdded value '7.25' to row 0 column 0:\n\n");
    visit_m(m);
    mat_insert(m, 4, 1, 5.75);
    printf("\n\nAdded value '5.75' to row 4 column 1:\n\n");
    visit_m(m);


    return 0;
}