#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/linked_list.h"

List *initList() {
    List *l = malloc(sizeof(*l));

    if (l == NULL) {
        exit(EXIT_FAILURE);
    }

    l->first = NULL;
    l->last = NULL;
    l->length = 0;

    return l;
}

int length(List *l) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    } else if (l->first == NULL || l->last == NULL) {
        return 0;
    } else {
        return l->length;
    }
}

void printList(List *l) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    if (l->first == NULL || l->last == NULL) {
        printf("[]\n");
    } else {
        Element *tmp = l->first;
        printf("[");
        while (tmp != NULL) {
            printf("%s %s - %d yo", tmp->user.firstName, tmp->user.lastName, tmp->user.age);
            if (tmp->next != NULL) {
                printf(", ");
            } else {
                printf("]\n");
            }
            tmp = tmp->next;
        }
    }
}

void push(List *l, User user) {
    Element *el = malloc(sizeof(*el));
    if (l == NULL || el == NULL) {
        exit(EXIT_FAILURE);
    }

    el->user = user;
    el->next = NULL;
    el->prev = l->last;
    if (l->first == NULL && l->last == NULL) {
        l->first = el;
        l->last = el;
    } else {
        l->last->next = el;
        l->last = el;
    }
    l->length++;
}

void unshift(List *l, User user) {
    Element *el = malloc(sizeof(*el));
    if (l == NULL || el == NULL) {
        exit(EXIT_FAILURE);
    }

    el->user = user;
    el->prev = NULL;
    el->next = l->first;
    if (l->first == NULL && l->last == NULL) {
        l->first = el;
        l->last = el;
    } else {
        l->first->prev = el;
        l->first = el;
    }
    l->length++;
}

void insert(List *l, User user, int index) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    if (index == 0) {
        unshift(l, user);
    } else if (index == l->length - 1) {
        push(l, user);
    } else {
        Element *newEl = malloc(sizeof(newEl));
        if (newEl == NULL) {
            exit(EXIT_FAILURE);
        }
        newEl->user = user;
        Element *el = getEl(l, index);
        newEl->prev = el->prev;
        el->prev->next = newEl;
        newEl->next = el;
        el->prev = newEl;
        l->length++;
    }

}

void pop(List *l) {
    if (l == NULL || (l->first == NULL && l->last == NULL)) {
        exit(EXIT_FAILURE);
    }

    Element *toDel = l->last;

    if (l->first->next == NULL || l->last->prev == NULL) {
        l->first = NULL;
        l->last = NULL;
    } else {
        toDel->prev->next = NULL;
        l->last = toDel->prev;
    }
    l->length--;

    free(toDel);
}

void shift(List *l) {
    if (l == NULL || (l->first == NULL && l->last == NULL)) {
        exit(EXIT_FAILURE);
    }

    Element *toDel = l->first;

    if (l->first->next == NULL || l->last->prev == NULL) {
        l->first = NULL;
        l->last = NULL;
    } else {
        toDel->next->prev = NULL;
        l->first = toDel->next;
    }
    l->length--;

    free(toDel);
}

void del(List *l, int index) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    if (index == 0) {
        shift(l);
    } else if (index == l->length - 1) {
        pop(l);
    } else {
        Element *toDel = getEl(l, index);
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
        l->length--;
        free(toDel);
    }
}

void empty(List *l) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    while (l->first != NULL && l->last != NULL) {
        pop(l);
    }
}
void delList(List *l) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    if (l->first != NULL || l->last != NULL) {
        empty(l);
    }
    free(l);
}

Element *getEl(List *l, int index) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    if (index > l->length - 1) {
        printf("Error: Index out of range\n");
        exit(EXIT_FAILURE);
    }
    int from_start = index <= (l->length-1 - index) ? 1 : 0;

    int i;
    Element *el;
    if (from_start) {
        el = l->first;
        for (i = 0; i < index; i++) {
            el = el->next;
        }
    } else {
        el = l->last;
        for (i = l->length - 1; i > index; i--) {
            el = el->prev;
        }
    }

    return el;
}

int findIndex(List *l, User *user) {
    if (l == NULL) {
        exit(EXIT_FAILURE);
    }
    int i;
    Element *el = l->first;
    for (i = 0; i < l->length; i++) {
        if (strcmp(user->firstName, el->user.firstName) == 0 && strcmp(user->lastName, el->user.lastName) == 0) {
            return i;
        }
        el = el->next;
    }
    return -1;
}

/* A utility function to swap two elements */
void swap (User *a, User *b) {
    User t = *a;
    *a = *b;
    *b = t;
}
 
/* Considers last element as pivot, places the
pivot element at its correct position in sorted array,
and places all smaller (smaller than pivot) to left
of pivot and all greater elements to right of pivot */
Element *partition(Element *l, Element *h)
{
    // set pivot as h element
    User *x = &h->user;
 
    // similar to i = l-1 for array implementation
    Element *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Element *j = l; j != h; j = j->next)
    {
        if (strcmp(j->user.lastName, x->lastName) <= 0)
        {
            // Similar to i++ for array
            i = (i == NULL) ? l : i->next;
 
            swap(&(i->user), &(j->user));
        }
    }
    i = (i == NULL) ? l : i->next; // Similar to i++
    swap(&(i->user), &(h->user));
    return i;
}
 
/* A recursive implementation of quicksort for linked list */
void _quickSort(Element *l, Element *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Element *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
// The main function to sort a linked list.
// It mainly calls _quickSort()
void quickSort(List *l)
{
    // Find last node
    Element *h = l->last;
    Element *head = l->first;
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}