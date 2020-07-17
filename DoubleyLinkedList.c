#include <conio.h>
#include <stdio.h>

struct Doubley{
int data;
struct Doubley *next,*prev;
};

void append(struct Doubley **,int);
void display(struct Doubley *);
void del_first(struct Doubley **);
void del_last(struct Doubley **);
void del_node(struct Doubley **,int);
main(){
    int toDelete;
struct Doubley *start=NULL;
append(&start,10);
append(&start,20);
append(&start,30);
append(&start,40);
append(&start,50);

display(start);
//Delete first node
del_first(&start);
printf("\nDisplaying after deleting first node\n");
display(start);

//Delete Last Node
del_last(&start);
printf("\nDisplaying after deleting Last node\n");
display(start);

//Delete Desired Node
printf("\nEnter Node to be deleted:");
scanf("%d",&toDelete);
del_node(&start,toDelete);
printf("\nDisplaying after deleting the desired node\n");
display(start);



}

void append(struct Doubley **ps,int x){
struct Doubley *p,*temp;
p=(struct Doubley *)malloc(sizeof(struct Doubley));
p->data=x;
p->next=NULL;

if(*ps==NULL){
    *ps=p;
    return;
}
temp=*ps;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=p;
p->prev=temp;
}



void display(struct Doubley *p){
if(p==NULL){
    printf("List Empty");

}
while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
}
}



void del_first(struct Doubley **ps){
struct Doubley *temp;
if(*ps==NULL)
{
    printf("List Empty");
    return;
}
if((*ps)->next==NULL)
{
    free(*ps);
    *ps=NULL;
    return;
}

temp=*ps;
*ps=temp->next;
free(temp);
(*ps)->prev==NULL;


}


void del_last(struct Doubley **ps){
struct Doubley *temp;
if(*ps==NULL)
{
    printf("List Empty");
    return;
}
if((*ps)->next==NULL)
{
    free(*ps);
    *ps=NULL;
    return;
}
temp=*ps;
while(temp->next != NULL){
    temp=temp->next;

}
(temp->prev)->next=NULL;
free(temp);


}


void del_node(struct Doubley **ps,int x ){
    struct Doubley *temp,*p;
    if(*ps==NULL){
        printf("List Empty");return;
    }
    temp=*ps;
    if((*ps)->data==x){
        free(ps);
        printf("Node found at first position and deleted  ");
        *ps=(*ps)->next;
        return;
    }

    while(temp!=NULL && temp->data!=x){
       p=temp;
       temp=temp->next;

    }
    if(temp==NULL){
        printf("Node Not Found  ");
    }
    else{
        p->next=temp->next;
        free(temp);
        printf("Node Deleted  ");
    }
}

