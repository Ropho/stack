#include "functions.h"

extern size_t exit_cond;

void dump (my_stack *head) {
    
    assert (head != nullptr);

    FILE *out = fopen ("DUMP", "a");
    
    if (head->error == MEMMORY_ALLOCATION_ERROR) {

        fprintf (out, "ARA ARA, memmory trouble (ERROR : %d)\n", head->error);
        fclose (out);
        return;
    }

    else if (head->error == STACK_UNDERFLOW) {
        fprintf (out, "ARA ARA, STACK UNDERFLOW (ERROR : %d) ", head->error);
        fclose (out);
        return;
    }

    else if (head->error == STACK_OVERFLOW) {
        fprintf (out, "ARA ARA, STACK OVERFLOW (ERROR : %d) ", head->error);
        fclose (out);
        return;
    }

    if (head->size_stack == 0)
        fprintf (out, "Stack created\n");

    else {

    for (int i = 0; i < head->size_stack; ++i)
        fprintf (out, "%d ", *(head->arr + i));
    fprintf (out, "\n");
    }
    
    fclose (out);
}

void verificator (my_stack *head) {

    assert (head != nullptr);
    
    if (head->arr == nullptr) {

        head->error = MEMMORY_ALLOCATION_ERROR;
        exit_cond = 1;
        return;
    }
    else if (head->size_stack < 0) {

        head->error = STACK_UNDERFLOW;
        exit_cond = 1;
        return;
    }

    else if (head->size_stack > head->size_array) {

        head->error = STACK_OVERFLOW;
        exit_cond = 1;
        return;
    }

}



my_stack *spawn_stack (size_t size_array) {

    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack));

    constructor (head, size_array);

    return head;
}


void constructor (my_stack *head, size_t size_array) {

    assert (head != nullptr);

    head->size_stack = 0;
    head->size_array = size_array;
    head->error = 0;
    head->arr = (int*)calloc(head->size_array, sizeof (int));
    
    verificator (head);

    dump (head);
}


void delete_stack (my_stack **head) {

    assert (*head != nullptr);

    destructor (*head);

    free(*head);
    *head = nullptr;

}

void destructor (my_stack *head) {

    assert (head != nullptr);

    free((head)->arr);

    (head)->arr = nullptr;
    (head)->size_stack = 0;
    (head)->size_array = 0;

}

void push (my_stack *head, int value) {

    assert (head != nullptr);
    
    head->size_stack += 1;

    verificator (head);
/*
    if (head->size_stack > head->size_array) {

        head->error = STACK_OVERFLOW;

        if (head->size_array != 0)
             head->size_array = head->size_array * MULTIPLIER;
        else head->size_array ++;

        head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    } */
    if (exit_cond != 1)
        *(head->arr + head->size_stack - 1) = value;

    dump (head);


}

int pop (my_stack *head) {

    assert (head != nullptr);

    --(head->size_stack);

    verificator (head);

    if (exit_cond != 1) {

    int tmp = *(head->arr + head->size_stack);
    *(head->arr + head->size_stack) = 0;
    dump (head);
    
    return tmp;
    }
/*
    if (head->size_stack < head->size_array / MULTIPLIER) {   

            head->size_array /= MULTIPLIER;
            head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }
  */  
    dump (head);
    
    return 0;
}