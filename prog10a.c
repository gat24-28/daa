#include <stdio.h> 
#include <stdlib.h> 

void prims(int cost[10][10], int n) 
{ 
    int a, b, i, j, visited[10], mincost = 0, u, v, min, ne = 1; 
    for(i = 1; i <= n; i++) 
        visited[i] = 0; 

    printf("\nThe edges of the minimum spanning tree \n "); 
    visited[1] = 1; 

    while(ne < n) 
    { 
        for(i = 1, min = 999; i <= n; i++) 
        { 
            for(j = 1; j <= n; j++) 
            { 
                if(cost[i][j] < min) 
                { 
                    min = cost[i][j]; 
                    a = u = i; 
                    b = v = j; 
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0) 
        {
            printf("\n%d Edge(%d,%d) = %d", ne++, a, b, min); 
            mincost = mincost + min; 
            visited[v] = 1; 
        }
        cost[a][b] = cost[b][a] = 999; 
    }
    printf("\nMinimum total cost = %d\n", mincost); 
}

int main() 
{
    int n, i, j, cost[10][10]; 
    printf("\nRead number of nodes: "); 
    scanf("%d", &n); 
    printf("\nRead cost matrix\n"); 

    for(i = 1; i <= n; i++) 
    {
        for(j = 1; j <= n; j++) 
        {
            scanf("%d", &cost[i][j]); 
            if(cost[i][j] == 0) 
                cost[i][j] = 999; 
        }
    }

    prims(cost, n); 
    return 0; 
}
