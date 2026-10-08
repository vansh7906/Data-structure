
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
}; 

int main() {
    int choice;
    struct node *newnode, *head = NULL, *temp = NULL; 
    
    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        
        printf("enter the val of new node\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL; 
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("enter 1 if u want to add another node else enter 0\n");
        scanf("%d", &choice);

    } while(choice == 1);

    printf("\nYour linked list: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
