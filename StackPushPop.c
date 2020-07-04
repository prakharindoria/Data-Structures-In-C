struct stack{
int tos;
int arr[5];
}

//void push(struct stack *,int );
//int pop(struct stack *);
main(){
int i,x,y;
struct stack s;
s.tos=-1;
for(i=0;i<5;i++){
    printf("\n Enter a Number \n");
    scanf("%d",&x);
    push(&s,x);
}
for(i=0;i<5;i++){
    y=pop(&s);
    if(y != -1)
        printf("\n Popped %d",y);

}
}

void push(struct stack *p,int x){
if(p->tos==4)
{printf("Stack OverFlow");return;}
p->tos=p->tos+1;
p->arr[p->tos]=x;
printf("\n Pushed %d",x);
}

int pop(struct stack *q){
    int res;
if(q->tos==-1)
    {printf("Stack UnderFlow");return -1;}
res=q->arr[q->tos];
q->tos=q->tos-1;
return res;

}
