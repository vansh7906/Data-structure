#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; } *rear = NULL;
void enqueue(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    if (!rear) {
        n->next = n;
    } else {
        n->next = rear->next;
        rear->next = n;
    }
    rear = n;
}
int dequeue() {
    if (!rear) return printf("Empty\n"), -1;
    struct Node* front = rear->next;
    int val = front->data;
    if (front == rear) rear = NULL;
    else rear->next = front->next;
    free(front);
    return val;
}
void display() {
    if (!rear) return;
    struct Node* temp = rear->next;
    do {
        printf("%d ", temp->data);
    } while ((temp = temp->next) != rear->next);
    printf("\n");
}
int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display(); 
    printf("Deleted: %d\n", dequeue());
    display(); 
}
