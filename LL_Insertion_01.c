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
    printf(" \nThere are %d nodes in a LINKED LIST\n ", count);
    return head;
}
struct node* insert_at_First(struct node *head, int d){
    struct node* ptr = (struct node *) malloc (sizeof(struct node));
    ptr ->data = d;
    ptr->link = head;
   return ptr;
}
struct node* insert_at_last(struct node* head , int D){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    struct node* temp = head ;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link =ptr;
    ptr ->data = D;
    ptr->link = NULL;
    return head;
}
struct node* Insert_at_givenNde(struct node *head, struct node *previous_node,int D){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    ptr->data = D;
    ptr->link = previous_node->link;
    previous_node->link = ptr;
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
 head = insert_at_First(head, 83);
 traversal(head);
 head = insert_at_last(head,69);
 traversal(head);
 head = Insert_at_givenNde(head , last, 44);
 traversal(head);
 return 0;
}