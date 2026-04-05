#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Visited array
int visited[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Enqueue
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void BFS(struct Node* adj[], int n, int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[MAX];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph, also add v -> u
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(adj, n, start);

    return 0;
}
