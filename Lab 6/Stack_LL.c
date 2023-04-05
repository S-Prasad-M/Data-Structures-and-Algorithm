#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push()
{
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        if (top == NULL)
        {
            node->next = NULL;
        }
        else
        {
            node->next = top;
        }
        top = node;
}

void Pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow");
        return;
    }
    else 
    {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

void Display()
{
    struct Node* temp = top;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, flow=1;

    while (flow)
    {
        printf("\n*******************************************************\n");
        printf("Stack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Program terminated\n");
                flow=0;
                break;
        }
        printf("\n*******************************************************\n");
    }

    return 0;
}