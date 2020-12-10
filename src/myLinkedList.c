#include "myLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

/*
Function Title: push
Summary: push value to linked list in sorted position if not duplicate
Inputs: int: next value to add
Outputs: none
Psuedocode:
Begin:
    set pos to head of list
    while not at end of list and not in correct position
       move position to next node
    if pos at end of list and input < last value in list
        add to end of list
        allocate space for new node
        set value in new node
    else if input > head of list
       add to start of list
       allocate space for new node
       set value in new node
       set new node next to head of list
       set head of list to new node
    else if input between current pos and next pos
        allocate space for new node
        set value in new node
        set new node next to next pos
        set pos next to new node
End
*/
void push(List *list, int input) {  // Begin:
    list->pos = list->head;         // set pos to head of list
    // while not at end of list and not in correct position
    while ((list->pos->next) && (input < list->pos->next->val)) {
        // move position to next node
        list->pos = list->pos->next;
    }

    // if pos at end of list and input < last value in list
    if (!(list->pos->next) && input < list->pos->val) {  // add to end of list
        list->pos->next = malloc(sizeof(Node));  // allocate space for new node
        list->pos->next->val = input;            // set value in new node

        // else if input > head of list
    } else if (input > list->head->val) {   // add to start of list
        list->prev = malloc(sizeof(Node));  // allocate space for new node
        list->prev->val = input;            // set value in new node
        list->prev->next = list->head;      // set new node next to head of list
        list->head = list->prev;            // set head of list to new node

        // else if input between current pos and next pos
    } else if (input < list->pos->val && input > list->pos->next->val) {
        list->prev = malloc(sizeof(Node));   // allocate space for new node
        list->prev->val = input;             // set value in new node
        list->prev->next = list->pos->next;  // set new node next to next pos
        list->pos->next = list->prev;        // set pos next to new node
    }
}  // End

/*
Function Title: pop
Summary: return next value in list and free last node
Inputs: none
Outputs: int: next value in list
Psuedocode:
Begin:
    free previous node
    set return node to prev
    set head to next
    return node value
End
*/
int pop(List *list) {               // Bgin:
    free(list->prev);               // free previous node
    list->prev = list->head;        // set return node to prev
    list->head = list->head->next;  // set head to next
    return list->prev->val;         // return node value
}  // End