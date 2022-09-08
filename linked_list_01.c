#include<stdio.h>
#include<stdlib.h>
// PROGRAM TO COUNT NUMBERS OF NODE IN LINKED LIST.....
struct node{
    int data;
    struct node *link;
};
void traverse(struct node *ptr){
    static int count;
   while(ptr!= NULL){
     printf("%d  ", ptr->data);
    ptr = ptr->link;
   // PTR will changes to next link of node
   count++;
   }
   printf("No. of NODES = %d ", count);
}
int main(){
  struct node *head;
   struct node *second;
   struct node *last;
   head = (struct node *) malloc(sizeof(struct node));
   second = (struct node *) malloc(sizeof(struct node));
   last = (struct node *) malloc(sizeof(struct node));
   head->data = 67;
   head->link = second;
   second->data = 77;
   second->link = last;
   last->data = 87;
   last->link = NULL;
//    printf("%u   ", second->link);
//     printf("%u", &last->data);

/*---> PASSING HEAD TO THE POINTER */ 
traverse(head);  
return 0;
}