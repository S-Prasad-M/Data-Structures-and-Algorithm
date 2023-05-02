#include <stdio.h>
#include<stdlib.h>
int MAX = 100;
int queue[100];
int rear = - 1;
int front = - 1;
void insert();
void delete();
void display();
void main()
{
    int choice;
    while (1)
    {
        printf("******************************************************************************\n");
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit  \nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
        printf("******************************************************************************\n");
    }
}
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        {
            front = 0;   
        }
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue[rear] = add_item;
    }
}
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is: %d\n", queue[front]);
        for(int i=0;i<rear;i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
