#include <stdio.h>
int fibonacci(int n){
    if(n<= 1){
        return n;                   
    }
    // recursive case
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int num;
    printf("enter fibonacci number: ");
    scanf("%d",&num);
    printf("%d\n",fibonacci(num));
    return 0;
}