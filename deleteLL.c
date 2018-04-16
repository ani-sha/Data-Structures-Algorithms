#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int new_data);
void deleteList(struct node** head_ref);
void printList(struct node* n);

void deleteList(struct node** head_ref){
  struct node* curr = *head_ref;
  struct node* next;

  while(curr!=NULL){
    next =curr->next;
    free(curr);
    curr=next;
  }
  *head_ref=NULL;
  printf("Deleted Linked List \n");
}

void push(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)= new_node;
}

int main(){
  struct node* head=NULL;

  int ch,val;

  printf("OPERATIONs\n");
  printf("1.Insert\n");
  printf("2.Delete the linked list\n");
  printf("3.Exit\n");

  do{
    printf("Enter choice=");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: deleteList(&head);
              break;
      case 3: exit(0);
      }
    }while(ch>0);
  return 0;
  }
