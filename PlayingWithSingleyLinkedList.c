//SingleyLinkedList implementation form Scratch 
//Prakhar Indoria

#include <conio.h>
#include <stdio.h>
struct node{
int data;
struct node *next;
};

void append(struct node**,int); //Method to add new element in LL.
int display(struct node*);  //Method to show all elements of LL.
int countnodes(struct node*);   //Count No. Of Nodes.
int search(struct node*,int);   //Search a specific element.
void del_last(struct node **);  //Delete from last of LL
void del_node(struct node **,int);  //Delete any element of LL
 
void main(){
struct node * start=NULL;
int noOfNodes;
char c; // c stands for Choice, To take user input weather user wants to continue entering elements in LL
int x;  // Element
int ts,sr,toDelete; //ts represents toSearch, sr represents searchResult , toDelete is the element to Delete from the LL
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
del_last(&start);
printf("\nDeleting The Last Node,New List Is: ");
display(start);

printf("\nEnter node to delete: ");
scanf("%d",&toDelete);
del_node(&start,toDelete);
printf("\nDeleting %d Now New List Is: ",toDelete);
display(start);



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

void del_last(struct node **ps){
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




void del_node(struct node **ps,int x )
{
    struct node *temp,*prev;
    if(*ps==NULL){
        printf("List Empty");return;
    }
    temp=*ps;
    if((*ps)->data==x){
        free(ps);
        printf("Node at found at first position and deleted");
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
