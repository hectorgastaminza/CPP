#include <stdlib.h> 
#include <stdbool.h>
  
#define STACK_MAX       (100U)

/** A simple stack struck with basic stack funtionalities */
typedef struct stack_t
{
    /* data */
    int arr[STACK_MAX]; 
    int top;   
}stack_t;

/** Initializes stack. It must be done before to use it */
void StackInit(stack_t * stack)
{
    stack->top = -1;
}
  
/** Check if the stack is empty */
bool StackIsEmpty(stack_t * stack) 
{ 
    if(stack->top == -1)
        return true;
    return false;
}
  
/** Check if the stack is full */
bool StackIsFull(stack_t * stack)
{ 
    if(stack->top == STACK_MAX - 1)
        return true;
    return false;
}
  
/** Remove an element from stack */
bool StackPop(stack_t * stack, int * value)
{ 
    bool retval = false;

    if(!isEmpty())
    { 
        *value = stack->arr[stack->top]; 
        stack->top--;
        retval = true;
    }

    return retval; 
} 
  
/** Insert an element to stack */
bool StackPush(stack_t * stack, int value)
{ 
    bool retval = false;

    if(!isFull())
    { 
        stack->top++;
        stack->arr[stack->top] = value;
        retval = true;
    }

    return retval;
}