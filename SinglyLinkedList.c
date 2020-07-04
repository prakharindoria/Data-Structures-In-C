#include <conio.h>
#include <stdio.h>
struct node{
int data;
struct node *next;
};

void append(struct node**,int);
int display(struct node*);
int countnodes(struct node*);
int search(struct node*,int);

void main(){
struct node * start=NULL;
int noOfNodes;
char c;
int x;
int ts,sr;
do{
printf("Do you want to enter in Linked List:");
scanf(" %c",&c);
if(c=='n')
    break;
printf("Enter your number:");
scanf("%d",&x);
append(&start,x);
printf("%d inserted\n");
}while(c=='y');
printf("\nYour List: ");
display(start);
noOfNodes=countnodes(start);
printf("\nNumber Of Nodes: %d",noOfNodes);

printf("\nSearch Your Node: ");
scanf("%d",&ts);
sr=search(start,ts);
printf("Your Number is at Position : %d",sr);
getch();
}


void append(struct node **ps,int x){
struct node *p,*temp;
p=(struct node *)malloc(sizeof(struct node));
p->data=x;
p->next=NULL;
if(*ps==NULL)
{
    *ps=p;
    return;
}
temp=*ps;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=p;
}


int search(struct node *p,int x){
    int res=1;

if(p==NULL){
    printf("List empty");
    return;
}
while(p!=NULL){
        if(x==p->data)
        return res;
        else
        {p=p->next;
        res=res+1;}


}
return -1;


}


int display(struct node *p){

if(p==NULL){

    printf("List empty");
    return;
}
while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;


}


}



int countnodes(struct node *p){
int res=0;
while(p!=NULL){
    res=res+1;
    p=p->next;
}
return res;

}
