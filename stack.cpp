#include "stdio.h"
#include "malloc.h"
#include "assert.h"


const size_t size = 2;
const size_t multyplier = 2;

enum ERRORS {

    MEMMORY_ALLOCATION_ERROR = 1,
    POP_EMPTY_STACK          = 666
};


typedef struct my_stack {

    size_t size_array;
    size_t size_stack;
    int *arr;

} my_stack;



my_stack *spawn_stack () {

    my_stack *head = (my_stack*)malloc(sizeof (my_stack));

    head->size_stack = 0;
    head->size_array = size;

    head->arr = (int*)malloc(sizeof (int) * head->size_array);

    return head;
}



void delete_stack (my_stack *head) {

    assert (head != nullptr);

    free(head->arr);

    head->arr = nullptr;
    head->size_stack = 0;
    head->size_array = 0;

}


void push (my_stack *head, int value) {

    assert (head != nullptr);

    head->size_stack += 1;

    if (head->size_stack > head->size_array) {

        head->size_array = head->size_array * multyplier;

        head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
    }

    *(head->arr + head->size_stack - 1) = value;


}

int pop (my_stack *head) {

    assert (head != nullptr);

    if (head->size_stack == 0)
        return POP_EMPTY_STACK;

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

    test = spawn_stack();

    push (test, 2);
    push (test, 3);
    push (test,4);
    //printf ("%d ", test->size_stack);
    //printf ("%d\n", test->size_array);

    //printf ("%d", *(test->arr + test->size_stack - 1));
  /*  printf ("%d", pop(test));
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

    delete_stack (test);

    return 0;
}
