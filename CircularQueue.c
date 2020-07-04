//Circular Queue
struct Queue{
int arr[7];
int rear,front;
};

void insert(struct Queue *,int);
int remove(struct Queue *);

void main(){

    int i,x;
    struct Queue q;
    q.front=0;
    q.rear=-1;

    for(int i=0;i<4;i++){
        printf("Enter element:");
        scanf("%d",&x);
        insert(&q,x);
        }

    for(int i=0;i<4;i++){
        x=remove(&q);
        if(x!=-1)
            printf("\n Removed= %d  ",x);
        }





}
void insert(struct Queue *q,int x){
if(((q->rear+1)%5==q->front))//||(q->rear==4 && q->front==0))
    printf("Queue Overflow");


if(q->rear==4)
    q->rear=0;
else
    {q->rear=q->rear+1;
    q->arr[q->rear]=x;}


if(q->front==-1)
q->front=0;return;

}


int remove(struct Queue *q){
int x;
if(q->front==-1)
{printf("Queue Underflow");return;}

x=q->arr[q->front];

if(q->front==q->rear)
    q->front=q->rear=-1;

else if(q->front==4)
    q->front==0;

else
    q->front=q->front+1;
    return x;

}





