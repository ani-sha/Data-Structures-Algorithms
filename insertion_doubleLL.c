#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void printList(struct Node *node);
void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
      if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;

      (*head_ref)= new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if (prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

void append(struct Node** head_ref, int new_data){

  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  struct Node *last = *head_ref;
     new_node->data  = new_data;
     new_node->next = NULL;

   if (*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return;
}

void printList(struct Node *node){
    struct Node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL){
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}


int main(){
  struct Node* head=NULL;

  int ch,val;
  printf("OPERATIONs\n");
  printf("1.Insert at beginning\n");
  printf("2.Insert in between\n");
  printf("3.Insert at the end\n");
  printf("4.Display linked list\n");
  printf("5.Exit\n");

  do{
    printf("Enter choice=");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: printf("Enter new data = ");
              scanf("%d",&val);
              insertAfter(head->next,val);
              break;
      case 3: printf("Enter new data = ");
              scanf("%d",&val);
              append(&head,val);
              break;
      case 4: printf("The linked List is: ");
              printList(head);
      case 5: exit(0);

    }
  }while(ch!=0);
return 0;
}
