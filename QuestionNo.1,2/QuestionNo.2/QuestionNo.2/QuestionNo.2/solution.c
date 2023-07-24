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
    tempArr = (int*)malloc(n * sizeof(int)); 
    for (int i = 0; i < 3; i++)
    {
        tempArr[i] = i;
    }
    for (int x = 3; x <= n; x++)
    {
        tempArr[x] = tempArr[x - 3] + tempArr[x - 2];
    }
    return tempArr[n];

}
int fibonacci3(int n) {
    if (n < 3) {
        return n;
    }
    int fib_n_minus_3 = 0;
    int fib_n_minus_2 = 1;

    int fiboN = 0; 
    for (int i = 3; i <= n; i++) {
        fiboN = fib_n_minus_3 + fib_n_minus_2  ;//1
        fib_n_minus_3 = fib_n_minus_2;//1
        fib_n_minus_2 = fiboN;
      
    } 
    return fiboN;
}
int main() {
    int output1 = fibonacci1(3);
    printf("output1=: %d\n", output1);
    int output2 = fibonacci2(3);
    printf("output2=: %d\n", output2);
    int output3 = fibonacci3(3);
    printf("output3=: %d\n", output3);

}