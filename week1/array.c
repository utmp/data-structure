#include <stdio.h>
#define arr_length 9 
int main(){
    int array[arr_length];
    // definining array 
    for(int i = 0; i<arr_length;i++){
        printf("enter number for %d index of array: ",i);
        scanf("%d",&array[i]);
    }
    // printing array
    printf("here's your array:\n");
    for (int i = 0; i < arr_length; i++)
    {
        printf("%d \t",array[i]);
    }
    
}