//연결리스트
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST 10

typedef struct {
    int array[MAX_LIST];
    int size;
} ArrayList;


void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayList* L) {
    L->size = 0;
}

int is_empty(ArrayList* L) {
    return L->size == 0;
}

int is_full(ArrayList* L) {
    return L->size == MAX_LIST;
}
int get_entry(ArrayList* L, int pos) {
    if (pos < 0 || pos >= L->size)
        error("Location error");
    return L->array[pos];
}

void print_list(ArrayList* L) {
    for (int i = 0; i < L->size; i++) {
        printf("%d->", L->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayList* L, int item) {
    if (L->size >= MAX_LIST) {
        error("List overflow");
    }
    L->array[L->size++] = item;
}

void insert(ArrayList* L, int pos, int item) {
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = (L->size - 1); i >= pos; i--) {
            L->array[i + 1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

int delete(ArrayList* L, int pos) {
    int item;
    if (pos < 0 || pos >= L->size)
        error("Location error");
    item = L->array[pos];
    for (int i = pos; i < (L->size - 1); i++) {
        L->array[i] = L->array[i + 1];
    }
    L->size--;
    return item;
}
int main(void) {
    ArrayList list;

    init(&list);
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 1, 20); print_list(&list);
    insert(&list, 2, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete(&list, 0); print_list(&list);
    return 0;
}












