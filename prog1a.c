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