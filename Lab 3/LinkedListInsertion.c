#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
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

void insert (int num, int pos, struct node *head)
{
    struct node *temphead = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    for(int i =0; i<pos-2; i++)
    {
        temphead = temphead->link;
    }
    temp->data = num;
    temp->link = temphead->link;
    temphead->link = temp;
}

void delete(int pos, struct node *head)
{
    struct node *temphead = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    for(int i =0; i<pos-2; i++)
    {
        temphead = temphead->link;
    }
    ;
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
        case 2:
        {
            int ch, num, pos;
            printf("1.Beggining \n2. At position \n3. At end \n Enter Choice: ");
            scanf("%d", &ch);
            switch(ch)
            {
                case  1:
                {
                    printf("Enter node to be added");
                    scanf("%d", &num);
                    insert(num, 0, newnode);
                    break;
                }
                case 2:
                {
                    printf("Enter node to be added and at which position: ");
                    scanf("%d %d", &num, &pos);
                    insert(num, pos, newnode);
                    break;
                }
                case 3:
                {
                    printf("Enter node to be added");
                    scanf("%d", &num);
                    create(num, newnode);
                    break;
                }
            }
            break;
        }
        case 3:
        {   
                int pos;
                printf("Enter the positionb to be deleted");
                scanf("%d", &pos);
                delete(pos);
        }
        case 4:
        {
            struct node *temp1 = newnode;
            while(temp1 != NULL)
            {
                printf("%d\t", temp1->data);
                temp1 = temp1->link;
            }
            break;
        }
        default:
            return 0;
    }
    }
}
