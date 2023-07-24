#include <stdio.h> 
#include <stdlib.h>

int fibonacci1(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1 || n == 2) {
        return n;
    }
    else {
        return fibonacci1(n - 3) + fibonacci1(n - 2);
    }
}
int main() {
  
   int x = fibonacci1(6);
    printf("output from fibonacci1 =: %d\n", x);
}