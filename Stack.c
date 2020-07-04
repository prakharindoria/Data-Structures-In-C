struct stack{
int tos;
int arr[5];
};

main(){
    int x;
    struct stack s;
    s.tos=-1;
    s.tos=s.tos+1;
    s.arr[s.tos]=10;
    s.tos=s.tos+1;
    s.arr[s.tos]=20;
    s.tos=s.tos+1;
    s.arr[s.tos]=30;
    s.tos=s.tos+1;
    s.arr[s.tos]=40;
    s.tos=s.tos+1;
    s.arr[s.tos]=50;

    x=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d ",x);
    x=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d ",x);
    x=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d ",x);
    x=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d ",x);
    x=s.arr[s.tos];
    s.tos=s.tos-1;
    printf("%d",x);






}
