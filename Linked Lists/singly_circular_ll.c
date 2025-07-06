#include <stdio.h>
#include <stdlib.h>

/// -----------------------------
/// Singly Linked List Section
/// -----------------------------
typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

SNode* shead = NULL;

void sll_addFirst(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = shead;
    shead = newNode;
}

void sll_addLast(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;

    if (shead == NULL) {
        shead = newNode;
        return;
    }

    SNode* temp = shead;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void sll_addAtPosition(int data, int pos) {
    if (pos <= 1) {
        sll_addFirst(data);
        return;
    }

    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;

    SNode* temp = shead;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void sll_display() {
    SNode* temp = shead;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/// -----------------------------
/// Singly Circular Linked List
/// -----------------------------
typedef struct SCNode {
    int data;
    struct SCNode* next;
} SCNode;

SCNode* schead = NULL;

void scll_addFirst(int data) {
    SCNode* newNode = (SCNode*)malloc(sizeof(SCNode));
    newNode->data = data;

    if (schead == NULL) {
        newNode->next = newNode;
        schead = newNode;
        return;
    }

    SCNode* temp = schead;
    while (temp->next != schead)
        temp = temp->next;

    newNode->next = schead;
    temp->next = newNode;
    schead = newNode;
}

void scll_addLast(int data) {
    SCNode* newNode = (SCNode*)malloc(sizeof(SCNode));
    newNode->data = data;

    if (schead == NULL) {
        newNode->next = newNode;
        schead = newNode;
        return;
    }

    SCNode* temp = schead;
    while (temp->next != schead)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = schead;
}

void scll_addAtPosition(int data, int pos) {
    if (pos <= 1) {
        scll_addFirst(data);
        return;
    }

    SCNode* newNode = (SCNode*)malloc(sizeof(SCNode));
    newNode->data = data;

    SCNode* temp = schead;
    for (int i = 1; i < pos - 1 && temp->next != schead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void scll_display() {
    if (schead == NULL) {
        printf("Singly Circular Linked List is empty.\n");
        return;
    }

    SCNode* temp = schead;
    printf("Singly Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != schead);
    printf("(Back to Head)\n");
}

/// -----------------------------
/// Main Function
/// -----------------------------
int main() {
    printf("=== Singly Linked List ===\n");
    sll_addFirst(30);
    sll_addLast(50);
    sll_addAtPosition(40, 2);
    sll_display();

    printf("\n=== Singly Circular Linked List ===\n");
    scll_addFirst(100);
    scll_addLast(200);
    scll_addAtPosition(150, 2);
    scll_display();

    return 0;
}
