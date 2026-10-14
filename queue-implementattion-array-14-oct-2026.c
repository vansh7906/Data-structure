#include <stdio.h>

int q[100];
int r = -1;
int f = -1;

void enqueu(int data) {
    if (r == 99) {
        printf("overflow\n");
    } 
    else if (f == -1 && r == -1) { 
        f = 0;
        r = 0;
        q[r] = data;
    } 
    else {
        q[++r] = data;
    }
}

void dequeue() {
    if (f == -1 || f > r) { 
        printf("queue is empty\n");
    } 
    else {
        printf("Dequeued: %d\n", q[f]);
        f++;
        
        if (f > r) {
            f = -1;
            r = -1;
        }
    }
}

void display() {
    if (f == -1 || f > r) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    enqueu(24);
    enqueu(2);
    enqueu(90);
    display();
    
    dequeue();
    display();
    
    return 0;
}
