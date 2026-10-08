#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createlink(int len){
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    for(int i=0;i<len;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("memorry allocation failed\n");
        }
        else{
            printf("enter data\n");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            if(head==NULL){
                head=newnode;
                temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            
        }      
    }
    return head; 
}
int numberofnodes(struct node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
struct node *searching(struct node *head ,int key){
    while(head!=NULL){
        if(head->data==key){
            return head;
        }
        head=head->next;
    }
    return NULL;
}
void main(){
    struct node *head=createlink(4);
    int len=numberofnodes(head);
    printf("there are %d no of nodes\n",len);
    struct node *a=searching(head,78);
    if(a==NULL){
        printf("not found\n");
    }
    else{
        printf("found %d\n",a->data);
    }
    
}
