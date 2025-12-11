#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;  
    struct Node* next;  
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        printf("Added %d at end (first node)\n", data);
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    
    printf("Added %d at end\n", data);
    return head;
}

struct Node* deleteAllRecursive(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    head->next = deleteAllRecursive(head->next);
    
    printf("Deleting node with data: %d\n", head->data);
    free(head);
    
    return NULL;
}

struct Node* deleteAll(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }
    
    printf("Deleting all elements recursively...\n");
    head = deleteAllRecursive(head);
    printf("All elements deleted!\n");
    return NULL;
}

struct Node* addBetween(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        printf("Added %d at position %d\n", data, position);
        return newNode;
    }
    
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    
    printf("Added %d at position %d (between elements)\n", data, position);
    return head;
}

void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List (forward): NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("List (backward): NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" -> NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("=== DOUBLE LINKED LIST OPERATIONS ===\n");
    printf("This program demonstrates:\n");
    printf("1. Adding element at END\n");
    printf("2. Deleting ALL elements RECURSIVELY\n");
    printf("3. Adding element BETWEEN elements\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add element at END\n");
        printf("2. Add element BETWEEN (at position)\n");
        printf("3. Delete ALL elements (Recursively)\n");
        printf("4. Traverse forward\n");
        printf("5. Traverse backward\n");
        printf("6. Count nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = addAtEnd(head, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = addBetween(head, data, position);
                break;
                
            case 3:
                head = deleteAll(head);
                break;
                
            case 4:
                traverseForward(head);
                break;
                
            case 5:
                traverseBackward(head);
                break;
                
            case 6:
                printf("Total nodes: %d\n", countNodes(head));
                break;
                
            case 7:
                printf("Exiting program...\n");
                if (head != NULL) {
                    head = deleteAll(head);
                }
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}