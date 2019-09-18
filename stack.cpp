#include<stdlib.h> 
  
using namespace std; 
  
/* A simple stack class with basic stack funtionalities */
class Stack 
{ 
private: 
    static const int max = 100; 
    int arr[max]; 
    int top; 
public: 
    Stack() { top = -1; } 
    bool isEmpty(); 
    bool isFull(); 
    bool pop(int * value); 
    bool push(int value); 
}; 
  
/* Stack's member method to check if the stack is iempty */
bool Stack::isEmpty() 
{ 
    if(top == -1) 
        return true; 
    return false; 
} 
  
/* Stack's member method to check if the stack is full */
bool Stack::isFull() 
{ 
    if(top == max - 1) 
        return true; 
    return false; 
} 
  
/* Stack's member method to remove an element from it */
bool Stack::pop(int * value) 
{ 
    bool retval = false;

    if(!isEmpty()) 
    { 
        *value = arr[top]; 
        top--; 
        return true;
    }

    return retval; 
} 
  
/* Stack's member method to insert an element to it */
bool Stack::push(int value) 
{ 
    bool retval = false;

    if(!isFull()) 
    { 
        top++; 
        arr[top] = value; 
        return true;
    }

    return retval;
} 