#include <conio.h>
#include <stdio.h>

struct bst{
struct bst *left;
int data;
struct bst *right;
};

void append(struct bst **,int );
int search(struct bst *,int);

main(){
struct bst *root=NULL;
int res,n,ts;//res for result //ts is toSearch //n is number
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
printf("SEARCH YOUR NODE:");
scanf("%d",&ts);
res=search(root,ts);
if(res==1)
    printf("Element Found in the Tree.");
else printf("Node NOT Found");


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


int search(struct bst *p,int x){
struct bst *temp;
if(p==NULL){
    return -1;

}
while(p!=NULL){
    if(p->data==x)
    return 1;
    if(p->data >x)
        p=p->left;
    else
        p=p->right;
}
return 0;

}
