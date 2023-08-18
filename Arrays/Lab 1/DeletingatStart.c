#include<stdio.h> 
int main() 
{ 
    int n,arr[10];
    printf("Enter the size of the array: ");
    scanf("%d" ,&n);
    printf("Enter elements in an array: ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    n--;
    for(int i=0;i<n;i++) 
        arr[i]=arr[i+1]; 
    printf("\nAfter deletion: ");
    for(int i=0;i<n;i++) 
        printf("\t%d", arr[i]);
}