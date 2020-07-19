#include <stdio.h>
#include <conio.h>

struct stack{
int data;
struct stack *next;
};


void push(struct stack **,int);
int pop(struct stack **);


main(){
    struct stack *tos=NULL;
    int i,x;
    printf("Push in Stack\n");
    for(i=0;i<5;i++){
        printf("Enter Number at %d Position : ",(i+1));
        scanf("%d",&x);
        push(&tos,x);
    }
    printf("\nPopping\n");
    for(i=0;i<5;i++){
        printf("%d\n",pop(&tos));
    }
}


void push(struct stack **ptos,int x){
struct stack *p;
p=(struct stack *)malloc(sizeof(struct stack));
if(p==NULL){
    printf("Stack OverFlow");
    return;
}
p->data=x;
p->next=*ptos;
*ptos=p;

}


int pop(struct stack **ptos){
struct stack *temp;
int x;
if(*ptos==NULL){

    printf("Stack Undeflow");
    return;
}
x=(*ptos)->data;
temp=*ptos;
*ptos=(*ptos)->next;
free(temp);
return x;

}

