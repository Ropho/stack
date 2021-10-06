#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "string.h"

#define kotik(out) fprintf(out, "\
                  　　　　　／＞　 フ   \n\
　　                　　　 | 　_　 _|    \n\
　 　　                 　／`ミ _x 彡   \n\
                　　 　 /　　　 　 |    \n\
                　　　 /　 ヽ　　 ﾉ     \n\
                　／￣|　　 |　|　|     \n\
                　| (￣ヽ＿_ヽ_)_)      \n\
                　＼二つ                \n\n");


//#define NDEBUG_MODE
//#define D_1
//#define D_2                   //uslovnaya compilyatsya
#define D_3


#ifndef NDEBUG_MODE


#define EX_VER {if (EXIT_COND) {printf ("u've been crashed"); return 0;}}
 

#define alive 0x11EDEAD


#endif


const int SIZE_CONSTRUCTOR = 10;
const size_t MULTIPLIER = 2;
const size_t DIVISOR = 3;

#define MUSOR 666

enum ERRORS {

    NO_ERROR                 = 0,
    MEMMORY_ALLOCATION_ERROR = 1,
    STACK_OVERFLOW           = 2,
    STACK_UNDERFLOW          = 3,
    NAS_VZLOMALI             = 4
};


typedef struct my_stack {

    #if defined D_2 || defined D_3
    long long left_canary;
    #endif

    #if defined D_1 || defined D_2 || defined D_3
    int    error;
    #endif

    size_t size_array;
    int    size_stack;
    int   *arr;

    #if defined D_1 || defined D_2 || defined D_3
    char stack_name[10];
    char func_name[10];
    char file_name[20];
    int  line;
    #endif

    #if defined D_2 || defined D_3
    long long right_canary;
    #endif

    #ifdef D_3
    long long hash;
    #endif
} my_stack;



void cur_inf (my_stack *head, const int line, const char *func, const char *file);

void constructor (my_stack *head, size_t size_array);

void delete_stack (my_stack **head);

static void destructor (my_stack *head);

void push (my_stack *head, int value);

int pop (my_stack *head);

static void verificator (my_stack *head);

static void dump (my_stack *head);

long long hash_calc (my_stack *head);

#endif // FUNCTIONS_H_INCLUDED
