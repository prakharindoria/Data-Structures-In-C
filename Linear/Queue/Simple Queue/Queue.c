struct Queue{
int arr[7];
int rear,front;
};

void insert(struct Queue *,int);
int delete(struct Queue *);
void show(struct Queue);

void main(){

    int i,x;
    struct Queue q;
    q.front=0;//We delete from  front
    q.rear=-1;// We insert at rear

    for(int i=0;i<7;i++){
        printf("Enter element:");
        scanf("%d",&x);
        insert(&q,x);
        }
        printf("\nShowing Queue: \n");
        show(q);
        printf("\n");

    for(int i=0;i<7;i++){
        x=remove(&q);
        if(x!=-1)
            printf("\n Removed= %d  ",x);
        }
}

void insert(struct Queue *q,int x){
if(q->front==7)
    {printf("Queue Overflow");return;}
    q->rear=q->rear+1;// or (*q).rear=((*q).rear)+1
q->arr[q->rear]=x;
printf("Rec Inserted %d \n",x);
}


int remove(struct Queue *q){
int x;
if(q->rear < q->front){
    printf("\n Queue Underflow");return -1;}

x=q->arr[q->front];
q->front=q->front+1;
return x;

}

void show(struct Queue u){
int i=0;
for(i=0;i<7;i++){
    printf("%d ",u.arr[i]);


}
}





































