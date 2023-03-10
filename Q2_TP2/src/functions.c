#include <stdio.h>
#include <stdlib.h>

#include "include/functions.h"

void alpha(char *str) {
    char *alpha = "alpha";
    unsigned int len;
    for (len = 0; alpha[len] != '\0'; len++);

    str = realloc(str, sizeof(char) * len + 1);

    unsigned int i = 0;
    for (i = 0;; i++) {
        str[i] = alpha[i];
        if (str[i] == '\0') return;
    }
}

char *beta() {
    char *beta = "beta";
    return beta;
}

void dynamic_array() {
    int res;
    int size = 0;
    int *arr = malloc(0);
    do {
        printf("Enter a number: ");
        scanf("%d", &res);
        getchar();
        arr = realloc(arr, sizeof(int) * size + 1);
        arr[size] = res;
        size++;
    } while (res >= 0); 

    if (size > 1) {
        printf("[");
        for (int i = 0; i < size - 1; i++) {
            printf("%d", arr[i]);
            if (i < size - 2) printf(", ");
        }
        printf("]\n");
    }
    free(arr);
}

void dynamic_linked_list() {
    typedef struct Node {
        unsigned int value;
        struct Node *next;
    } Node;
    
    typedef struct List {
        unsigned int size;
        Node *head;
    } List;

    List *l = malloc(sizeof(List));
    l->size = 0;
    l->head = NULL;
    int res;
    do {
        printf("Enter a number: ");
        scanf("%d", &res);
        getchar();
        if (res >= 0) {
            Node *n = malloc(sizeof(Node));
            n->value = res;
            n->next = NULL;
            if (l->size == 0) {
                l->head = n;
            } else {
                Node *tmp = l->head;
                while(tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = n;
            }
            l->size++;
        }
    } while (res >= 0);
    if (l->size > 0) {
        printf("[");
        Node *tmp = l->head;
        while(tmp != NULL) {
            printf("%d", tmp->value);
            tmp = tmp->next;
            if (tmp != NULL) printf(", ");
        }
        printf("]\n");
    }
    while (l->size > 0) {
        Node *tmp = l->head;
        l->head = tmp->next;
        l->size--;
        free(tmp);
    }
    free(l);
}
