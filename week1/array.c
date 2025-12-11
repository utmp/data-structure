#include <stdio.h>

#define arr_length 4

void traverseArray(int arr[], int size) {
    printf("Array elements (reverse): ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void printArray(int arr[],int size){
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
       printf("%d\t",arr[i]);
    }
}
int insertElement(int arr[], int size, int element, int position) {
    if (size >= arr_length) {
        printf("Array is full! Cannot insert.\n");
        return size;
    }
    
    if (position < 0 || position > size) {
        printf("Invalid position! Position should be between 0 and %d\n", size);
        return size;
    }
    
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    
    printf("Element %d inserted at position %d\n", element, position);
    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty! Cannot delete.\n");
        return size;
    }
    
    if (position < 0 || position >= size) {
        printf("Invalid position! Position should be between 0 and %d\n", size - 1);
        return size;
    }
    
    int deletedElement = arr[position];
    
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    printf("Element %d deleted from position %d\n", deletedElement, position);
    return size - 1;
}

int main() {
    int arr[arr_length];
    int size = 0;
    int choice, element, position;
    
    printf("Enter initial number of elements (max %d): ", arr_length);
    scanf("%d", &size);
    
    if (size > 0 && size <= arr_length) {
        printf("Enter %d elements:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }
    
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Traverse Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4.Print array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (size > 0) {
                    traverseArray(arr, size);
                } else {
                    printf("Array is empty!\n");
                }
                break;
                
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                size = insertElement(arr, size, element, position);
                break;
                
            case 3:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;
                
            case 4:
                printArray(arr,size);
                break;
            case 5: 
                printf("Exiting program... \n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}