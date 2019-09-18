#include <iostream>
using namespace std;

#define QUEUE_MAX       (100U)

class Queue
{
    private:
        int front,rear;
        int ele[QUEUE_MAX];
    public:
        Queue() /* To Initalize queue */
        {
            front =  0;
            rear  = -1;
        }
 
        bool isFull();
        bool isEmpty();
        bool insertQueue(int  item);
        bool deleteQueue(int *item);
};
 
/** To check queue is full or not */
bool Queue::isFull()
{
    bool retval = false;
 
    if( rear == (QUEUE_MAX-1))
    {
        retval = true;
    }
 
    return retval;
}
 
/** To check queue is empty or not */
bool Queue::isEmpty()
{
    bool retval = false;
 
    if(front == (rear + 1))
    {
        retval = true;
    }
 
    return retval;    
}
 
 
/** Insert Item into queue */
bool Queue:: insertQueue(int item)
{
    bool retval = false;

    if(!isFull())
    {
        ++rear;
        ele[rear]=item;
        retval = true;

        cout<<"\ninserted Value :" << item;
    }
    else
    {
        cout<<"\nQueue OverFlow" << endl;
    }
    
    return retval; 
}
 
/** delete item from queue */
bool Queue:: deleteQueue(int *item)
{
    bool retval = false;

    if(!isEmpty())
    {
        *item = ele[front];
        ++front;
        return true;

        cout<<"\nDeleted Value :" << *item;
    }
    else
    {
        cout<<"\nQueue Underflow" << endl;
    }
        
    return retval;
}