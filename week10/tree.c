#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


typedef struct {
    int data[MAX_SIZE];
    int size;
} Tree;

Tree* createTree() {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->size = 0;
    return tree;
}

int getParent(int idx) {
    if (idx == 0) return -1;
    return (idx - 1) / 2;
}

int getLeftChild(int idx) {
    int leftIdx = 2 * idx + 1;
    return (leftIdx < MAX_SIZE) ? leftIdx : -1;
}

int getRightChild(int idx) {
    int rightIdx = 2 * idx + 2;
    return (rightIdx < MAX_SIZE) ? rightIdx : -1;
}

void insertNode(Tree *tree, int value) {
    if (tree->size >= MAX_SIZE) {
        printf("Agac dolu! Daha fazla node eklenemez.\n");
        return;
    }
    tree->data[tree->size] = value;
    tree->size++;
    printf("%d degeri eklendi.\n", value);
}

void displayTree(Tree *tree) {
    if (tree->size == 0) {
        printf("Agac bos!\n");
        return;
    }
    
    printf("\nAgac Yapisi (Array Indisleri):\n");
    printf("Index | Deger | Parent | Sol Cocuk | Sag Cocuk\n");
    printf("------|-------|--------|-----------|----------\n");
    
    for (int i = 0; i < tree->size; i++) {
        int parent = getParent(i);
        int leftChild = getLeftChild(i);
        int rightChild = getRightChild(i);
        
        printf("  %d   |  %d   |", i, tree->data[i]);
        
        if (parent != -1) {
            printf("   %d   |", parent);
        } else {
            printf("  Yok  |");
        }
        
        if (leftChild != -1 && leftChild < tree->size) {
            printf("    %d     |", leftChild);
        } else {
            printf("   Yok   |");
        }
        
        if (rightChild != -1 && rightChild < tree->size) {
            printf("    %d\n", rightChild);
        } else {
            printf("   Yok\n");
        }
    }
}

void inOrderTraversal(Tree *tree, int idx, int depth) {
    if (idx >= tree->size) return;
    
    int leftChild = getLeftChild(idx);
    if (leftChild != -1 && leftChild < tree->size) {
        inOrderTraversal(tree, leftChild, depth + 1);
    }
    
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%d\n", tree->data[idx]);
    
    int rightChild = getRightChild(idx);
    if (rightChild != -1 && rightChild < tree->size) {
        inOrderTraversal(tree, rightChild, depth + 1);
    }
}

void preOrderTraversal(Tree *tree, int idx) {
    if (idx >= tree->size) return;
    
    printf("%d ", tree->data[idx]);
    
    int leftChild = getLeftChild(idx);
    if (leftChild != -1 && leftChild < tree->size) {
        preOrderTraversal(tree, leftChild);
    }
    
    int rightChild = getRightChild(idx);
    if (rightChild != -1 && rightChild < tree->size) {
        preOrderTraversal(tree, rightChild);
    }
}


void postOrderTraversal(Tree *tree, int idx) {
    if (idx >= tree->size) return;
    
    int leftChild = getLeftChild(idx);
    if (leftChild != -1 && leftChild < tree->size) {
        postOrderTraversal(tree, leftChild);
    }
    
    int rightChild = getRightChild(idx);
    if (rightChild != -1 && rightChild < tree->size) {
        postOrderTraversal(tree, rightChild);
    }
    
    printf("%d ", tree->data[idx]);
}


void levelOrderTraversal(Tree *tree) {
    if (tree->size == 0) return;
    
    for (int i = 0; i < tree->size; i++) {
        printf("%d ", tree->data[i]);
    }
}


int getHeight(Tree *tree, int idx) {
    if (idx >= tree->size) return -1;
    
    int leftChild = getLeftChild(idx);
    int rightChild = getRightChild(idx);
    
    int leftHeight = -1;
    int rightHeight = -1;
    
    if (leftChild != -1 && leftChild < tree->size) {
        leftHeight = getHeight(tree, leftChild);
    }
    
    if (rightChild != -1 && rightChild < tree->size) {
        rightHeight = getHeight(tree, rightChild);
    }
    
    int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return maxHeight + 1;
}

int countNodes(Tree *tree, int idx) {
    if (idx >= tree->size) return 0;
    
    int leftChild = getLeftChild(idx);
    int rightChild = getRightChild(idx);
    
    int count = 1;
    if (leftChild != -1 && leftChild < tree->size) {
        count += countNodes(tree, leftChild);
    }
    if (rightChild != -1 && rightChild < tree->size) {
        count += countNodes(tree, rightChild);
    }
    
    return count;
}


int main() {
    Tree *tree = createTree();
    
    printf("---- ARRAY TABANLI AGAC OLUSTURMA ----\n\n");
    
    printf("Nodlar ekleniyor:\n");
    insertNode(tree, 1);   
    insertNode(tree, 2);   
    insertNode(tree, 3);  
    insertNode(tree, 4);  
    insertNode(tree, 5);  
    insertNode(tree, 6); 
    insertNode(tree, 7);  
    
    displayTree(tree);
    
    printf("\n---- AGAC GEZILERI ----\n\n");
    
    printf("In-Order (Sol-Kok-Sag):\n");
    inOrderTraversal(tree, 0, 0);
    
    printf("\nPre-Order (Kok-Sol-Sag): ");
    preOrderTraversal(tree, 0);
    printf("\n");
    
    printf("Post-Order (Sol-Sag-Kok): ");
    postOrderTraversal(tree, 0);
    printf("\n");
    
    printf("Level-Order (Seviye Seviye): ");
    levelOrderTraversal(tree);
    printf("\n");
    
    printf("\n---- AGAC BILGILERI ----\n");
    printf("Agacin Yuksekligi: %d\n", getHeight(tree, 0));
    printf("Toplam Node Sayisi: %d\n", countNodes(tree, 0));
    printf("Root Node Degeri: %d\n", tree->data[0]);
    
    printf("\n---- SPESIFIK NODE BILGILERI ----\n");
    int idx = 1;
    printf("\nIndex %d icin (Node %d):\n", idx, tree->data[idx]);
    printf("  Parent: Index %d", getParent(idx));
    if (getParent(idx) != -1) printf(" (Deger: %d)", tree->data[getParent(idx)]);
    printf("\n");
    
    int left = getLeftChild(idx);
    printf("  Sol Cocuk: Index %d", left);
    if (left != -1 && left < tree->size) printf(" (Deger: %d)", tree->data[left]);
    printf("\n");
    
    int right = getRightChild(idx);
    printf("  Sag Cocuk: Index %d", right);
    if (right != -1 && right < tree->size) printf(" (Deger: %d)", tree->data[right]);
    printf("\n");
    
    free(tree);
    return 0;
}