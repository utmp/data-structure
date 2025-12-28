#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

int parentIdx(int i) {
    return (i - 1) / 2;
}

int leftChildIdx(int i) {
    return 2 * i + 1;
}

int rightChildIdx(int i) {
    return 2 * i + 2;
}

void swapMax(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUpMax(MaxHeap *heap, int idx) {
    if (idx > 0 && heap->arr[parentIdx(idx)] < heap->arr[idx]) {
        swapMax(&heap->arr[idx], &heap->arr[parentIdx(idx)]);
        heapifyUpMax(heap, parentIdx(idx));
    }
}

void heapifyDownMax(MaxHeap *heap, int idx) {
    int largest = idx;
    int left = leftChildIdx(idx);
    int right = rightChildIdx(idx);

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != idx) {
        swapMax(&heap->arr[idx], &heap->arr[largest]);
        heapifyDownMax(heap, largest);
    }
}

void insertMaxHeap(MaxHeap *heap, int key) {
    if (heap->size >= heap->capacity) {
        printf("Heap dolu!\n");
        return;
    }
    heap->arr[heap->size] = key;
    heapifyUpMax(heap, heap->size);
    heap->size++;
}

int extractMaxHeap(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap bos!\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMax(heap, 0);
    return max;
}


typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swapMin(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUpMin(MinHeap *heap, int idx) {
    if (idx > 0 && heap->arr[parentIdx(idx)] > heap->arr[idx]) {
        swapMin(&heap->arr[idx], &heap->arr[parentIdx(idx)]);
        heapifyUpMin(heap, parentIdx(idx));
    }
}

void heapifyDownMin(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = leftChildIdx(idx);
    int right = rightChildIdx(idx);

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swapMin(&heap->arr[idx], &heap->arr[smallest]);
        heapifyDownMin(heap, smallest);
    }
}

void insertMinHeap(MinHeap *heap, int key) {
    if (heap->size >= heap->capacity) {
        printf("Heap dolu!\n");
        return;
    }
    heap->arr[heap->size] = key;
    heapifyUpMin(heap, heap->size);
    heap->size++;
}

int extractMinHeap(MinHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap bos!\n");
        return -1;
    }
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDownMin(heap, 0);
    return min;
}

void printHeap(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    printf("---- MAX HEAP ORNEGI ----\n");
    MaxHeap *maxHeap = createMaxHeap(10);
    
    int values[] = {15, 10, 20, 8, 2, 25, 30};
    for (int i = 0; i < 7; i++) {
        insertMaxHeap(maxHeap, values[i]);
    }
    
    printf("Max Heap: ");
    printHeap(maxHeap->arr, maxHeap->size);
    
    printf("En buyuk element cikis sirasiyla:\n");
    while (maxHeap->size > 0) {
        printf("%d ", extractMaxHeap(maxHeap));
    }
    printf("\n\n");

    printf("---- MIN HEAP ORNEGI ----\n");
    MinHeap *minHeap = createMinHeap(10);
    
    for (int i = 0; i < 7; i++) {
        insertMinHeap(minHeap, values[i]);
    }
    
    printf("Min Heap: ");
    printHeap(minHeap->arr, minHeap->size);
    
    printf("En kucuk element cikis sirasiyla:\n");
    while (minHeap->size > 0) {
        printf("%d ", extractMinHeap(minHeap));
    }
    printf("\n");

    free(maxHeap->arr);
    free(maxHeap);
    free(minHeap->arr);
    free(minHeap);

    return 0;
}