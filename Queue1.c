#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("%d Enqueued into queue\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    char choice;
    int data;
    do {
        printf("\nEnter your choice:\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\nq: Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice); 

        switch(choice) {
            case '1':
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case '2':
                printf("Dequeuing element...\n");
                dequeue();
                break;
            case '3':
                display();
                break;
            case 'q':
            case 'Q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 'q' && choice != 'Q' );
    return 0;
}

