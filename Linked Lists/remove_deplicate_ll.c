#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to insert at end (used for testing)
void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to remove duplicates from sorted list
void removeDuplicates() {
    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* dup = current->next;
            current->next = current->next->next;
            free(dup);
        } else {
            current = current->next;
        }
    }
}

// Function to print list
void printList() {
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Inserting sorted values with duplicates
    insertEnd(10);
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(30);
    insertEnd(30);
    insertEnd(40);

    printf("Original Sorted List:\n");
    printList();

    removeDuplicates();

    printf("After Removing Duplicates:\n");
    printList();

    return 0;
}
