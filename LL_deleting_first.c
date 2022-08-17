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
struct node *delete_from_first(struct node *head){
    struct node *temp = head;
    head = temp->link;
    free(temp);
    return head;
}
struct node *delete_at_particular_position(struct node *head,int index){
     struct node* previous = head ;
  struct node* current = head ;
  while(index!=1){
    previous = current;
    current = current->link;
    index--;
  }
  previous->link = current->link;
  free(current);
  current = NULL;
  return head;
}
struct node *delete_ALL(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        temp= temp->link;
        free(head);
        head = temp;
    }
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
//   head = delete_from_first(head);
//   traversal(head);
//    head = delete_at_particular_position(head,2);
//   traversal(head);
  head = delete_ALL(head);
  traversal(head);
  return 0;
}