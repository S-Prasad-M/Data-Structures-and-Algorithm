#include<stdio.h>
int main()
{
    int n,i, item;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int array[n+1];
    printf("\nEnter Elements in array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    for(i=0;i<n;i++) 
    { 
        printf("\t%d", array[i]); 
    }
    printf("\nenter the element at the end: ");
    scanf("%d", &array[n]); 
    printf("Updated Array:");
    for(i=0;i<n+1;i++) 
    { 
        printf("\t%d", array[i]); 
    }
}