#include<stdio.h>

int count;
int partition(int a[10], int low, int high)
{
    int i, j, pivot, temp;
    i = low+1;
    j = high;
    pivot = a[low];
    while(1)
    {
        while(pivot>=a[i] && i<=high)
        {
            i++;
            count++;
        }
        count++;
        while(pivot<a[j] && j>=low)
        {
            j--;
            count++;
        }
        count++;
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[10], int low, int high)
{
    int i, j;
    if(low<=high)
    {
        j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}

int main()
{
    int i;
    int a[10];

    printf("Enter 10 elements:\n");
    for(int i=1; i<=10; i++)
        scanf("%d", &a[i]);

    quicksort(a, 1, 10);
    printf("Elements after sorting:\n");
    for(int i=1; i<=10; i++)
        printf("%d\t", a[i]);

    printf("\nNumber of counts: %d\n", count);
    return 0;
}