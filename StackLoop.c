struct stack{
int tos;
int arr[5];

}

main(){
int i,x,y;
struct stack s;
s.tos=-1;
for(i=0;i<5;i++){
    printf("Enter a Number ");
    scanf("%d",&x);
    s.tos=s.tos+1;
    s.arr[s.tos]=x;
}
for(i=0;i<5;i++){
    y=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d ",y);
}



}
