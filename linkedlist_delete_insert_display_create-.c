#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node *head){
    struct Node *temp = head;
    printf("\nHere is the linked list:\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* linkedlist(int len){
    struct Node *head = NULL;
    struct Node *temp = NULL;
    
    int curr_pos = 1;
    printf("Enter values of nodes:\n");
    while(curr_pos <= len){
        if(head == NULL){
            temp = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &temp->data);
            head = temp;
            temp->next = NULL;
        }
        else{
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
            scanf("%d", &temp->data);
            temp->next = NULL;
        } 
        curr_pos++;
    }
    return head;
}

struct Node* linkedlist_insertion(int pos, struct Node* head){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter val of node to be inserted: ");
    scanf("%d", &newnode->data);
    
    if(pos == 1){
        newnode->next = head;
        return newnode;
    }
    
    struct Node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return head;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct Node* linkedlist_deletion(int pos, struct Node* head){
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    
    struct Node *temp = head;
    
    if (pos == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    
    struct Node *nodetodelete = temp->next;
    temp->next = nodetodelete->next;
    free(nodetodelete);
    
    return head;
}

int main(){
    int len;
    printf("Enter the len of linked list: ");
    scanf("%d", &len);
    struct Node *head = linkedlist(len);
    
    int choice;
    printf("\nChoose an option:\n1. Insertion\n2. Deletion\n3. Display Only\nEnter choice (1-3): ");
    scanf("%d", &choice);
    
    int pos;
    if (choice == 1) {
        printf("Enter the pos to insert: ");
        scanf("%d", &pos);
        head = linkedlist_insertion(pos, head);
    } 
    else if (choice == 2) {
        printf("Enter the pos to delete: ");
        scanf("%d", &pos);
        head = linkedlist_deletion(pos, head);
    }
    
    display(head);
    return 0;
}
