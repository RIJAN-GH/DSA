#include <stdio.h>
#include <stdlib.h>

// Singly Linked List structure
struct Node {
    int info;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->info = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

// Function to insert at a given position
void insertAtPosition(int data, int pos) {
    if (pos < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->info = data;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* ptr = head;
    for (int i = 0; i < pos - 1; i++) {
        if (ptr == NULL) {
            printf("Position not found!\n");
            free(newNode);
            return;
        }
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Function to delete at the beginning
void delAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted element is %d\n", temp->info);
    free(temp);
}

// Function to delete at the end
void delAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* ptr = head;
    struct Node* temp = NULL;

    if (head->next == NULL) {
        printf("Deleted element is %d\n", head->info);
        free(head);
        head = NULL;
        return;
    }

    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }

    temp->next = NULL;
    printf("Deleted element is %d\n", ptr->info);
    free(ptr);
}

// Function to delete at k-th position
void delAtPosition(int k) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (k < 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* ptr = head;
    struct Node* temp = NULL;

    if (k == 0) {
        head = head->next;
        printf("Deleted element is %d\n", ptr->info);
        free(ptr);
        return;
    }

    for (int i = 0; i < k - 1; i++) {
        if (ptr->next == NULL) {
            printf("Position not found!\n");
            return;
        }
        ptr = ptr->next;
    }

    temp = ptr->next;
    if (temp == NULL) {
        printf("Position not found!\n");
        return;
    }
    
    ptr->next = temp->next;
    printf("Deleted element is %d\n", temp->info);
    free(temp);
}

// Function to traverse and print the list
void traverse() {
    struct Node* ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos;
    
    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at K-th Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from K-th Position\n");
        printf("7. Traverse\n");
        printf("8. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
                
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
                
            case 3:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtPosition(data, pos);
                break;

            case 4:
                delAtBeginning();
                break;
                
            case 5:
                delAtEnd();
                break;
                
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                delAtPosition(pos);
                break;
                
            case 7:
                traverse();
                break;
                
            case 8:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 8);

    return 0;
}