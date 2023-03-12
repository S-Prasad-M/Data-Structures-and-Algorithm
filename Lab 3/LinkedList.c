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
    while(temphead->link != NULL){
        temphead = temphead->link;
    }
    temphead->link = temp;
    temp->data=num;
    temp->link = NULL;
}
void main()
{
    int len, num;
    struct node *newnode = (struct node*)malloc(sizeof(struct node*));
    //struct node *newnode2 = (struct node*)malloc(sizeof(struct node*));
    // struct node *newnode3 = (struct node*)malloc(sizeof(struct node*));
    // struct node *newnode4 = (struct node*)malloc(sizeof(struct node*));
    // struct node *newnode5 = (struct node*)malloc(sizeof(struct node*));
    newnode->link = NULL; newnode->data= 10;
    struct node *temp1 = newnode;
    // newnode2->link = newnode3; newnode2->data= 20;
    // newnode3->link = newnode4; newnode3->data= 30;
    // newnode4->link = newnode5; newnode4->data= 40;
    // newnode5->link = NULL; newnode5->data= 50;
    
    printf("Enter number of nodes:");
    scanf("%d", &len);
    for(int i =0;i<len;i++)
    {
        printf("Enter element:");
        scanf("%d",&num);
        create(num, newnode);
    }
    while(temp1 != NULL)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->link;
    }
}