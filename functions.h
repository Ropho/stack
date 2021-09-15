#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "stdio.h"
#include "malloc.h"
#include "assert.h"

const size_t SIZE_CONSTRUCTOR = 1;
const size_t MULTIPLIER = 2;
size_t EXIT       = 0;


enum ERRORS {

    NO_ERROR = 0,
    MEMMORY_ALLOCATION_ERROR = 1,
    STACK_OVERFLOW = 2,
    POP_EMPTY_STACK          = 666
};


typedef struct my_stack {

    int    error;
    size_t size_array;
    size_t size_stack;
    int    *arr;

} my_stack;



my_stack *spawn_stack (size_t size_array);

void constructor (my_stack *head, size_t size_array);

void delete_stack (my_stack **head);

void destructor (my_stack *head);

void push (my_stack *head, int value);

int pop (my_stack *head);

void verificator (my_stack *head, FILE *out);

void dump (my_stack *head);

#endif // FUNCTIONS_H_INCLUDED
