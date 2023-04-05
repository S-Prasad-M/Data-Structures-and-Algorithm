#include<stdio.h>
#include<conio.h>
int main()
{
    int size;
    printf("Enter size of the stack: ");
    scanf("%d",&size);
    int stack[size]; int top = -1;
    while(1)
    {
        int choice, item;
        printf("***********************************************\n");
        printf("1.Push \n2.Pop \n3.Display \n4.Exit \nEnter the choice: ");
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
                for(int i =0; i<=top; i++)
                {
                    printf("%d\t",stack[i] );
                }
            }
            break;
        default:
            printf("Thank you for using stack\n");
            return 0;
        }
        printf("\n***********************************************\n");
    }
}
