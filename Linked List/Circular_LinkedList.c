#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
typedef struct node clist;
void create(clist **head);
void print(clist *head);
void insert_beg(clist **head);
void insert_end(clist **head);
void insert_pos(clist **head);
void delete_begin(clist **head);
void delete_end(clist **head);
void delete_pos(clist **head);
int main(){
    int ans;
    clist *head;
    create(&head);
    print(head);
    do{
        printf("Select the operation you want to perform\n");
        printf("1.insert node in the beginning\n");
        printf("2.insert node in the end\n");
        printf("3.insert node in the given position\n");
        printf("4.deletion of node from beginning\n");
        printf("5.deletion of node from end\n");
        printf("6.deletion of node from given pos\n");
         printf("0.exit\n");
         scanf("%d",&ans);
        switch (ans){
            case 1:
                insert_beg(&head);
                print(head);
                break;
            case 2:
                insert_end(&head);
                print(head);
                break;
            case 3:
                insert_pos(&head);
                print(head);
                break;
            case 4:
                delete_begin(&head);
                print(head);
                break;
            case 5:
                delete_end(&head);
                print(head);
                break;
            case 6:
                delete_pos(&head);
                print(head);
                break;
            case 0:
                break;
        }
    }while(ans!=0);
}
void create(clist **head){
    int ans;
    clist *tmp=*head;
    clist *p;
    int c=0;
    printf("do you want to enter elemetnt[0/1] : ");
    scanf("%d",&(ans));
    while(ans){
        c++;
        p=(clist*)malloc(sizeof(clist));
        printf("enter the element : ");
        scanf("%d",&(p->val));
        p->next=NULL;
        if(c>1){
        tmp->next=p;
        }else{
            p->next=NULL;
            *head=p;
        }
        tmp=p;
        printf("do you want to enter elemetnt[0/1] : ");
        scanf("%d",&(ans));
    }
    tmp->next=*head;
}
void print(clist *head){
    clist *tmp=head;
    clist *p=head;
    printf("-----------------------\n");
    do{
        printf("%d ",(p->val));
        p=p->next;
    }while(p!=tmp);
    printf("\n-----------------------\n");
}
void insert_beg(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    clist *t=(clist*)malloc(sizeof(clist));
    printf("enter the new elemnt\n");
    scanf("%d",&(t->val));
    t->next=NULL;
    if(p!=NULL){
    while(p->next!=tmp){
        p=p->next;
    }
    p->next=t;
    t->next=tmp;
    *head=t;
}
    else{
        *head=tmp;
        tmp->next=tmp;
    }
}
void insert_end(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    clist *t=(clist*)malloc(sizeof(clist));
    printf("enter the new elemnt\n");
    scanf("%d",&(t->val));
    t->next=NULL;
    if(p!=NULL){
    while(p->next!=tmp){
        p=p->next;
    }
    p->next=t;
    t->next=tmp;
    }
    else{
        *head=tmp;
        tmp->next=tmp;
    }
}
void insert_pos(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    int n;
    printf("enter the position of the new element\n");
    scanf("%d",&(n));
    clist *t=(clist*)malloc(sizeof(clist));
    printf("enter the new elemnt\n");
    scanf("%d",&(t->val));
    t->next=NULL;
    if(p!=NULL){//if the list is not empty
        for(int i=1;i<n-1;i++){
            p=p->next;
        }
        if(p->next!=NULL){
             t->next=p->next;
        }
        else{//if the new element is to be inserted in the end
             t->next=NULL;
        }
        p->next=t;
    }
    else{//if no other element is present
        *head=tmp;
        tmp->next=tmp;
    }
}
void delete_begin(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    if(p==NULL){
        return;
    }
    while(p->next!=tmp){
        p=p->next;
    }
    p->next=p->next->next;
    *head=tmp->next;
    free(tmp);

}
void delete_end(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    if(p==NULL){
        return;
    }
    while(p->next->next!=tmp){
        p=p->next;
    }
    tmp=p->next;
    p->next=tmp->next;
    free(tmp);
}
void delete_pos(clist **head){
    clist *p=*head;
    clist *tmp=*head;
    int n;
    printf("enter the position you want to delete\n");
    scanf("%d",&(n));
    if(p==NULL){
        return;
    }
    for (int i=1;i<n-1;i++){
        p=p->next;
    }
    tmp=p->next;
    p->next=tmp->next;
    free(tmp);
}
