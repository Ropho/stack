#include "functions.h"

extern size_t EXIT_COND;

long long hash_calc (my_stack *head) {

    assert (head != nullptr);
    
    long long hash = 0;

    verificator (head);

    hash += head->left_canary;
    hash += head->error;
    hash += head->size_array;
    hash += head->size_stack;
    
    if (head->size_stack > 0 && head->arr != nullptr)
        for (int i = 0; i < head->size_stack; ++i)
            hash += *(head->arr + i);
    
    for (int i = 0; i < strlen (head->stack_name); ++i)
        hash += head->stack_name[i];
    for (int i = 0; i < strlen (head->func_name); ++i)
        hash += head->func_name[i];
    for (int i = 0; i < strlen (head->file_name); ++i)
        hash += head->file_name[i]; 
    
    hash += head->line;
    hash += head->right_canary;

    return hash;    
}


#ifndef NDEBUG_MODE

static void dump (my_stack *head) {             

    assert (head != nullptr);

    FILE *out = fopen ("DUMP", "a");
    assert (out != nullptr);

    fprintf (out, "STACK <%s> [%x] at (%s) at (%s) (%d): ", head->stack_name, head, head->func_name, head->file_name, head->line);

    if (head->error == MEMMORY_ALLOCATION_ERROR) {

        fprintf (out, "ARA ARA, memmory trouble (ERROR : %d)\n", head->error);
        fclose (out);
        return;
    }

    else if (head->error == STACK_UNDERFLOW) {

        fprintf (out, "ARA ARA, STACK UNDERFLOW (ERROR : %d)\n", head->error);
        fclose (out);
        return;
    }

    else if (head->error == STACK_OVERFLOW) {

        fprintf (out, "ARA ARA, STACK OVERFLOW (ERROR : %d) STACK WAS REALLOC''ED ", head->error);
    }

    else if (head->error == NAS_VZLOMALI) {
        fprintf (out, "RIP canary dead (ERROR : %d) ", head->error);
    }


    if (head->size_stack == 0 && head->size_array == SIZE_CONSTRUCTOR) {
        if (head->size_array > 0 && *(head->arr) != MUSOR)
            fprintf (out, "Stack created\n\n");
        else 
            fprintf (out, "EMPTY STACK\n\n");
    }
    else if (head->arr == nullptr && head->size_stack == 0 && head->size_array == 0) {
        
        fprintf (out, "Stack DEcreated\n\n");
    }
    else {

        fprintf (out,"\n{\n");

#if defined D_2 || defined D_3
        if (head->left_canary == alive)
            fprintf (out, "left canary alive :)\n\n");
        else
            fprintf (out, "left canary dead :(\n\n");

        fprintf (out,"size = %d\ncapacity = %d\n", head->size_stack, head->size_array);

        if (head->arr != nullptr && (*((long long*)(head->arr - sizeof (long long))) == alive))
            fprintf (out, "left canary in stack alive :)\n");
        else
            fprintf (out, "left canary in stack dead :(\n");

    for (int i = 0; i < head->size_stack; ++i)
        fprintf (out, "\t[%d] = %d\n", i, *(head->arr + i));

     if (*((long long*)(head->arr + head->size_array)) == alive)
        fprintf (out, "right canary in stack alive :)\n");
    else
        fprintf (out, "right canary in stack dead :(\n");

    if (head->right_canary == alive)
        fprintf (out, "\nright canary alive :)\n");
    else
        fprintf (out, "\nright canary dead :(\n");
    fprintf (out, "}\n\n");

#else
        fprintf (out,"size = %d\ncapacity = %d\n", head->size_stack, head->size_array);
        for (int i = 0; i < head->size_stack; ++i)
        fprintf (out, "\t[%d] = %d\n", i, *(head->arr + i));
#endif
    }
    
    fclose (out);
    return;
}

#else 
    
static void dump (my_stack *head) {

    FILE *out = fopen ("DUMP", "a");
    fprintf (out,"size = %d\ncapacity = %d\n", head->size_stack, head->size_array);
    for (int i = 0; i < head->size_stack; ++i)
        fprintf (out, "\t[%d] = %d\n", i, *(head->arr + i));
    fprintf (out, "\n");
    fclose (out);
    return;
}

#endif


#ifndef NDEBUG_MODE

