#include<stdio.h>
#include<stdlib.h>
struct node{
struct node* prev;
int data;
struct node* next;
};
void show_gardim(struct node *head){
  struct node *ptr = head;
//   printf("You have show your data of Linked list %d times.\n These are your data : \t ", counter);
  while(ptr!=NULL){
    printf("%d   \t", ptr->data);
    ptr= ptr->next;
  }
  
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
struct node *data_rakhum(struct node* head , int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp ->data = data;
    temp->next= NULL;
    head = temp;
    return head;

}
struct node *create_list(struct node *head){
    int n,data;
    printf("Enter the no. of Nodes: \n");
    scanf("%d", &n);
    if(n==0){
      return head;
    }
    else{
        printf("Enter data for NODE 1: ");
        scanf("%d", &data);
        head = data_rakhum(head,data);
        for(int i = 1;i<n;i++){
            printf("Enter data for NODE %d: ", i+1);
            scanf("%d", &data);
            head = last_ma_add(head,data);
        }
        return head;
    }
}
int main(){
    struct node *head = NULL;
    head= create_list(head);
    show_gardim(head);
    return 1;

}