#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *
    link;
};

void create(int num, struct node *head)
{
    struct node *temphead = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    while(temphead->link != NULL)
    {
        temphead = temphead->link;
    }
    temphead->link = temp;
    temp->data = num;
    temp->link = NULL;
}

int main()
{
    int choice;
    int num, len;
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    // printf("1.Create \n2. Insert \n3. Delete \n4.Display \n Enter Choice: ");
    // scanf("%d", &choice);
    while (1)
    {
    printf("1.Create \n2. Insert \n3. Delete \n4.Display \n Enter Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter number of nodes:");
            scanf("%d", &len);
            printf("enter first node data:");
            scanf("%d",&num);
            newnode->link = NULL; newnode->data= num;
            for(int i =0;i<len-1;i++)
            {
                printf("Enter element:");
                scanf("%d",&num);
                create(num, newnode);
            }
            break;
        }
        // case 2:
        //     int num, pos;
        //     printf("Enter node to be added and at which position: ");
        //     scanf("%d %d", )
        case 4:
        {
            struct node *temp1 = newnode;
            while(temp1 != NULL)
            {
                printf("%d\t", temp1->data);
                temp1 = temp1->link;
            }
        }
        default:
            return 0;
    }
    }
}