#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void main(){
    int choice;
    struct node *temp=NULL,*head=NULL,*newnode;
    
    do{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value of newnode\n");
        scanf("%d",&newnode->data);
        if(head == NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
        printf("enter 1 if u want to add another node or enter 0 if not\n");
        scanf("%d",&choice);

    }
    while(choice==1);
    printf("enter the val of the new node\n");
    struct node *bnode;
    bnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&bnode->data);
    bnode->next=head;
    head=bnode;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
