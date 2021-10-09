#include "functions.h"


size_t EXIT_COND = 0;   //условие выхода из проги

#ifndef NDEBUG

    #define stk_name(name, a) {strcpy (a, #name); strcat (a, "\0");} 
    #define $ ,__LINE__,__PRETTY_FUNCTION__,__FILE__
    #define hash(name) if (name->hash != hash_calc(name)) EXIT_COND = 1;
    

    #define create(name) {name = (my_stack*)calloc(1, sizeof (my_stack)); \
       cur_inf (name $); stk_name(name, name->stack_name) constructor (name, SIZE_CONSTRUCTOR); EX_VER}

#ifdef D_3
    #define pushka(name, value) {cur_inf (name $); push (name, value);  hash(name) EX_VER}  
    #define popka(name)  {cur_inf (name $);    pop (name); hash(name) EX_VER}
    #define check(name) {hash(name) EX_VER}
#endif

#if defined D_2 || defined D_1 
    #define pushka(name, value) {cur_inf (name $); push (name, value); EX_VER}  
    #define popka(name)  {cur_inf (name $);    pop (name); EX_VER}
#endif

    #define dead(name) {cur_inf (name $); delete_stack (&name);}

#endif

#ifdef NDEBUG
    #define create(name) {name = (my_stack*)calloc(1, sizeof (my_stack)); constructor (name, SIZE_CONSTRUCTOR);}
    #define pushka(name, value) {push (name, value);}  
    #define popka(name)  {pop (name);}
    #define dead(name) {delete_stack (&name);}
#endif

int main (void) {
    
    FILE *out = fopen ("DUMP", "w");       //clearing the dump  file
    kotik(out)
    fclose (out);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// TYPE HERE //////////////////////////////////////////////////////
// USE 4 FUNCTIONS
// create (name) - create stack with given name
// pushka (name) - push stack
// popkaa (name) - pop  stack
// dead (name)   - kill stack
// if u want to use ur own function: after every function use check (name of stack) 
//e.g printf ("1000 - 7"); check(head)

#ifdef D_3          //mode with HASH

    my_stack *head = nullptr;

    create (head)

    pushka (head, MUSOR)
        pushka (head, MUSOR)
           popka (head)
             popka (head)
             
            pushka (head, 4)
                pushka (head, 4)
                    pushka (head, 4)


    printf ("i hate this world"); check (head)    

    //popka (head)
        //head->arr = nullptr;
         // popka (head)
           pushka (head, 4) 
    dead (head)

        //create (head
    return 0;
#endif
///////////////////////////////////////////////TYPE ONLY IN D_3 mode///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined D_2 || defined D_1      //mode with canaries and verificator

    my_stack *head = nullptr;

    create (head)

    pushka (head, 4)

    popka (head)

    dead (head)

    return 0;
#endif

#ifdef NDEBUG       //mode without anything (easy death)

    my_stack *head = nullptr;

    create (head)

    pushka (head, 4)
    
    popka (head)

    popka (head)

    popka (head)

    pushka (head,1)

    dead (head)

    return 0;
#endif    
}
