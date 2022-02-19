//тут людей ебут
#include <stdlib.h>
#include <stdbool.h>

int *dijkstra_alg(int **a, int centr, int col)
{
    int *dist = calloc(col, sizeof(int));
    bool *visited = calloc(col, sizeof(bool));
    for (int i = 0; i < col; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[centr] = 0;
    int index = 0, u = 0;
    for (int coun = 0; coun < col; coun++)
    {
        int min = INT_MAX;
        for (int i = 0; i < col; i++)
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                index = i;
            }
        u = index;
        visited[u] = true;
        for (int i = 0; i < col; i++)
            if (!visited[i] && a[u][i] && a[u][i] != INT_MAX && dist[u] != INT_MAX && dist[u] + a[u][i] < dist[i])
                dist[i] = dist[u] + a[u][i];
    }
    return dist;
}