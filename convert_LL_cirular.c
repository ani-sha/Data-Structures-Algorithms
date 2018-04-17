#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void displayList(struct Node* node);
void push(struct Node** head, int data);

struct Node* circular(struct Node* head){
    struct Node* start = head;
     while (head->next != NULL)
        head = head->next;
    head->next = start;
    return start;
}

void push(struct Node** head, int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = (*head);
     (*head) = newNode;
}

void displayList(struct Node* node){
    struct Node* start = node;

    while (node->next != start) {
        printf("%d ", node->data);
        node = node->next;
    }
         printf("%d ", node->data);
}

int main(){
  struct Node* head=NULL;

  int ch,val;
  printf("\nOPERATIONs\n");
  printf("1.Insert\n");
  printf("2.Convert\n");
  printf("3.Print\n");
  printf("3.Exit\n");

  do{
    printf("\nEnter choice = ");
    scanf("%d",&ch);

    switch (ch){
      case 1: printf("Enter new data = ");
              scanf("%d",&val);
              push(&head,val);
              break;
      case 2: circular(head);
              break;
      case 3: printf("The list is : ");
              displayList(head);
              break;
      case 4:exit(0);
    }
  }while(ch!=0);
return 0;
}
