#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at specific position
void insertAtPosition(struct Node** head_ref, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating initial list: 10 → 20 → 30
    insertAtPosition(&head, 30, 1);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 10, 1);

    printf("Original list: ");
    display(head);

    // Insert 25 at position 3 (between 20 and 30)
    insertAtPosition(&head, 25, 3);

    printf("After inserting 25 at position 3: ");
    display(head);

    return 0;
}
