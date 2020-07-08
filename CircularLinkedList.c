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
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    display(start);
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
    printf("\n%d",temp->data);
    temp=temp->next;
}while(temp!=p);
}
