#include<stdio.h>
void main()
{
    int row, col, i, j, sum = 0;
    printf("Enter row and column");
    scanf("%d %d", &row, &col);
    int arr[row][col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Enter array [%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
            sum += arr[i][j]; 
            printf("\n");
        }
    }
    printf("Sum of all elements in the 2d array = %d", sum);
}
