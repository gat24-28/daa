#include<stdio.h>
#include<stdlib.h>

void dfs (int arr[10][10], int n, int v[10], int source)
{
    int i;
    v[source] = 1;
    for(i=1; i<=n; i++)
    {
        if(v[i] == 0 && arr[source][i] == 1 || arr[i][source] == 1)
            dfs(arr, n, v, i);  
    }
}

int main()
{
    int a[10][10], n, v[10], i, j, count = 0, flag = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    
    for(i=1; i<=n; i++)
        v[i] = 0;

    for(i=1; i<=n; i++)
    {
        if(v[i] == 0)
        {
            dfs(a, n, v, i);
            count++;
        }
    }
        
    if(count == 1)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected with %d comparisons\n", count);

    return 0;
} 