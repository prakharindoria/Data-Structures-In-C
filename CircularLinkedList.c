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
    struct cnode *start=NULL;int choice;
    printf("Circular Linked List : ");
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    append(&start,60);
    append(&start,70);
    append(&start,80);
    append(&start,90);
    append(&start,100);
    display(start);
    del_first(&start);
    printf("\n\nAfter deletion first node : ");
    display(start);
    del_last(&start);
    printf("\n\nAfter deletion last node : ");
    display(start);
    printf("\n\nDelete the element of your choice: ");
    scanf("%d",&choice);
    del_any(&start,choice);
    printf("\n\nAfter deletion %d node : ",choice);
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

void del_any(struct cnode **ps,int x){//ps pointer to start
struct cnode *temp,*prev;
if((*ps)==NULL){
    printf("List is empty");
    return;
}
temp=*ps;
 if((*ps)->data==x){
        *ps=(*ps)->next;
            free(temp);printf("Node Deleted");
        return;

    }
    while(temp->next!=NULL && temp->data!=x)
    {prev=temp;
   temp=temp->next;
    }
    if(temp->data==x){
        prev->next=temp->next;
        free(temp);
        printf("Node Deleted");
    }
    else printf("Node not found");

}
