#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newNode->next = head;
    temp->next = newNode;
    return newNode; 
}

Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertAtPosition(Node *head, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    Node *temp = head;
    int count = 1;
    
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node *head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    
    if (head->next == head) {  
        free(head);
        return NULL;
    }
    
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    Node *toDelete = head;
    temp->next = head->next;
    head = head->next;
    
    printf("%d silindi.\n", toDelete->data);
    free(toDelete);
    return head;
}

Node* deleteFromEnd(Node *head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    
    if (head->next == head) {
        free(head);
        return NULL;
    }
    
    Node *temp = head;
    Node *prev = NULL;
    
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = head;
    printf("%d silindi.\n", temp->data);
    free(temp);
    return head;
}

Node* deleteAtPosition(Node *head, int position) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    
    Node *temp = head;
    Node *prev = NULL;
    int count = 1;
    
    while (count < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    
    if (count != position) {
        printf("Gecersiz konum!\n");
        return head;
    }
    
    prev->next = temp->next;
    printf("%d silindi.\n", temp->data);
    free(temp);
    return head;
}

Node* deleteByValue(Node *head, int value) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    
    if (head->data == value) {
        return deleteFromBeginning(head);
    }
    
    Node *temp = head;
    Node *prev = NULL;
    
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);
    
    if (temp == head) {
        printf("%d bulunamadi!\n", value);
        return head;
    }
    
    prev->next = temp->next;
    printf("%d silindi.\n", temp->data);
    free(temp);
    return head;
}

void traversalForward(Node *head, int times) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }
    
    Node *temp = head;
    printf("Ileri Traversal: ");
    
    for (int i = 0; i < times; i++) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("...\n");
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }
    
    Node *temp = head;
    printf("Liste: ");
    
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("HEAD\n");
}

void freeList(Node *head) {
    if (head == NULL) return;
    
    Node *temp = head;
    Node *next;
    
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
}

int main() {
    Node *head = NULL;
    
    printf("===== CEMBERSEL LINKED LIST =====\n\n");
    
    printf("--- EKLEME ISLEMLERI ---\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    displayList(head);
    
    printf("\nBasina 5 ekle:\n");
    head = insertAtBeginning(head, 5);
    displayList(head);
    
    printf("\n2. konuma 15 ekle:\n");
    head = insertAtPosition(head, 15, 2);
    displayList(head);
    
    printf("\n--- TRAVERSAL ---\n");
    traversalForward(head, 10);
    
    printf("\n--- SILME ISLEMLERI ---\n");
    printf("\nBasindan sil:\n");
    head = deleteFromBeginning(head);
    displayList(head);
    
    printf("\nSonundan sil:\n");
    head = deleteFromEnd(head);
    displayList(head);
    
    printf("\n3. konumdan sil:\n");
    head = deleteAtPosition(head, 3);
    displayList(head);
    
    printf("\nDegeri 20 olan elementi sil:\n");
    head = deleteByValue(head, 20);
    displayList(head);
    
    freeList(head);
    
    return 0;
}