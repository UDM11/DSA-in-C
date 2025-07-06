#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to insert at the end
void insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Recursive function to reverse linked list
Node* reverseRecursive(Node* node) {
    if (node == NULL || node->next == NULL)
        return node;

    Node* rest = reverseRecursive(node->next);
    node->next->next = node;
    node->next = NULL;
    return rest;
}

// Function to print the list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Inserting some values
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf("Original List:\n");
    printList(head);

    head = reverseRecursive(head);

    printf("Reversed List (Recursively):\n");
    printList(head);

    return 0;
}