static void verificator (my_stack *head) {

    assert (head != nullptr);

    if (head->arr == nullptr && head->size_array != 0) {

        head->error = MEMMORY_ALLOCATION_ERROR;
        EXIT_COND = 1;
        return;
    }

    else if (head->size_stack < 0) {

        head->error = STACK_UNDERFLOW;
        EXIT_COND = 1;
        return;
    }

    else if (head->size_stack > head->size_array) {

        head->error = STACK_OVERFLOW;
        EXIT_COND = 0;
        return;
    }
    
#if defined D_2 || defined D_3

    else if (head->left_canary != alive || head->right_canary != alive) {

        head->error = NAS_VZLOMALI;
        EXIT_COND = 1;
        return;
    }
    
    else if (head->arr != nullptr)
        if (*((long long*)(head->arr - sizeof (long long))) != alive || *((long long*)(head->arr + head->size_array)) != alive) {
        head->error = NAS_VZLOMALI;
        EXIT_COND = 1;
        return;
    }
#endif
}

void cur_inf (my_stack *head, const int line, const char *func, const char *file) {

    assert (head != nullptr);

    head->line = line;
    strcpy (head->func_name, "");
    strcpy (head->func_name, func);
    strcat (head->func_name, "\0");

    strcpy (head->file_name, "");
    strcpy (head->file_name, file);
    strcat (head->file_name, "\0");

    return;
}

#endif

void constructor (my_stack *head, size_t size_array) {

    assert (head != nullptr);

    head->size_stack   = 0;
    head->size_array   = size_array;
    
    #ifndef NDEBUG_MODE
    head->error        = NO_ERROR;
    #endif

    if (head->size_array > 0) {

        #if defined D_2 || defined D_3
        head->arr          = (int*)calloc(head->size_array + 4, sizeof (int)); //with 2 canaries
        *((long long*)head->arr) = alive; 
        head->arr = head->arr + sizeof (long long);
        *(long long*)(head->arr + head->size_array) = alive;

        #else
            head->arr          = (int*)calloc(head->size_array, sizeof (int));

        #endif
    }
    else 
        head->arr = nullptr;

    #if defined D_2 || defined D_3
    head->left_canary  = alive;
    head->right_canary = alive;
    #endif

    #ifdef D_3
    head->hash = 0;
    #endif

    #ifndef NDEBUG_MODE
    verificator (head);

    dump (head);
    #endif
}


void delete_stack (my_stack **head) {

    assert (*head != nullptr);
    
    destructor (*head);

    #ifndef NDEBUG_MODE
    dump (*head);
    #endif
    free(*head);
    *head = nullptr;

}

static void destructor (my_stack *head) {

    assert (head != nullptr);

    free((head)->arr);

    (head)->arr = nullptr;
    (head)->size_stack = 0;
    (head)->size_array = 0;

    #if defined D_2 || defined D_3
    head->left_canary = alive;
    head->right_canary = alive;
    #endif

    #ifdef D_3
    head->hash = 0;
    #endif

    #ifndef NDEBUG_MODE
    head->error = NO_ERROR;
    strcpy (head->file_name, "");
    strcpy (head->func_name, "");
    strcpy (head->stack_name, "");
    head->line = 0;
    #endif
}

void push (my_stack *head, int value) {

    assert (head != nullptr);
    
    head->size_stack += 1;

    #ifndef NDEBUG_MODE
    verificator (head);

    if (head->error == STACK_OVERFLOW) {

        if (head->size_array != 0)
             head->size_array = head->size_array * MULTIPLIER;
        else head->size_array ++;
        
        if (head->size_array > 0)
            head->arr = (int*) realloc (head->arr, sizeof (int) * head->size_array);
        assert (head->arr != nullptr);
    } 
    #else
        if (head->size_array > head->size_stack) {

        if (head->size_array != 0)
             head->size_array = head->size_array * MULTIPLIER;
        else head->size_array ++;
        
        if (head->size_array > 0)
            head->arr = (int*) realloc (head->arr, sizeof (int) * head->size_array);
        assert (head->arr != nullptr);
    } 
    #endif


    if (EXIT_COND != 1)
        *(head->arr + head->size_stack - 1) = value;

    dump (head);

#ifdef D_3
    head->hash = hash_calc (head);
#endif

#ifndef NDEBUG_MODE
    head->error = NO_ERROR;
#endif
}

int pop (my_stack *head) {

    assert (head != nullptr);
    
    #ifndef NDEBUG_MODE
    verificator (head);
    #endif

    --(head->size_stack);

        
    #ifndef NDEBUG_MODE
    verificator (head);
    #endif

    if (EXIT_COND != 1) {

        int tmp = *(head->arr + head->size_stack);
        *(head->arr + head->size_stack) = MUSOR;
    
        if (head->size_stack < head->size_array / DIVISOR) {   

            head->size_array /= DIVISOR;
            head->arr = (int*)realloc (head->arr, sizeof (int) * head->size_array);
        }
        dump (head);
#ifdef D_3
         head->hash = hash_calc (head);
#endif
        return tmp;
    }

    dump (head);
    
#ifdef D_3
    head->hash = hash_calc (head);
#endif
    return 666;
}