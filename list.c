/**
 * Base on https://www.includehelp.com/data-structure-tutorial/single-linked-list-insertion.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node_t {
    int data;
    struct _node_t* next;
} node_t;

node_t * ListCreateNode(int val);
bool ListInsert(node_t** head, int val, int position);
void ListPrint(node_t* head);

node_t * ListCreateNode(int val)
{
  node_t * retval = (node_t*)malloc(sizeof(node_t));

  if (retval != NULL)
  {
    retval->data = val;
    retval->next = NULL;
  }

  return retval;
}

bool ListInsert(node_t** head, int val, int position)
{
    bool retval = true;
    node_t *tmp_node = ListCreateNode(val);

    if ((tmp_node != NULL) && (position >= 1))
    {
      if (*head == NULL) 
      {
          /* List is empty, assigning head pointer to tmp_node */
          *head = tmp_node;
      }
      else if (position == 1)
      {
        /* Inserting node at the beginning of the list */
        tmp_node->next = *head;
        *head = tmp_node;
      }
      else
      {
        node_t *curr = *head;
        int count = 1;
        
        --position; /* A node is inserted using the pointer of the previous one. */
                    /* Ex: Position 3 means select node in the position 2 */

        while ((curr != NULL) && (count < position))
        {
            curr = curr->next;
            ++count;
        }

        if (position > count) 
        {
          printf("\nPosition doesn't exists in the list ");
          retval = false;
        }
        else if ((count == position) && (curr->next == NULL))
        {
          /* Inseting node at the end of the list */
          curr->next = tmp_node;
        }
        else
        {
          /* Inserting node in the list at given position */
          tmp_node->next = curr->next;
          curr->next = tmp_node;
        }
      }
    }
    else
    {
      printf("Memory allocation is failed:");
      retval = false;
    }

    return retval;
}

void ListPrint(node_t* head)
{
    printf("\nList elements:\n");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void ListExample(void)
{
    int num_nodes, value, index, position;
    node_t* head = NULL;

    printf("Enter the no. of nodes to create list: ");
    scanf("%d", &num_nodes);

    for (index = 1; index <= num_nodes; index++) {
        printf("Enter node data for position %d in the list:  ", index);
        scanf("%d", &value);
        ListInsert(&head, value, index);
    }
    ListPrint(head);

    printf("\nInsert the element at 1st position:  ");
    scanf("%d", &value);
    ListInsert(&head, value, 1);
    // We have inserted one more element, hence num_nodes get increased by 1
    num_nodes += 1;
    ListPrint(head);

    printf("\nInsert the element at last position:  ");
    scanf("%d", &value);
    ListInsert(&head, value, num_nodes + 1);
    // We have inserted one more element, hence num_nodes will get increased by 1
    num_nodes += 1;
    ListPrint(head);

    printf("\nInsert the element at any position in the list\n");
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the element value: ");
    scanf("%d", &value);
    ListInsert(&head, value, position);
    // We have inserted one more element, hence num_nodes will get increased by 1
    num_nodes += 1;
    ListPrint(head);
}

int main()
{
    ListExample();

    return 0;
}