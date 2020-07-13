#include <conio.h>
#include <stdio.h>

struct Doubley{
int data;
struct Doubley *next,*prev;
};

void append(struct Doubley **,int);
void display(struct Doubley *);
main(){
struct Doubley *start=NULL;
append(&start,10);
append(&start,20);
append(&start,30);
append(&start,40);
append(&start,50);

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
