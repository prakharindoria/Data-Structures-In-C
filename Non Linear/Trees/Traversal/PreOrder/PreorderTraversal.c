//Tree Taversals
//1.Inorder 2.Preorder #.Postorder
#include<conio.h>
#include <stdio.h>

struct bst{
struct bst *left;
int data;
struct bst *right;
};

struct stack{
struct bst* arr[10];
int tos;
};


void append(struct bst **,int );
void push(struct stack *,struct bst *);
struct bst* pop(struct stack*);
void preorder(struct bst *);



main(){
struct bst *root=NULL;
int res,n;//res for result //n is number
char ch;//ch is choice
do{
    printf("Do You want to enter in Binary Search Tree?(y/n)");
    scanf("%c",&ch);//scanf( "%c",&ch); //A extra space can be used to eat enter. OR fflush(stdin) cam be used.
    if(ch!='y')break;
    printf("Enter Your Element: \n");
    scanf("%d",&n);
    fflush(stdin);
    append(&root,n);
}while(1);
printf("Preorder Traversal:");
preorder(root);
}

void append(struct bst **pr,int x){
struct bst *p,*temp,*prev;
p=(struct bst *)(malloc(sizeof(struct bst)));
p->data=x;
p->left=p->right=NULL;
if(*pr==NULL){
    *pr=p;
    return;

}
temp=*pr;
while(temp!=NULL){
    prev=temp;
    if(temp->data >x)
        temp=temp->left;
     else
        temp=temp->right;
}

if(prev->data >x)
    prev->left=p;
else
    prev->right=p;

}


void push(struct stack *s,struct bst *right){
    if(s->tos==9)
        {printf("stack overflow");return;}
    s->tos=s->tos+1;
    s->arr[s->tos]=right;
}


struct bst* pop(struct stack *s){
struct bst *res;
if(s->tos==-1)
{
    printf("Stack UnderFlow");return NULL;
}
res=s->arr[s->tos];
s->tos--;
return res;
}


void preorder(struct bst *p){
struct stack s;
if(p==NULL){
    printf("Tree Empty");return;
}
s.tos=-1;
push(&s,p);
while(s.tos!=-1){
    p=pop(&s);
    while(p!=NULL){
        printf("%d ",p->data);
        if(p->right!=NULL)
            push(&s,p->right);
        p=p->left;
    }


}


}










