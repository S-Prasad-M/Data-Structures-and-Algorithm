#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
void display(struct node* head)
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

void create(int item, struct node* head)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    struct node* temphead = head;
    while (temphead->next != NULL )
    {
        temphead = temphead->next;
    }
    temphead->next = temp;
    temp->data = item;
    temp->prev = temphead;
}
void insertatpos(int item, struct node* head, int pos)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    struct node* temphead = head;
    struct node* temp2 = NULL;
    temp->data = item;
    temp->next = NULL;
    while(pos != 1);
    {
        temphead = temphead->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        temphead->next = temp;
        temp->prev = temphead;
    }
    else{
        temp2 = temphead -> next;
        temphead->next = temp;
        temp2->prev = temp;
        temp->next = temp2;
        temp->prev = temphead;
        // temp->prev = temphead;
        // temp->next = temphead->next;
        // temphead->next->prev = temp;
        // temphead->next = temp;
    }
}
void main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    int len, num, pos;
    printf("Enter number of elements:");
    scanf("%d", &len);
    printf("Enter first node:");
    scanf("%d", &num);
    head->prev = NULL;
    head->data = num;
    head->next = NULL;
    for(int i=0; i<len-1;i++)
    {
        printf("Enter node:");
        scanf("%d", &num);
        create(num, head);
    }
    display(head);
    printf("Enter node and pos:");
    scanf("%d %d", &num, &pos);
    insertatpos(num, head, pos);
    display(head);
}