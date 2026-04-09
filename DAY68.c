#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];
int V;

// Queue implementation
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++;  // increase in-degree
}

// Kahn's Algorithm
void topologicalSort() {
    int count = 0;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order:\n");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0) {
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }

    // If count != V → cycle exists
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    V = 6;

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort();

    return 0;
}
