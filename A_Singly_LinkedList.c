#include <conio.h>
#include <stdio.h>
struct node{
int data;
struct node *next;
};


//Declarations:
void append(struct node**,int);
int display(struct node*);
int countnodes(struct node*);
int search(struct node*,int);
void del_last(struct node **);
void del_node(struct node **,int);
//whenever changes are needed in the LL ,doubley pointers ares used // For just traversing singley pointer is used

void main(){
struct node *start=NULL;//external pointer start
char c;//c for choice
int noOfNodes,x,ts,sr,toDelete;//x for data from user //ts is toSearch //sr is searchedIndex
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

{//Show LL Elements
printf("\nYour List: ");
display(start);
noOfNodes=countnodes(start);
printf("\nNumber Of Nodes: %d",noOfNodes);
}

{//Searching specific node.
printf("\nSearch Your Node: ");
scanf("%d",&ts);
sr=search(start,ts);
printf("Your Number is at Position : %d",sr);}

{//Deleting Element from the last
del_last(&start);
printf("\nDeleting The Last Node,New List Is: ");
display(start);}

{//Deleting a specific element by asking for its value from user.
printf("\nEnter node to delete: ");
scanf("%d",&toDelete);
del_node(&start,toDelete);
printf("\nDeleting %d Now New List Is: ",toDelete);
display(start);
getch();}
}


void append(struct node **ps,int x){
//One of the primary reason we use doubley pointer is that we have make changes in the start pointer too(which is an external pointer)...
//for instance we have to insert in first node,then we have change NULL that is kept in start pointer.( start==NULL in the main)
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


void del_last(struct node **ps){
//We used doubley pointer because the last node we are deleting can also be the only node in LL.
//In that case we have to make changes in the start pointer. Hence Doubley.
struct node *prev,*temp;
if(*ps==NULL)
{printf("List Empty");return;}
if((*ps)->next==NULL){
    free(*ps);
    *ps=NULL;
    return;
}
temp=*ps;
while(temp->next!=NULL)
{
    prev=temp;
    temp=temp->next;

}
free(temp);
prev->next=NULL;

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


void del_node(struct node **ps,int x ){
    struct node *temp,*prev;
    if(*ps==NULL){
        printf("List Empty");return;
    }
    temp=*ps;
    if((*ps)->data==x){
        free(ps);
        printf("Node found at first position and deleted");
        return;
    }

    while(temp!=NULL && temp->data!=x){
       prev=temp;
       temp=temp->next;

    }
    if(temp==NULL){
        printf("Node Not Found");
    }
    else{
        prev->next=temp->next;
        free(temp);
        printf("Node Deleted");
    }
}
