#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    int data; 
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
    case FIBO:
    {
        int fibResult = fibFun(a->data);
        Node* node = (Node*)malloc(sizeof(Node));
        node->type = FIBO;
        node->data = fibResult;
      
        return node;
    } 
    default:
        return NULL;
    }
}

Node* addFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = ADD;
    node->data = a + b; 
    return node;
}

Node* subFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = SUB;
    node->data = a-b; 
    return node;
}

Node* mulFunc(int a, int b) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = MUL;
    node->data = a * b; 
    return node;
}
int fibFun(int a) {
    if (a == 0) {
        return 0;
    }
    else if (a== 1) {
        return 1;
    }
    else {
        return fibFun(a - 1)  + fibFun(a - 2);
    }
}
void calc(Node* node) {
    switch (node->type) {
    case 0:
        return   printf("add = %d\n", node->data);
    case 1:
        return  printf("sub = %d\n", node->data);
    case 2:
        return  printf("mul = %d\n", node->data);
    case 3:
        return  printf("FIBO = %d\n", node->data);

    default:
        return NULL;
    }
    
}
int main() {
    Node* d1= (Node*)malloc(sizeof(Node));
    d1->data = 10;
    Node* d2 = (Node*)malloc(sizeof(Node));
    d2->data = 6; 
    Node* d3 = (Node*)malloc(sizeof(Node));
    d3->data = 5;
    Node* d4 = (Node*)malloc(sizeof(Node));
    d4->data = 4;

   Node* add = makeFunc(ADD, d1, d2);
   Node* mul = makeFunc(MUL, d3, d4);
   Node* sub = makeFunc(SUB, mul, add);
   Node* fibo = makeFunc(FIBO, sub, NULL);
   calc(add);
   calc(mul);
   calc(sub);
   calc(fibo);

     
    return 0;
}