#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "id.h"

#define N 100000

typedef struct Element {
    User user;
    struct Element *next;
    struct Element *prev;
} Element;

typedef struct List {
    int length;
    Element *first;
    Element *last;
} List;

List *initList();
int length(List *l);
void printList(List *l);
void push(List *l, User user);
void unshift(List *l, User user);
void insert(List *l, User user, int index);
void pop(List *l);
void shift(List *l);
void del(List *l, int index);
void empty(List *l);
void delList(List *l);
Element *getEl(List *l, int index);
int findIndex(List *l, User *user);
void swap (User *a, User *b);
Element *partition(Element *l, Element *h);
void _quickSort(Element *l, Element *h);
void quickSort(List *l);

#endif
