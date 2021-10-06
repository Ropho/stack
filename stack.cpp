#include "functions.h"


size_t EXIT_COND = 0;   //условие выхода из проги

#ifndef NDEBUG_MODE

#define get_stack_name(name, a) {strcpy (a, #name); strcat (a, "\0");} 
#define $ ,__LINE__,__PRETTY_FUNCTION__,__FILE__
#define hash(name) if (name->hash != hash_calc(head)) EXIT_COND = 1;
#endif


int main (void) {

    FILE *out = fopen ("DUMP", "w");       //clearing the dump  file
    kotik(out)
    fclose (out);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// TYPE HERE /////////////////////////////////////////////////////
#ifndef NDEBUG_MODE
    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack));   //create stack -_-
    cur_inf (head $); get_stack_name(head, head->stack_name)  
        constructor (head, SIZE_CONSTRUCTOR); 
    EX_VER

cur_inf (head $); push (head, 4); hash(head) EX_VER
cur_inf (head $); push (head, 4); hash(head) EX_VER
cur_inf (head $); push (head, 9); hash(head) EX_VER
//return 0;
*(head->arr - sizeof (long long)) = 12;
hash_calc (head); cur_inf (head $); push (head, 9); EX_VER
printf ("mem");
return 0;
        my_stack *wait = (my_stack*)calloc(1, sizeof (my_stack));
       cur_inf (wait $);
       get_stack_name (wait, wait->stack_name)  
        constructor (wait, SIZE_CONSTRUCTOR); 
       EX_VER

cur_inf (wait $); pop (wait); EX_VER



cur_inf (head $); pop (head); EX_VER
cur_inf (head $); pop (head); EX_VER
// $    pop (head); EX_VER
// $    pop (head); EX_VER
cur_inf (head $);    delete_stack (&head);

    printf ("OK");

    return 0;

#else
    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack));
    constructor (head, SIZE_CONSTRUCTOR); 
    push (head, 5);
    push (head, 5);
    push (head, 5);
    push (head, 5);
    pop (head);
    pop (head);
    pop (head);
    pop (head);
    pop (head);
    delete_stack (&head);
    printf ("haha");
    return 0;
#endif    
}
