/* https://www.includehelp.com/data-structure-tutorial/circular-queue-in-data-structure-using-c-and-cpp.aspx */
#include <stdlib.h> 
#include <stdbool.h>
  
#define QUEUE_MAX       (100U)
 
/** Declaration of Queue */
typedef struct _queue_t
{
    int front;
    int rear;
    int ele[QUEUE_MAX];
}queue_t;
 
/** Intialze Queue */
void QueueInit(queue_t *queue)
{
    queue->rear  = -1;
    queue->front =  0;
}
 
/** To check Queue is full or not */
bool QueueIsFull(queue_t *queue)
{
    bool retval = false;
 
    if(queue->rear == QUEUE_MAX -1)
    {
        retval = true;
    }
 
    return retval;
}
 
/** To check Queue is empty or not */
bool QueueIsEmpty(queue_t *queue)
{
    bool retval = false;
 
    if(queue->front == queue->rear+1)
    {
        retval = true;
    }
 
    return retval;
}
 
/** Insert item into queue */
bool QueueInsert(queue_t *queue, int item)
{
    bool retval = false;

    if(!QueueIsFull(queue))
    {
        queue->rear++;
        queue->ele[queue->rear] = item;
        retval = true;        
        printf("\nInserted item : %d", item);
    }
    else
    {
        printf("\nQueue Overflow");
    }
     
    return retval;
}
 
/** Delete item from queue */
bool QueueDelete(queue_t *queue, int *item)
{
    bool retval = false;

    if(!isEmpty(queue))
    {
        *item = queue->ele[queue->front];
        queue->front++;
        retval = true;
        printf("\nDeleted item : %d", *item);
    }
    else
    {
        printf("\nQueue Underflow");
    }
    
    return retval;
}