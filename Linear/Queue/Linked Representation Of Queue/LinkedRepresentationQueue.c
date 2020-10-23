#include <stdio.h>
#include <conio.h>

struct queue{
int data;
struct queue *next;
};

void insert(struct queue **,struct queue **,int);
int rem(struct queue **,struct queue **);

main(){
struct queue *front,*rear;
front=rear=NULL;
char ch;
int var;//count=0;
int r;

do{
    printf("Do you want to enter in Queue? (y/n) \n");
    scanf(" %c",&ch);
    if(ch=='n')
    break;
    printf("Enter element: ");
    scanf("%d",&var);
    insert(&front,&rear,var);
    //count=count+1;

}while(ch=='y');
printf("Popping:\n");

//while(count>0){
//printf("%d\n",rem(&front,&rear));
//count=count-1;
//}

do{
    r=rem(&front,&rear);
    if(r==-1)
        break;
    printf("%d\n",r);
}while(r);

}


void insert(struct queue **pf,struct queue **pr ,int x){
    struct queue *p;
    p=(struct queue *)malloc(sizeof(struct queue));

    if(p==NULL){
        printf("Queue Overflow");
        return;
    }
    p->data=x;
    p->next=NULL;

    if(*pf==NULL)
        *pf=p;
    else
    (*pr)->next=p;

    *pr=p;

}



int rem(struct queue **pf,struct queue **pr ){
struct queue *temp;
int x;
if(*pf==NULL){
    printf("Queue Underflow");
    return -1;

}
temp=*pf;
x=temp->data;
if(*pf==*pr)
    *pr=NULL;
*pf=temp->next;
free(temp);
return x;



}
