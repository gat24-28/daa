#include<stdio.h>
#include<string.h>

void naiveStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0; i<=n-m; i++)
    {
        int j = 0;

        while(j<m && text[i+j] == pattern[j])
            j++;
            
        if(j==m)
            printf("Pattern match found at index %d\n", i);
    }
}

int main()
{
    char text[20], pattern[10];
    printf("Enter the text: ");
    scanf("%s", text);
    
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    naiveStringMatch(text, pattern);

    return 0; 
}



#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
    while (left<=right)
    {
        int mid = left + (right-left)/2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of the array:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key element: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n-1, key);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}



#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
    if(left<=right)
    {
        int mid = left + (right-left)/2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            return binarySearch(arr, mid+1, right, key);
        else
            return binarySearch(arr, left, mid-1, key);
    }

    return -1;
}

int main()
{
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of the array:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key element: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n-1, key);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}
