#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL; 

// Insert at beginning
void insert_begin(int data) {
    Node* newnode = (struct Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

// Insert at end
void insert_end(int data) {
    Node* newnode = (struct Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->prev = ptr;
}

// Insert at kth position
void insert_k(int data, int k) {
    if (k <= 1 || head == NULL) {
        insert_begin(data);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < k - 1 && temp->next != NULL; i++)
        temp = temp->next;

    Node* newnode = (struct Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

// Delete from beginning
void delete_begin() {
    if (head == NULL)
        return;
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL)
        return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete at kth position
void delete_k(int k) {
    if (head == NULL || k <= 0)
        return;
    if (k == 1) {
        delete_begin();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Update node at kth position
void update_k(int k, int new_data) {
    if (head == NULL || k <= 0) {
        printf("Invalid position.\n");
        return;
    }

    Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position %d does not exist.\n", k);
        return;
    }

    temp->data = new_data;
    printf("Node at position %d updated to %d.\n", k, new_data);
}


void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    insert_begin(10);
    insert_begin(20);
    insert_k(15, 2);
    insert_k(5, 10); 
    insert_end(25);

    printf("After Insertions:\n");
    display();

    update_k(3, 99);
    printf("After Updating position 3 to 99:\n");
    display();

    delete_k(2);
    printf("After Deleting at position 2:\n");
    display();

    delete_end();
    printf("After Deleting at end:\n");
    display();

    delete_begin();
    printf("After Deleting at beginning:\n");
    display();

    return 0;
}