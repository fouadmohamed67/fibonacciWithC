#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    add,
    sub,
    mul,
} TypeTag;

typedef struct Node {
    TypeTag type;
    int data;
    struct Node* next;
} Node;

Node* makeFunc(TypeTag op) {
    switch (op) {
    case add:
        return addFunc;
    case sub:
        return subFunc;
    case mul:
        return mulFunc;
    default:
        return NULL;
    }
}

Node* addFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = add;
    node->data = a + b;
    node->next = NULL;
    return node;
}

Node* subFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = sub;
    node->data = a - b;
    node->next = NULL;
    return node;
}

Node* mulFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = mul;
    node->data = a * b;
    node->next = NULL;
    return node;
}

int main() {
    Node* add = (*makeFunc(add))(10, 6);
    printf("add: %d\n", add->data);
    free(add);
    return 0;
}