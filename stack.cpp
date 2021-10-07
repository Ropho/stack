#include "functions.h"


size_t EXIT_COND = 0;   //условие выхода из проги

#ifndef NDEBUG_MODE

    #define stk_name(name, a) {strcpy (a, #name); strcat (a, "\0");} 
    #define $ ,__LINE__,__PRETTY_FUNCTION__,__FILE__
    #define hash(name) if (name->hash != hash_calc(name)) EXIT_COND = 1;
    
#endif

#define p printf("popa\n");

int main (void) {
    
    FILE *out = fopen ("DUMP", "w");       //clearing the dump  file
    kotik(out)
    fclose (out);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// TYPE HERE /////////////////////////////////////////////////////
#ifdef D_3

    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack)); //create stack -_-

    cur_inf (head $); stk_name(head, head->stack_name) constructor (head, SIZE_CONSTRUCTOR); EX_VER
    

//return 0;
//printf ("%x\n",hash_calc(head));
cur_inf (head $); push (head, 4);  hash(head) EX_VER           //сделать ХЭШ
//printf ("%x\n",hash_calc(head));
//return 0;

cur_inf (head $); push (head, 4); hash(head) EX_VER       //крашит хэш       ХЭШ
//printf ("%x\n",hash_calc(head));
//printf ("kek");
cur_inf (head $); push (head, 9); hash(head) EX_VER       //крашит хэш на реалоке 
//printf ("%x\n",hash_calc(head));
//return 0;
//*(head->arr - sizeof (long long)) = 12;
//printf ("%x\n",hash_calc(head));
//return 0;
cur_inf (head $); push (head, 9); hash(head) EX_VER
//printf ("%x\n",hash_calc(head));
cur_inf (head $); push (head, 9); hash(head) EX_VER


cur_inf (head $);    pop (head); hash(head) EX_VER
cur_inf (head $);    pop (head); hash(head) EX_VER
cur_inf (head $);    pop (head); hash(head) EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER

cur_inf (head $); delete_stack (&head);

//printf ("mem");
return 0;




cur_inf (head $); pop (head); EX_VER
cur_inf (head $); pop (head); EX_VER
// $    pop (head); EX_VER
// $    pop (head); EX_VER
cur_inf (head $);    delete_stack (&head);

    printf ("OK");

    return 0;
#endif

#if defined D_2 || defined D_1

my_stack *head = (my_stack*)calloc(1, sizeof (my_stack)); //create stack -_-

    cur_inf (head $); stk_name(head, head->stack_name) constructor (head, SIZE_CONSTRUCTOR); EX_VER
    

cur_inf (head $); push (head, 4); EX_VER


cur_inf (head $); push (head, 4);  EX_VER      

cur_inf (head $); push (head, 9);  EX_VER  

cur_inf (head $); push (head, 9); EX_VER

cur_inf (head $); push (head, 9); EX_VER

cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER
cur_inf (head $);    pop (head); EX_VER

cur_inf (head $);    delete_stack (&head);
return 0;

#endif

#ifdef NDEBUG
    my_stack *head = (my_stack*)calloc(1, sizeof (my_stack));
    constructor (head, SIZE_CONSTRUCTOR); 
    push (head, 5);
    push (head, 5);
    push (head, 5);
    push (head, 5);
    printf ("%d\n", pop (head));
    pop (head);
    pop (head);
    pop (head);
    //pop (head);
    delete_stack (&head);
    printf ("haha");
    return 0;
#endif    
}
