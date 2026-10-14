#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("System Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct Queue *q) {
    return (q->front == NULL);
}

void enqueue(struct Queue *q, int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (isEmpty(q)) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = q->front;
    int dequeuedData = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedData;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeQueue(struct Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    struct Queue *myQueue = createQueue();

    enqueue(myQueue, 78);
    enqueue(myQueue, 80);
    enqueue(myQueue, 2);
    enqueue(myQueue, 73);
    
    dequeue(myQueue);
    display(myQueue);

    freeQueue(myQueue);
    return 0;
}
