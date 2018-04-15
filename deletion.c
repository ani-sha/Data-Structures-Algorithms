#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int new_data);
void deleteNode(struct node** head_ref,int key);
void printList(struct node* n);

void push(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)= new_node;
}

void deleteNode(struct node** head_ref,int key){
  struct node* temp= *head_ref, *prev_node;
  if(temp!=NULL && temp->data==key){
    *head_ref=temp->next;
    free(temp);
    return;
  }
 while(temp!=NULL && temp->data!=key){
  prev_node=temp;
  temp=temp->next;
 }
if(temp==NULL)
return;

prev_node->next=temp->next;

free(temp);
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
  printf("1.Insert\n");
  printf("2.Delete\n");
  printf("3.Print linked list\n");
  printf("4.Exit\n");

  do{
    printf("Enter choice=");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: printf("Enter data to delete = ");
              scanf("%d",&val);
              deleteNode(&head,val);
              break;
      case 3: printf("The linked List is: ");
              printList(head);
              break;
      case 4: exit(0);

      }
    }while(ch!=0);
  return 0;
  }
