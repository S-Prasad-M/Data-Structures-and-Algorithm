#include<stdio.h>
#include<stdlib.h>

int ROW;
int COL;
int **create(int i, int j) {
    int **arr = malloc(i * sizeof(int *));
    for (int a = 0; a < i; a++) {
        arr[a] = malloc(j * sizeof(int));
        for (int b = 0; b < j; b++) {
            printf("Enter value of arr[%d][%d]: ", a, b);
            scanf("%d", &arr[a][b]);
        }
    }
    return arr;
}

int **create_empty(int i, int j) {
    int **arr = malloc(i * sizeof(int *));
    for (int a = 0; a < i; a++) {
        arr[a] = malloc(j * sizeof(int));
    }
    return arr;
}

void display(int** arr){
    printf("\n");
    for(int i =0; i<ROW;i++){
        for(int j = 0;j<COL;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** delete(int**arr,int row, int col){
    arr[row][col] = 0;
    return arr;
}

int** update(int**arr,int row, int col, int val){
    arr[row][col] = val;
    return arr;
}

int** delete_row(int **arr,int row){
    int ** arr1 = create_empty(ROW-1,COL);
    for(int i =0;i<ROW;i++){
        if(i<row){
            arr1[i] = arr[i];
        }
        if(i>row){
            arr1[i-1] = arr[i];
        }
    }
    ROW--;
    free(arr);
    return arr1;
}

int** insert_row(int **arr,int row_insert){
    int ** arr1 = create_empty(ROW+1,COL);
    for(int i = 0;i<ROW+1;i++){
        if(i<row_insert){
            arr1[i] = arr[i];
        }
        else if(i == row_insert){
            for(int j = 0;j<COL;j++){
                printf("Enter the value for index arr[%d][%d] : ",i,j);
                scanf("%d",&arr1[i][j]);
            }
        }
        else{
            arr1[i] = arr[i-1];
        }
    }
    ROW++;
    free(arr);
    return arr1;
}

int sum(int ** arr){
    int sum =0;
    for(int i =0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            sum += arr[i][j];
        }
    }
    return sum;
}

int** sort_row(int** arr){
    for(int i = 0;i<ROW;i++){
        for(int j = 0 ;j<ROW-i-1;j++){
            if(arr[j][0] > arr[j+1][0]){
                int *temp = arr[j];
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            }
        }
    }
    return arr;
}

int** sort(int** arr){
    for(int i = 0;i<ROW;i++){
        for(int a = 0; a<COL; a++){
            for(int b = 0 ;b<COL-a-1;b++){
                if(arr[i][b] > arr[i][b+1]){
                    int tmp = arr[i][b];
                    arr[i][b] = arr[i][b+1];
                    arr[i][b+1] = tmp;
                }
            }
        }
    }
    return arr;
}

int** complete_sort(int** arr){
    arr = sort(arr);
    arr = sort_row(arr);
    return arr;
}

int** insert_col(int** arr,int index){
    int** arr1 = create_empty(ROW, COL+1);
    for(int i = 0; i<ROW;i++){
        for(int j = 0;j<COL+1;j++){
            if(j<index){
                arr1[i][j] = arr[i][j];
            }
            else if(j==index){
                printf("Enter the value for index arr[%d][%d] : ",i,j);
                scanf("%d",&arr1[i][j]);
            }
            else{
                arr1[i][j]  =  arr[i][j-1];
            }
        }
    }
    COL++;
    free(arr);
    return arr1;
}

int** delete_col(int** arr, int index){
    int** arr1 = create_empty(ROW, COL-1);
    for(int i = 0;i<ROW;i++){
        for(int j = 0; j<COL;j++){
            if(j<index){
                arr1[i][j] = arr[i][j];
            }
            else if(j>index){
                arr1[i][j-1] = arr[i][j];
            }
        }
    }
    COL--;
    free(arr);
    return arr1;
}

int demo(){
    int i , j;

    printf("Enter no of row : ");
    scanf("%d",&ROW);
    printf("Enter no of col : ");
    scanf("%d",&COL);

    int **arr = create(ROW,COL);
    display(arr);
    // arr = delete(arr,1,1);
    // display(arr);
    // arr = update(arr,1,1,999);
    // arr = delete_row(arr,1);
    arr = insert_col(arr,1);
    display(arr);
    // printf("%d",sum(arr));
    // arr = complete_sort(arr);
    arr = delete_col(arr,1);

    display(arr);
}

int main(){
//  creation of menu;
    int len,val,r_index,c_index;
    printf("Creating array\nenter number of row of 2-D array : ");
    scanf("%d",&ROW);
    printf("enter number of column of 2-D array : ");
    scanf("%d",&COL);
    printf("\n\n");
    int** arr = create(ROW,COL);
    int option,exit_status = 0;
    // printf("%d\n",len(head));
    do{
        printf("\nSelect the below option:\n\n");
        printf("1.display the array\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.dimension of array\n");
        printf("5.sort array\n");
        printf("6.update\n");
        printf("7.sum of array\n");
        printf("8.exit\n\nEnter Your option:");
        scanf("%d",&option);
        printf("\n*********************************************\n");
        int index,val;
        switch (option)
        {
        case 1:
            display(arr);
            break;
        case 2:
            printf("\n1.insertion of Row\n");
            printf("\n2.insertion of Col\n\n");
            scanf("%d",&option);
            printf("\nEnter the index of inserting : ");
            scanf("%d",&index);
            if(option == 1){
                arr = insert_row(arr,index);
            }
            else if(option == 2){
                arr = insert_col(arr,index);
            }
            break;
        case 3:
            printf("\n1.Deletion of Row\n");
            printf("\n2.Deletion of Col\n\n");
            scanf("%d",&option);
            printf("\nEnter the index of Deletion : ");
            scanf("%d",&index);
            if(option == 1){
                arr = delete_row(arr,index);
            }
            else if(option == 2){
                arr = delete_col(arr,index);
            }
            break;
        case 4:
            printf("\nThe dimension of array is %d x %d\n",ROW,COL);
            break;
        case 5:
            printf("\n\n1.Sort by  Row\n");
            printf("\n2.sort by column\n");
            printf("\n3.total sort\n\n");
            scanf("%d",&option);
            if(option == 1){
                arr = sort_row(arr);
            }
            else if(option == 2){
                arr = sort(arr);
            }
            else if(option == 3){
                arr = complete_sort(arr);
            }
            break;
        case 6:
            printf("Enter the index of updating : ");
            scanf("%d %d",&r_index,&c_index);
            printf("Enter the value for updating : ");
            scanf("%d",&arr[r_index][c_index]);
            break;
        case 7:
            printf("Sum of all element is : %d",sum(arr));
            break;
        case 8:
            printf("exiting.....\n");
            exit_status = 1;
            break;
        default:
            printf("enter the valid option\n");
            break;
        }
        printf("\n*********************************************\n");
    }
    while(exit_status != 1);
    return 0;
}  
