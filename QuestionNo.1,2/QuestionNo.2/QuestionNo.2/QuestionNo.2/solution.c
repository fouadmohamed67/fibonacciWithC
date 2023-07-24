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
int fibonacci2(int n) {
    
    int *tempArr;
    tempArr = (int*)malloc(n+1 * sizeof(int)); 

    if (n < 3) {
        return n;
    }
    else if (tempArr[n] != 0) {
        return tempArr[n];
    }
    else {
        tempArr[n] = fibonacci2(n - 3) + fibonacci2(n - 2);
        return tempArr[n];
    }
}
int main() {
    int output1 = fibonacci1(6);
    printf("output1=: %d\n", output1);
    int output2 = fibonacci2(6);
    printf("output2=: %d\n", output2);

}