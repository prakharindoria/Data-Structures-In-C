#include<conio.h>
#include<stdio.h>

struct cnode{
int data;
struct cnode *next;
};

void append(struct cnode **,int);
void display(struct cnode *);

void main()
{
    struct cnode *start=NULL;
    printf("Circular Linked List : ");
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    display(start);
    del_first(&start);
    printf("\n\nAfter deletion first node : ");
    display(start);
    del_last(&start);
    printf("\n\nAfter deletion last node : ");
    display(start);
    getch();
}


void append(struct cnode **ps,int x ){
struct cnode *p,*temp;
p=(struct cnode *)malloc(sizeof(struct cnode));
p->data=x;

if(*ps==NULL)
{
    *ps=p;
    p->next=p;
    return;
}
temp=*ps;
while(temp->next!=*ps)
{
    temp=temp->next;
}
    temp->next=p;
    p->next=*ps;
}

void display(struct cnode *p){
struct cnode *temp;
if(p==NULL){
    printf("List is empty");
    return;
}
temp=p;
do{
    printf(" %d",temp->data);
    temp=temp->next;
}while(temp!=p);
}


void del_first(struct cnode **ps){
struct cnode *temp;
if((*ps)==NULL){
    printf("List is empty");
    return;
}
if((*ps)->next==(*ps)){
    free(*ps);
    *ps=NULL;
    return;


}
else
{
    temp=*ps;
    while(temp->next!=*ps){
        temp=temp->next;

    }
    temp->next=(*ps)->next;
    free(*ps);
    *ps=temp->next;
}


}


void del_last(struct cnode **ps){
struct cnode *temp,*prev;
if((*ps)==NULL){
    printf("List is empty");
    return;
}
if((*ps)->next==(*ps)){
    free(*ps);
    *ps=NULL;
    return;


}
else
{
    temp=*ps;
    while(temp->next!=*ps){
            prev=temp;
        temp=temp->next;

    }
    free(temp);
    prev->next=*ps;

}


}

