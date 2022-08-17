#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* traversal (struct node *head){
    int count  = 0;
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("\t%d \t ", ptr->data);
        ptr = ptr->link;
        count++;
    }
    printf(" \n No. of Nodes in Linked List :- %d  \n ", count);
    return head;
}
struct node* delete_from_last (struct node *head){
 struct node* temp1 = head ;
  struct node* temp2 = head ;
    while(temp1->link != NULL){
        temp2 = temp1;
        //  This always come before temp1 coz temp->link move forward direction below.
        temp1 = temp1->link;
    }
    temp2->link = NULL;
    free(temp1);
    temp1 = NULL;
    return head;
}
int main(){
  struct node *head,*second,*last;
  head = (struct node *) malloc (sizeof(struct node));
  second = (struct node *) malloc (sizeof(struct node));
  last = (struct node *) malloc (sizeof(struct node));
  head->data = 56;
  head->link = second;
  second->data = 78;
  second->link = last;
  last->data =93;
  last->link = NULL;
  traversal(head);
  head = delete_from_last(head);
  traversal(head);
  return 0;
}