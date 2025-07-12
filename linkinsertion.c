#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory Allocation error!!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node* node;
    node = createNode(10);
    if (node != NULL) {
        printf("Node created with data = %d\n", node->data);
        printf("Address of node       = %p\n", (void*)node);
        printf("Address in next ptr   = %p\n", (void*)node->next);
    }
    free(node);
    return 0;
}