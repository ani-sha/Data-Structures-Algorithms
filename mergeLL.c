#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref,int new_data);
void MoveNode(struct node** destRef, struct node** sourceRef);

struct node* SortedMerge(struct node* a, struct node* b){
  struct node* result = NULL;
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
  if (a->data <= b->data){
     result = a;
     result->next = SortedMerge(a->next, b);
  }else{
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

void printList(struct node *node){
    while (node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

void push(struct node** head_ref,int new_data){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)= new_node;
}

int main(){
    int val,aa,bb;
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;

    printf("Enter limit : ");
    scanf("%d",&val);

    printf("Enter elements for LL a :\n");
    for(int i=0;i<val;i++){
      scanf("%d",&aa);
      push(&a,aa);
    }

    printf("Enter elements for LL b :\n");
    for(int i=0;i<val;i++){
      scanf("%d",&bb);
      push(&a,bb);
    }

    res=SortedMerge(a,b);


    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
