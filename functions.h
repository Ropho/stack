#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "TXLib.h"

const size_t size = 2;
const size_t multyplier = 2;

enum ERRORS {

    MEMMORY_ALLOCATION_ERROR = 1,
    POP_EMPTY_STACK          = 666
};


typedef struct my_stack {

    size_t error;
    size_t size_array;
    size_t size_stack;
    int *arr;

} my_stack;



my_stack *spawn_stack ();

void constructor (my_stack *head);

void delete_stack (my_stack **head);

void destructor (my_stack *head);

void push (my_stack *head, int value);

int pop (my_stack *head);




#endif // FUNCTIONS_H_INCLUDED
