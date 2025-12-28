#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

bool isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}


typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack *s, int value) {
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    return s->items[s->top--];
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

typedef struct {
    int vertices;
    int **adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1; 
}

void dfsIterative(Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Stack *stack = createStack();
    
    push(stack, startVertex);
    visited[startVertex] = true;
    
    while (!isStackEmpty(stack)) {
        int vertex = pop(stack);
        printf("%d ", vertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
                push(stack, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
    free(stack);
}


void bfs(Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Queue *queue = createQueue();
    
    enqueue(queue, startVertex);
    visited[startVertex] = true;
    
    while (!isQueueEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
    free(queue);
}

int main() {
    Graph *graph = createGraph(6);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    printf("GRAPH YAPISI: \n");
    printf("Koseler: 0, 1, 2, 3, 4, 5\n");
    printf("Kenarlar: (0-1), (0-2), (1-3), (2-4), (3-5), (4-5)\n\n");
    
    printf("\n\n");
    
    printf("DFS: \n");
    dfsIterative(graph, 0);
    printf("\n");
    
    printf("BFS: \n");
    bfs(graph, 0);
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
    
    return 0;
}