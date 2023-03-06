#include<stdio.h>
int main()
{
    int n,i, item;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int array[n+1];
    printf("\nEnter Elements in array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter element to find:");
    scanf("%d",&item);
    for(int i=0; i<n;i++)
    {
        if(array[i]==item)
        {
            printf("Position of found element= %d", i+1);
            break;
        }
    }
    return 0;
}