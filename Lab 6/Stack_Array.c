#include<stdio.h>
#include<conio.h>
void display(int arr[], int top)
{
    int i = top;
    while (i>=0)
    {
        printf("%d \t", arr[i]);
        i--;
    }
}


int main()
{
    int size, i, j;
    printf("Enter size of the stack: ");
    scanf("%d",&size);
    int stack[size]; int top = -1; int temp;
    int revstack[size];
    while(1)
    {
        int choice, item;
        printf("***********************************************\n");
        printf("1.Push \n2.Pop \n3.Display \n4.Reverse \n5.Sort  \n6.Exit  \nEnter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if (top == size-1)
            {
                printf("Stack is full. Cannot push more items.\n");
            }
            else
            {
                printf("Enter element to push into stack: ");
                scanf("%d", &item);
                top++;
                stack[top] = item;
            }
            break;
        case 2:
            if(top==-1)
            {
                printf("Stack is already empty");
            }
            else
            {
                printf("Popped element: %d", stack[top]);
                top--;
            }
            break;
        case 3:
            if (top==-1)
            {
                printf("Stack is empty\n");
            }
            else{
                display(stack,top);
            }
            break;
        case 4:
            i = top;
            j=0;
            while (i>=0)
            {
                revstack[j]=stack[i];
                i--;j++;
            }
            display(revstack,top);
            break;
        case 5:
            for(i=0;i<top-1;i++)
            {
                for(j=0;j<top-i-1;j++)
                {
                    if(stack[i]>stack[j])
                    {
                        temp = stack[i];
                        stack[i] = stack[j];
                        stack[j] = temp;
                    }
                }
            }
            printf("After Sorting... \t");
            display(stack, top);
            break;
        default:
            printf("Thank you for using stack\n");
            return 0;
        }
        printf("\n***********************************************\n");
    }
}
