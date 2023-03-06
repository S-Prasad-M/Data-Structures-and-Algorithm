#include<stdio.h>
int main()
{
    int n,i, item;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter Elements in array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    for(i=0;i<n;i++) 
    { 
        printf("\t%d", array[i]); 
    }
    printf("\n enter the element at the beginning");
    scanf("%d", &item); 
    n++;
    for(i=n-1; i>=0; i--) 
    {
        array[i-1]=array[i-2]; 
    }
    array[0]=item; 
    printf("resultant array element"); 
    for(i=0;i<n;i++) 
    { 
        printf("\t%d", array[i]); 
    }
    return 0; 
}