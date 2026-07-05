#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void bfs(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX]={0};
    int queue[MAX];
    int front=1,rear=1;

    visited[start]=1;
    queue[rear++]=start;
    while(front<rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for(int i=1;i<=n;i++)
        {
            if(graph[current][i]==1 && !visited[i])
            {
                visited[i] = start;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int n, i, j, graph[MAX][MAX], start;
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            scanf("%d",&graph[i][j]);
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Nodes reachable from vertex %d using bfs:\n", start);
    bfs(graph, n, start);
    return 0;
}