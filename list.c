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
bool ListInsert(node_t **head, int val, int position);
bool ListDelete(node_t **head, int position);
bool ListDeleteNode(node_t **node);
node_t * ListNodeGet(node_t *head, int position);
void ListTraverse(node_t *head);

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

bool ListInsert(node_t **head, int val, int position)
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
        /* A node is inserted using the pointer of the previous one. */
        /* Ex: Position 3 means select node in the position 2 */
        node_t *curr = ListNodeGet(*head, (position-1));

        if (curr != NULL)
        {
          /* Inserting node in the list at given position */
          tmp_node->next = curr->next;
          curr->next = tmp_node;
        }
        else
        {
          printf("\nPosition doesn't exists in the list\n");
          retval = false;
        }
      }
    }
    else
    {
      printf("Memory allocation is failed\n");
      retval = false;
    }

    return retval;
}

bool ListDelete(node_t **head, int position)
{
  bool retval = true;

  if (position == 1)
  {
    ListDeleteNode(head);
  }
  else if (position > 1)
  {
    node_t *curr = ListNodeGet(*head, (position-1));

    if ((curr != NULL) && (curr->next != NULL))
    {
      ListDeleteNode(&(curr->next));
    }
    else
    {
      printf("\nPosition doesn't exists in the list\n");
      retval = false;
    }
  }
  else
  {
      printf("\nPosition doesn't exists in the list\n");
      retval = false;
  }

  return retval;
}

bool ListDeleteNode(node_t **node)
{
  bool retval = false;

  if (*node != NULL)
  {
    node_t *nodeDelete = *node;  
    *node = nodeDelete->next;
    free(nodeDelete);
    retval = true;
  }

  return retval;
}

node_t * ListNodeGet(node_t *head, int position)
{
  node_t * retNode = NULL;

  if (position >= 1)
  {
    node_t * auxNode = head;
    int nodePosition = 1;

    while ((auxNode!=NULL) && (nodePosition < position))
    {
      ++nodePosition;
      auxNode = auxNode->next;
    }

    if (nodePosition == position)
    {
      retNode = auxNode;
    }
  }

  return retNode;
}

void ListTraverse(node_t *head)
{
	node_t *current = head;   /* current node set to head */
	int count=0;              /* to count total no of nodes */

	printf("\ntraversing the list\n");
	while(current != NULL)
  {
		printf("%d ", current->data);
		++count;
		current=current->next;	
	}
	
	printf("\ntotal no of nodes : %d\n", count);
}

void ListExample(void)
{
    int num_nodes, value, index, position;
    node_t* head = NULL;

    printf("Enter the no. of nodes to create list: ");
    scanf("%d", &num_nodes);

    for (index = 1; index <= num_nodes; index++) 
    {
        printf("Enter node data for position %d in the list:  ", index);
        scanf("%d", &value);
        ListInsert(&head, value, index);
    }
    ListTraverse(head);

    position = 0;
    while (position >= 0)
    {
      printf("\nInsert the element at any position in the list\n");
      printf("Enter the position (<0 exit): ");
      scanf("%d", &position);
      printf("Enter the element value: ");
      scanf("%d", &value);
      ListInsert(&head, value, position);
      ListTraverse(head);
    }

    position = 0;
    while (position >= 0)
    {
      printf("\nDelete the element at any position in the list\n");
      printf("Enter the position (<0 exit): ");
      scanf("%d", &position);
      ListDelete(&head, position);
      ListTraverse(head);
    }
}

int main()
{
    ListExample();

    return 0;
}
