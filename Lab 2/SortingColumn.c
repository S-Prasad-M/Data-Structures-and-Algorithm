#include<stdio.h>
void main()
{
    int row, col, i, j, k;
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
        {
            for(k=0;k<col; k++)
            {
                if(arr[i][j]<arr[k][j])
                {
                int temp = arr[k][j];
                arr[k][j] = arr[i][j];
                arr[i][j] = temp;
                }
            }
        }
    }
    printf("Sorted Array: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d\t",arr[i][j]);
        printf("\n");
    }
    return 0;
}
