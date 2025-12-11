#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 10 

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES]; 
int numVertices = 9;

void initGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void dfs(int startNode) {
    visited[startNode] = true;

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[startNode][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

bool checkConnection(int startNode, int endNode) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    dfs(startNode);

    return visited[endNode];
}

int main() {
    initGraph();
    addEdge(0, 1); // v1 <-> v2
    addEdge(1, 2); // v2 <-> v3
    addEdge(1, 3); // v2 <-> v4
    addEdge(2, 3); // v3 <-> v4
    addEdge(2, 4); // v3 <-> v5
    addEdge(3, 4); // v4 <-> v5

    addEdge(5, 6); // v6 <-> v7
    addEdge(5, 7); // v6 <-> v8
    addEdge(5, 8); // v6 <-> v9
    addEdge(6, 7); // v7 <-> v8
    addEdge(7, 8); // v8 <-> v9

    int n1,n2;
    printf("Enter number to check connection between vertices\n");
    printf("vertice one: ");
    scanf("%d",&n1);
    printf("vertice two: ");
    scanf("%d",&n2);
    bool result = checkConnection(n1,n2);
    printf("connection status is %s", result ? "true" : "false");
    return 0;
}