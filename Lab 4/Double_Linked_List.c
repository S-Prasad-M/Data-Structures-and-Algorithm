#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
void create(int item, struct node *head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    struct node* temphead = head;
    temp->data = item;
    temp->next = NULL;
    if (temphead == NULL)
    {
        head = temp;
        temp->prev = NULL;
    }
    else
    {
        while(temphead->next != NULL)
        {
            temphead = temphead->next;
        }
        temp->prev = temphead;
        temphead->next = temp;
    }
}

int length(struct node* head)
{
    struct node* temphead = head;
    int l = 0;
    while (temphead != NULL)
    {
        temphead = temphead->next; l++;
    }
    return l;
}

void insertpos(int item, int pos, struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    struct node* temphead = head;
    temp->data = item;
    if (pos == 1)
    {
        temp->prev = NULL;
        temp->next = temphead;
        temphead->prev = temp;
        temphead = temp;
    }
    else if(pos>1 && pos<length(head))
    {
        while(pos-1 != 1)
        {
            temphead = temphead->next;
            pos--;
        }
        temp->prev=temphead;
        temp->next=temphead->next;
        temphead->next->prev = temp;
        temphead->next = temp;
    }
    else
    {
        while(temphead->next != NULL)
        {
            temphead = temphead->next;
        }
        temp->prev = temphead;
        temphead->next = temp;
    }
}

void delete(int pos, struct node* head)
{
    struct node* temphead = head;
    while(pos-1 != 1)
    {
            temphead = temphead->next;
            pos--;
    }
    temphead->next->next->prev = temphead;
    temphead->next = temphead->next->next;
}
void display(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int choice;
    int num, len;
    struct node *head = (struct node*)malloc(sizeof(struct node*));
    // printf("1.Create \n2. Insert \n3. Delete \n4.Display \n Enter Choice: ");
    // scanf("%d", &choice);
    while (1)
    {
    printf("\n1.Create \n2. Insert \n3. Delete \n4.Display \n Enter Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter number of nodes:");
            scanf("%d", &len);
            printf("enter first node data:");
            scanf("%d",&num);
            head->next = NULL; 
            head->data= num;
            head->prev = NULL;
            for(int i =0;i<len-1;i++)
            {
                printf("Enter element:");
                scanf("%d",&num);
                create(num, head);
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
                    insertpos(num, 1, head);
                    break;
                }
                case 2:
                {
                    printf("Enter node to be added and at which position: ");
                    scanf("%d %d", &num, &pos);
                    insertpos(num, pos, head);
                    break;
                }
                case 3:
                {
                    printf("Enter node to be added");
                    scanf("%d", &num);
                    create(num, head);
                    break;
                }
            }
            break;
        }
        case 3:
        {   
                int pos;
                printf("Enter the position to be deleted");
                scanf("%d", &pos);
                delete(pos, head);
        }
        case 4:
        {
            display(head);
            break;
        }
        default:
            return 0;
    }
    }
}
