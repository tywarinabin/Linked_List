#include<stdio.h>
#include<stdlib.h>
struct node{
struct node* prev;
int data;
struct node* next;
};
static int counter;
struct node *data_rakhum(struct node* head , int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp ->data = data;
    temp->next= NULL;
    head = temp;
    return head;

}
void show_gardim(struct node *head){
  struct node *ptr = head;
  counter++;
  printf("You have show your data of Linked list %d times.\n These are your data : \t ", counter);
  while(ptr!=NULL){
    printf("%d   \t", ptr->data);
    ptr= ptr->next;
  }
  
}
struct node *insert_at_first(struct node* head , int ndata){
  struct node *ptr = (struct node *) malloc (sizeof (struct node));
  ptr->next = head;
  ptr->data = ndata;
  ptr->prev = NULL;
  head ->prev = ptr;
  head->next = NULL;
  head = ptr;
  return head;
}
struct node *last_ma_add(struct node* head , int ndata){
  struct node *ptr = (struct node *) malloc (sizeof (struct node));
  struct node *temp = head;
  while(temp->next!= NULL){
    temp= temp->next;
  }
  ptr->prev = temp;
  ptr->data = ndata;
  ptr->next = NULL;
  temp->next = ptr;
  return head;
}
int main(){
  struct node *head ;
  head = (struct node *)  malloc (sizeof(struct node));
  head = data_rakhum(head,78);
  show_gardim(head);
  printf(" \n ");
  head = insert_at_first(head, 84);
  show_gardim(head);  // output : 84 and 78
  head = last_ma_add(head,45);
  show_gardim(head); // Output -> 84, 78 and 45
  return 0;
}