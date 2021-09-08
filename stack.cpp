#include "functions.h"

my_stack *spawn_stack (size_t size_array) {

    my_stack *head = (my_stack*)malloc(sizeof (my_stack));

    if (head == nullptr)
        return nullptr;

    constructor (head ,size_array);

    return head;
}


void constructor (my_stack *head, size_t size_array) {

    head->size_stack = 0;
    head->size_array = size_array;
    head->error = 0;
    head->arr = (int*)malloc(sizeof (int) * head->size_array);

    if (head->arr == nullptr)
        head->error = MEMMORY_ALLOCATION_ERROR;
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

    if (head->size_stack > head->size_array) {

        if (head->size_array != 0)
             head->size_array = head->size_array * multyplier;
        else head->size_array ++;

        head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }

    *(head->arr + head->size_stack - 1) = value;


}

int pop (my_stack *head) {

    assert (head != nullptr);

    if (head->size_stack == 0)  {

        head->error = POP_EMPTY_STACK;
        return 0;
    }

    int tmp = *(head->arr + head->size_stack - 1);
    *(head->arr + head->size_stack - 1) = 0;
    --head->size_stack;

    if (head->size_stack < head->size_array / multyplier) {     //уменьшение размера массива

            head->size_array /= multyplier;
            head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }


    return tmp;
}


int main (void) {

    my_stack *test;

    test = spawn_stack (size);

    push (test, 2);
    push (test, 3);
    push (test,4);
    //printf ("%d ", test->size_stack);
    //printf ("%d\n", test->size_array);

    //printf ("%d", *(test->arr + test->size_stack - 1));
  /* printf ("%d", pop(test));
    printf ("%d", pop(test));
    printf ("%d", pop(test));
    printf ("%d", pop(test));
    printf ("\n%d", test->size_array);
    push (test,2);
    printf ("\n%d", test->size_array);
    push(test,2);
    printf ("\n%d", test->size_array);
    push(test,2);
    printf ("\n%d", test->size_array);
    */

    delete_stack (&test);

    return 0;
}
