#include <stdio.h>
#define SIZE 3

int items[SIZE];
int front = -1, rear = -1;

// check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// check if the queue is empty
int isEmpty() {
    return front == -1;
}

// adding an element
void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is full!!");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = value;
        printf("\n%d enqueued into queue.", value);
    }
}

// removing an element
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty!!");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element: %d", element);
        return element;
    }
}

// display the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("\nEmpty Queue.");
    } else {
        printf("\nQueue elements: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\nFront:%d \t", front);
        printf("Rear:%d", rear);
    }
}

int main() {
    printf("---Circular Queue Implementation---\n");
    dequeue(); // test dequeue on empty

    enqueue(10);
    enqueue(20);
    enqueue(30);

    enqueue(40); // should fail (queue full)

    display();
    dequeue();  // removes one item
    display();

    enqueue(50); // now should succeed
    display();

    enqueue(60); // should fail again
    return 0;
}
