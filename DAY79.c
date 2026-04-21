#include <stdio.h>

#define INF 1000000

int main() {
    int n, m;
    int graph[101][101];
    int selected[101] = {0};
    int minEdge[101];
    int total = 0;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for(int i = 1; i <= n; i++)
        minEdge[i] = INF;

    minEdge[1] = 0;

    for(int count = 1; count <= n; count++) {
        int u = -1, min = INF;

        for(int i = 1; i <= n; i++) {
            if(!selected[i] && minEdge[i] < min) {
                min = minEdge[i];
                u = i;
            }
        }

        selected[u] = 1;
        total += minEdge[u];

        for(int v = 1; v <= n; v++) {
            if(!selected[v] && graph[u][v] < minEdge[v])
                minEdge[v] = graph[u][v];
        }
    }

    printf("%d", total);

    return 0;
}
