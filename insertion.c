#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int new_data);
void insertAfter(struct node* prev_node, int new_data);
void append(struct node** head_ref,int new_data);
void printList(struct node* n);

void push(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)= new_node;
}

void insertAfter(struct node* prev_node, int new_data){
  if(prev_node==NULL){
    printf("The previous node cannot be NULL\n");
    return;
  }
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=prev_node->next;
  prev_node->next=new_node;
}

void append(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  struct node* last = *head_ref;
  new_node->data=new_data;
  new_node->next=NULL;
  if(*head_ref==NULL){
    *head_ref=new_node;
    return;
  }
while (last->next!=NULL){
  last=last->next;
}
last->next=new_node;
return;
}

void printList(struct node* n){
  while(n!=NULL){
    printf("%d\n",n->data);
    n=n->next;
  }
}

int main(){
  struct node* head=NULL;

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
