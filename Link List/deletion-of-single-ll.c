#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end (to build list)
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete node at specific position
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Delete first node
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node before the one to delete
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Display the list
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

    // Build initial list: 10 → 20 → 30 → 40
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Original List: ");
    display(head);

    // Delete node at position 3
    deleteAtPosition(&head, 3);

    printf("After deleting node at position 3: ");
    display(head);

    return 0;
}
