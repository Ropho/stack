#include "stdio.h"
#include "malloc.h"
#include "assert.h"

typedef struct my_stack {

    int inf = NULL;
    struct my_stack *pointer = nullptr;
} my_stack;


void push (my_stack **stack1, int value) {

    my_stack *new_stack = (my_stack*)malloc(sizeof(my_stack));

    if (*stack1 == nullptr) {

        *stack1 = new_stack;
        (*stack1)->inf = value;
        (*stack1)->pointer = nullptr;

        return;
    }

    else {

        new_stack->pointer = *stack1;
        (*stack1) = new_stack;
        (*stack1)->inf = value;

        return;
    }
}

int pop (my_stack **stack1) {

    assert (*stack1 != nullptr);

    int value = (*stack1)->inf;
    my_stack *tmp = *stack1;
    *stack1 = (*stack1)->pointer;
    free (tmp);

    return value;
}




int main (void) {

    my_stack *kek = nullptr;

    push (&kek, 2);
    push (&kek, 3);


    my_stack *print = kek;
    while (print != nullptr) {

        printf ("%d ", print->inf);
        print = print->pointer;
    }

    printf ("\n%d ",pop (&kek));
    printf ("%d",pop (&kek));

}
