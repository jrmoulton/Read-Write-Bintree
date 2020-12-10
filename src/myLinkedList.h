
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *pos;
    Node *prev;
} List;

void push(List *, int);
int pop(List *);

#endif