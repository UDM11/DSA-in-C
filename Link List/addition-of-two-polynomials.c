#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

// Create new node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end
void insertTerm(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct PolyNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display polynomial
void display(struct PolyNode* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Add two polynomials
struct PolyNode* addPoly(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct PolyNode *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    // P1(x) = 4x^3 + 3x^2 + 6
    insertTerm(&poly1, 4, 3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 6, 0);

    // P2(x) = 5x^2 + 2x + 4
    insertTerm(&poly2, 5, 2);
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 4, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}
