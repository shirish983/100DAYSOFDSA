#include <stdio.h>

int graph[101][101], visited[101], n, m;

void dfs(int node) {
    visited[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(graph[node][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
