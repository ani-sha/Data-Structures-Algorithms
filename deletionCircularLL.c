#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node **head_ref,int data);
void printList(struct node *head);
void deleteNode(struct node *head, int key);


void push(struct node **head_ref,int data){
  struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
  struct node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;

  if(*head_ref!=NULL){
    while(temp->next!= *head_ref)
      temp=temp->next;
    temp->next=ptr1;
  }
  else
    ptr1->next=ptr1;

  *head_ref=ptr1;
}

void printList(struct node *head){
    struct node *temp = head;
    if (head != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

void deleteNode(struct node *head, int key){
  struct node *curr = head, *prev;
  while(curr->data!=key){
    if(curr->next == head){
      printf("Node not present\n");
      break;
    }
    prev=curr;
    curr=curr->next;
  }
if(curr == head){
  prev=head;
  while(prev->next!=head)
     prev=prev->next;
     prev->next = head;
     free(curr);
   }
 else if (curr -> next == head){
  prev->next = head;
         free(curr);
     }else{
         prev->next = curr->next;
         free(curr);
     }
  }


int main(){
  struct node* head=NULL;

  int ch,val;
  printf("\nOPERATIONs\n");
  printf("1.Insert\n");
  printf("2.Print Linked List\n");
  printf("3. Delete a node\n");
  printf("4.Exit\n");

  do{
    printf("\nEnter choice = ");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: printf("The linked List is: ");
              printList(head);
              break;
      case 3: printf("\nEnter node to delete =");
              scanf("%d",&val);
              deleteNode(head,val);
              break;
      case 4: exit(0);
    }
  }while(ch!=0);
return 0;
}
