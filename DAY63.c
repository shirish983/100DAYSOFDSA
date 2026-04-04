#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix (simpler for exam)
int visited[MAX];
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m, u, v, s;

    // Input vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove for directed graph
    }

    // Initialize visited
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Starting vertex
    scanf("%d", &s);

    // Call DFS
    dfs(s);

    return 0;
}
