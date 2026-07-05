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






#include <stdio.h>

#define INFINITY 999 
#define MAX 10 

struct EDGE
{ 
    int x, y, wt; 
} e[MAX];

int parent[MAX];
int cost[MAX][MAX];
int t[MAX][3];
int nedges = 0;
int eno;

void sort_edges()
{ 
    int i, j; 
    struct EDGE temp; 
    for(i = 1; i < nedges; i++)
    {
        for(j = 1; j <= nedges - i; j++)
        {
            if(e[j].wt > e[j+1].wt)
            { 
                temp = e[j]; 
                e[j] = e[j+1]; 
                e[j+1] = temp; 
            } 
        }
    }
} 

int get_parent(int v)
{ 
    while(parent[v]) 
        v = parent[v]; 
    return v; 
} 

void join(int i, int j)
{ 
    parent[j] = i; 
} 

void kruskal(int n)
{ 
    int i, j, k, sum = 0; 
    int current_edge = 1; 
    struct EDGE nextedge; 

    for(k = 1; k < n; )
    { 
        nextedge = e[current_edge++]; 
        i = get_parent(nextedge.x); 
        j = get_parent(nextedge.y); 

        if(i != j)
        { 
            join(i, j); 
            t[k][1] = nextedge.x; 
            t[k][2] = nextedge.y; 
            sum = sum + nextedge.wt; 
            k++; 
        } 
    } 

    printf("\nCost of the spanning tree is: %d\n", sum); 
    printf("\nThe edges of the spanning tree are:\n"); 
    for(i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][1], t[i][2]);
} 

int main()
{ 
    int i, j, n; 

    printf("\nEnter the no. of vertices: "); 
    scanf("%d", &n); 

    for(i = 1; i <= n; i++) 
        parent[i] = 0; 

    int edge_count = 1; 
    printf("\nEnter the cost adjacency matrix: 0 = self loop & 999 = no edge\n"); 
    for(i = 1; i <= n; i++)
    { 
        for(j = 1; j <= n; j++)
        { 
            scanf("%d", &cost[i][j]); 
            if(i >= j || cost[i][j] == INFINITY || cost[i][j] == 0) 
                continue; 

            e[edge_count].x = i; 
            e[edge_count].y = j; 
            e[edge_count].wt = cost[i][j]; 
            edge_count++; 
            nedges++; 
        } 
    } 

    sort_edges(); 
    kruskal(n); 

    return 0; 
}
