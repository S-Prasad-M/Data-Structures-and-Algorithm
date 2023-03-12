#include<stdio.h>
int main()
{
    int n,i,pos,item;
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
    printf("\nEnter the element and the position: ");
    scanf("%d %d", &item, &pos);
    for (int i = n; i >= pos - 1; i--) 
        array[i+1] = array[i]; 
    array[pos-1] = item;
    printf("Updated Array:");
    for(i=0;i<n+1;i++) 
    { 
        printf("\t%d", array[i]); 
    }
}