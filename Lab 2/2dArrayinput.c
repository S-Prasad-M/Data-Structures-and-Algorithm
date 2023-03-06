#include<stdio.h>
int main()
{
    int row, col, i, j;
    printf("Enter row and column");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Enter array [%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
            printf("\n");
        }
        
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("Array[%d][%d] = %d",i, j, arr[i][j]);
    }
    return 0;
}