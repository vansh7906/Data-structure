#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node *head){
    struct Node *temp=head;
    printf("here is the linkedlist\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct Node* linkedlist(int len){
    struct Node *head=NULL;
    struct Node *temp=NULL;
    
    int curr_pos=1;
    printf("enter values of nodes\n");
    while(curr_pos<=len){
        if(head==NULL){
            temp=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&temp->data);
            head=temp;
            temp->next=NULL;
        }
        else{
            temp->next=(struct Node*)malloc(sizeof(struct Node));
            temp=temp->next;
            scanf("%d",&temp->data);
            temp->next=NULL;
        } 
        curr_pos++;
    }
    return head;
}

struct Node* linkedlist_insertion(int pos,struct Node* head){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter val of node to be inserted\n");
    scanf("%d",&newnode->data);
    
    if(pos==1){
        newnode->next=head;
        return newnode;
    }
    
    struct Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

int main(){
    int len;
    printf("enter the len of linked list\n");
    scanf("%d",&len);
    struct Node *head=linkedlist(len);
    int pos;
    printf("enter the pos to be insert\n");
    scanf("%d",&pos);
    
    head=linkedlist_insertion(pos,head);
    display(head);
    return 0;
}
