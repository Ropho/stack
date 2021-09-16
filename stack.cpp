#include "functions.h"

int main (void) {

    FILE *out = fopen ("DUMP", "w");       //clearing the dump  file
     fclose (out);

    my_stack *test;

    test = spawn_stack (SIZE_CONSTRUCTOR);
    
    //if (EXIT)
      //  return 0;

    pop (test);

    push (test, 2);

    push (test, 3);

    push (test, 4);

   // printf ("%d ", test->size_stack);
   // printf ("%d\n", test->size_array);

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
    
    printf ("OK");

    return 0;
}
