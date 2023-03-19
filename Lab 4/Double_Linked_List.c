#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
void insertend(int item, struct node *head)
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

void insertpos(int item, int pos, struct node* head)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    struct node* temphead = head;
    temp->data = item;
    if (temphead == NULL)
    {
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
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
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    int len, item, pos;
    printf("Enter number of elements:");
    scanf("%d",&len);
    printf("Enter the first element");
    scanf("%d", &item);
    head->prev = NULL;
    head->data = item;
    head->next = NULL;
    for(int i=0; i<len-1; i++)
    {
        printf("Enter the value of node:");
        scanf("%d", &item);
        insertend(item,head);
    }
    display(head);
    printf("Enter the value of node:");
    scanf("%d", &item);
    printf("Enter the position:");
    scanf("%d", &pos);
    insertpos(item, pos, head);
    display(head);
}