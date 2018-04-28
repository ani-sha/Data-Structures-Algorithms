#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int new_data);
void printList(struct node* n);
static void reverse(struct node** head_ref);

void push(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)= new_node;
}

static void reverse(struct node** head_ref){
  struct node* prev=NULL;
  struct node* curr=*head_ref;
  struct node* next=NULL;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  *head_ref=prev;
}

void printList(struct node* n){
  struct node* temp= n;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}

int main(){
  struct node* head=NULL;

  int ch,val;

  printf("OPERATIONs\n");
  printf("1.Insert\n");
  printf("2.Reverse the linked list\n");
  printf("3.Exit\n");

  while(1){
    printf("Enter choice=");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: reverse(&head);
              printf("result= ");
              printList(head);
              getchar();
              break;
      case 3: exit(0);
      }
    }
  return 0;
  }
