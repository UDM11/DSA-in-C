#include <stdio.h>
#include <stdlib.h>

/// -----------------------------
/// Doubly Linked List Section
/// -----------------------------
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* dhead = NULL;

void dll_addFirst(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dhead;

    if (dhead != NULL)
        dhead->prev = newNode;

    dhead = newNode;
}

void dll_addLast(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;

    if (dhead == NULL) {
        newNode->prev = NULL;
        dhead = newNode;
        return;
    }

    DNode* temp = dhead;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void dll_addAtPosition(int data, int pos) {
    if (pos <= 1) {
        dll_addFirst(data);
        return;
    }

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;

    DNode* temp = dhead;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        dll_addLast(data);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void dll_display() {
    DNode* temp = dhead;
    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/// -----------------------------
/// Doubly Circular Linked List
/// -----------------------------
typedef struct DCNode {
    int data;
    struct DCNode* prev;
    struct DCNode* next;
} DCNode;
DCNode* dchead = NULL;

void dcll_addFirst(int data) {
    DCNode* newNode = (DCNode*)malloc(sizeof(DCNode));
    newNode->data = data;

    if (dchead == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        dchead = newNode;
        return;
    }

    DCNode* last = dchead->prev;

    newNode->next = dchead;
    newNode->prev = last;
    dchead->prev = newNode;
    last->next = newNode;
    dchead = newNode;
}

void dcll_addLast(int data) {
    if (dchead == NULL) {
        dcll_addFirst(data);
        return;
    }

    DCNode* newNode = (DCNode*)malloc(sizeof(DCNode));
    newNode->data = data;

    DCNode* last = dchead->prev;

    newNode->next = dchead;
    newNode->prev = last;
    last->next = newNode;
    dchead->prev = newNode;
}

void dcll_addAtPosition(int data, int pos) {
    if (pos <= 1) {
        dcll_addFirst(data);
        return;
    }

    DCNode* newNode = (DCNode*)malloc(sizeof(DCNode));
    newNode->data = data;

    DCNode* temp = dchead;
    for (int i = 1; i < pos - 1 && temp->next != dchead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void dcll_display() {
    if (dchead == NULL) {
        printf("Doubly Circular Linked List is empty.\n");
        return;
    }

    DCNode* temp = dchead;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != dchead);
    printf("(Back to Head)\n");
}

/// -----------------------------
/// Main Function
/// -----------------------------
int main() {
    printf("=== Doubly Linked List ===\n");
    dll_addFirst(10);
    dll_addLast(30);
    dll_addAtPosition(20, 2);
    dll_display();

    printf("\n=== Doubly Circular Linked List ===\n");
    dcll_addFirst(100);
    dcll_addLast(300);
    dcll_addAtPosition(200, 2);
    dcll_display();

    return 0;
}
