#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at front\n", data);
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        printf("Inserted %d at end (first node)\n", data);
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    printf("Inserted %d at end\n", data);
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    if (position == 1) {
        return insertAtFront(head, data);
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
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
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
    return head;
}

struct Node* deleteFromFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from front\n", temp->data);
    free(temp);
    return head;
}


struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        return NULL;
    }
    
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    if (position < 1) {
        printf("Invalid position! Position should be >= 1\n");
        return head;
    }
    
    if (position == 1) {
        return deleteFromFront(head);
    }
    
    struct Node* temp = head;
    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d\n", nodeToDelete->data, position);
    free(nodeToDelete);
    return head;
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

void displayComplexity() {
    printf("\n=== TIME COMPLEXITY OF OPERATIONS ===\n");
    printf("1. Traverse List: O(n)\n");
    printf("2. Insert at Front: O(1)\n");
    printf("3. Insert at End: O(n)\n");
    printf("4. Insert at Position: O(n)\n");
    printf("5. Delete from Front: O(1)\n");
    printf("6. Delete from End: O(n)\n");
    printf("7. Delete from Position: O(n)\n");
    printf("=====================================\n\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Create/Add element at end\n");
        printf("2. Insert at front\n");
        printf("3. Insert at position\n");
        printf("4. Insert at end\n");
        printf("5. Delete from front\n");
        printf("6. Delete from end\n");
        printf("7. Delete from position\n");
        printf("8. Traverse list\n");
        printf("9. Count nodes\n");
        printf("10. Display time complexity\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
                
            case 5:
                head = deleteFromFront(head);
                break;
                
            case 6:
                head = deleteFromEnd(head);
                break;
                
            case 7:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
                
            case 8:
                traverseList(head);
                break;
                
            case 9:
                printf("Total nodes: %d\n", countNodes(head));
                break;
                
            case 10:
                displayComplexity();
                break;
                
            case 11:
                printf("Exiting program...\n");
                while (head != NULL) {
                    head = deleteFromFront(head);
                }
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}