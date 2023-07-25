#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
} TypeTag;

typedef struct Node {
    TypeTag type;
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* addFunc(int a, int b);
Node* subFunc(int a, int b);
Node* mulFunc(int a, int b);

Node* makeFunc(TypeTag op, Node *a, Node *b) {
    switch (op) {
    case ADD: 
        return addFunc(a->data, b->data);  
    case SUB: 
        return subFunc(a->data, b->data);
    case MUL: 
        return mulFunc(a->data, b->data);
    default:
        return NULL;
    }
}

Node* addFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = ADD;
    node->data = a + b;
    node->next = NULL;
    return node;
}

Node* subFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = SUB;
    node->data = a - b;
    node->next = NULL;
    return node;
}

Node* mulFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = MUL;
    node->data = a * b;
    node->next = NULL;
    return node;
}

int main() {
    Node* d1= (Node*)malloc(sizeof(Node));
    d1->data = 10;
    Node* d2 = (Node*)malloc(sizeof(Node));
    d2->data = 6;

    Node* add = makeFunc(ADD, d1, d2);
    Node* mul = makeFunc(MUL, d1, d2);
    Node* sub = makeFunc(SUB, mul, add);
    printf("add: %d\n", add->data);
    printf("mul: %d\n", mul->data);
    printf("sub: %d\n", sub->data); 

    free(add);
    return 0;
}