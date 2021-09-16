#include "functions.h"
    
void dump (my_stack *head) {

    assert (head != nullptr);

    FILE *out = fopen ("DUMP", "a");

    if (out == nullptr) {
        assert (0);
    }
    
    if (head->error != NO_ERROR) 
        verificator (head, out);

    for (int i = 0; i < head->size_stack; ++i)
        fprintf (out, "%d ", *(head->arr + i));
    fprintf (out, "\n");

    
    fclose (out);

    return;
}

void verificator (my_stack *head, FILE *out) {

    assert (head != nullptr);
    assert (out  != nullptr);
    
    if (head->error == MEMMORY_ALLOCATION_ERROR) {

        fprintf (out, "ARA ARA, memmory trouble (ERROR : %d)\n", head->error);
        //EXIT = 1;
    }

    else if (head->error == POP_EMPTY_STACK) 
        fprintf (out, "ARA ARA, why u pop empty stack? (ERROR : %d) ", head->error);
    
    else if (head->error == STACK_OVERFLOW) 
        fprintf (out, "ARA ARA, size of stack was realloc'ed (ERROR : %d) ", head->error);
}

    my_stack *spawn_stack (size_t size_array) {

    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack));

    if (head == nullptr)
        assert (0);

    constructor (head, size_array);

    return head;
}


void constructor (my_stack *head, size_t size_array) {

    assert (head != nullptr);

    head->size_stack = 0;
    head->size_array = size_array;
    head->error = 0;
    head->arr = (int*)calloc(head->size_array, sizeof (int));

    if (head->arr == nullptr)
        head->error = MEMMORY_ALLOCATION_ERROR;

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
    
    if (head->error != NO_ERROR)
        head->error = NO_ERROR;

    head->size_stack += 1;

    if (head->size_stack > head->size_array) {

        head->error = STACK_OVERFLOW;

        if (head->size_array != 0)
             head->size_array = head->size_array * MULTIPLIER;
        else head->size_array ++;

        head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }

    *(head->arr + head->size_stack - 1) = value;

    dump (head);


}

int pop (my_stack *head) {

    assert (head != nullptr);

    if (head->error != NO_ERROR)
        head->error = NO_ERROR;
    
    if (head->size_stack == 0)  {

        head->error = POP_EMPTY_STACK;

        dump (head);

        return 0;
    }

    int tmp = *(head->arr + head->size_stack - 1);
    *(head->arr + head->size_stack - 1) = 0;
    --head->size_stack;

    if (head->size_stack < head->size_array / MULTIPLIER) {   

            head->size_array /= MULTIPLIER;
            head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }
    
    dump (head);
    
    return tmp;
}