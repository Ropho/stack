#include "functions.h"

size_t exit_cond = 0;   //условие выхода из проги

int main (void) {

    FILE *out = fopen ("DUMP", "w");       //clearing the dump  file
    fclose (out);

    my_stack *test;

    test = spawn_stack (SIZE_CONSTRUCTOR);

   push (test, 2);
    ex_ver
    
    push (test, 3);
    ex_ver

    push (test, 4);
    ex_ver
    
    pop (test);
    ex_ver
   // printf ("%d ", test->size_stack);
   // printf ("%d\n", test->size_array);
/*
    //printf ("%d", *(test->arr + test->size_stack - 1));
   printf ("%d", pop(test));
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

    printf ("OK");

    return 0;
}
