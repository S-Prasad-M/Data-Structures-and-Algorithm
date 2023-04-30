#include<stdio.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
int i,count = 0;

void insert_queue()
{
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
    }
    head = temp;
    count++;
}

void delete_queue()
{
    if (head==NULL)
    {
        printf("Underflow error");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        struct Node* temp = head;
        struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
        while (temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("%d removed from queue",temp->data);
        free(temp);
    }
}

void display()
{
    struct Node* temp1 = head;
    while(temp1 != NULL)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->next;
    }
}

int main()
{
    int choice, flow=1;
    while (flow)
    {
        printf("\n*******************************************************\n");
        printf("1.Add to queue \n2.Delete queue \n3.Display \n4.Exit \nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_queue();
                break;
            case 2:
                delete_queue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Terminated \n");
                flow = 0;
                break;
        }
        printf("\n*********************************************************\n");
    }
}
