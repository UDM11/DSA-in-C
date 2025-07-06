#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(Node** head, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1 && p2) {
        if (p1->expo > p2->expo) {
            insertEnd(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        } else if (p1->expo < p2->expo) {
            insertEnd(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        } else {
            insertEnd(&result, p1->coeff + p2->coeff, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insertEnd(&result, p1->coeff, p1->expo);
        p1 = p1->next;
    }
    while (p2) {
        insertEnd(&result, p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

// Display polynomial
void display(Node* head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->expo);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    // Polynomial 1: 5x^4 + 4x^2 + 2
    insertEnd(&poly1, 5, 4);
    insertEnd(&poly1, 4, 2);
    insertEnd(&poly1, 2, 0);
    // Polynomial 2: 5x^3 + 2x^2 + 3x + 1
    insertEnd(&poly2, 5, 3);
    insertEnd(&poly2, 2, 2);
    insertEnd(&poly2, 3, 1);
    insertEnd(&poly2, 1, 0);
    printf("Polynomial A: ");
    display(poly1);
    printf("Polynomial B: ");
    display(poly2);
    sum = addPoly(poly1, poly2);
    printf("Sum: ");
    display(sum);
    return 0;
}
