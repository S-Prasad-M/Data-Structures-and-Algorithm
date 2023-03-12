#include<stdio.h>
void main()
{
    int row, col, i, j, item;
    printf("Enter row and column");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Enter array [%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter new element to be updated at which position i and j: ");
    scanf("%d %d %d", &item, &i, &j);
    arr[i][j]= item;
    printf("After updation: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d\t",arr[i][j]);
        printf("\n");
    }
}