#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* Crate_New_CLL (struct node *head, int newdata){
struct node *ptr = malloc(sizeof(struct node));
ptr->data = newdata;
ptr->link = ptr;
}
struct node* traversal (struct node *head){
    struct node *ptr = malloc(sizeof(struct node));
    ptr = head->link;
    printf("%d \t", head->data);
    while(ptr!=head){
        printf("\t%d \t ", ptr->data);
        ptr = ptr->link;
    }
}
struct node *insert_at_last(struct node *head, int ndata){
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    while(ptr->link != head){
        ptr = ptr->link;
    }
    temp ->data = ndata; 
    ptr->link = temp;
    temp->link = head;
    return head;
}
int main(){
struct node *head  = malloc(sizeof(struct node));
int data = 56;
head = Crate_New_CLL(head, data);
traversal(head);
head = insert_at_last(head,96);
head = insert_at_last(head, 79);
head = insert_at_last(head, 85);
traversal(head);
    return 0;
}