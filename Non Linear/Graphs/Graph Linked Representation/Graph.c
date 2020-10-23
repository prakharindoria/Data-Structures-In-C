#include<stdio.h>
#include<stdlib.h>

struct edge{
   char data;
   struct edge *next;
};
struct node {
   char data;
   struct node *next;
   struct edge *enext;
};
void insertNode(struct node**,char);
void insertEdge(struct node*,char, char);
void display(struct node *);
void delNode(struct node**,char);
void delEdge(struct node*, char,char);
struct node* search(struct node*, char);


int main()
{
   struct node *start=NULL;
   int ch;
   char c1, c2;

   /*
   //Sample code
   insertNode(&start,'A');
   insertNode(&start,'B');
   insertNode(&start,'C');
   insertNode(&start,'D');
   insertNode(&start,'E');

   printf("All Nodes:\n");
   display(start);
   // B adjacent to A
   insertEdge(start,'A','B');
   insertEdge(start,'A','C');
   insertEdge(start,'A','D');
   insertEdge(start,'B','C');
   insertEdge(start,'D','C');
   insertEdge(start,'D','E');
   insertEdge(start,'E','C');

   printf("Graph is:\n");
   display(start);

   printf("Deleted B,E:\n");
   delEdge(start,'B','E');
   display(start);

   printf("Deleted A,D:\n");
   delEdge(start,'A','D');
   display(start);

   printf("\nDelete A");
   delNode(&start,'A');
   display(start);

   printf("\nDelete E");
   delNode(&start,'E');
   display(start);
   */

   printf("Welcome to Graph Operations");
   A:
   printf("\nEnter Operation:");
   printf("\n1.Add Node to Graph");
   printf("\n2.Create Adjacent Node of Vertex");
   printf("\n3.Delete Node/Vertex");
   printf("\n4.Delete Edge/Adj Node");
   printf("\n5.Display Graph");
   printf("\n6.Exit\n>>");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:{
         printf("\nEnter Node Name as a Char, i.e A,B..\n>>");
         scanf("\n%c",&c1);
         insertNode(&start,c1);
         break;
      }
      case 2:{
         printf("\nEnter Vertex/Node Name whose adj node you want to make\n>>");
         scanf("\n%c",&c1);
         printf("\nEnter new adj node name\n>>");
         scanf("\n%c",&c2);
         insertEdge(start,c1,c2);
         break;
      }
      case 3:{
         printf("\nWhich node you want to delete, i.e A,B..\n>>");
         scanf("\n%c",&c1);
         delNode(&start,c1);
         break;
      }
      case 4:{
         printf("\nEnter parent of that Adj Node, i.e A,B..\n>>");
         scanf("\n%c",&c1);
         printf("\nEnter Adj Node Name, i.e A,B..\n>>");
         scanf("\n%c",&c2);
         delEdge(start,c1,c2);
         break;
      }
      case 5:{
         printf("\n--------------\n");
         printf("Nodes\tAdj Nodes\n");
         display(start);
         printf("\n-------------\n");
         break;
      }
      case 6:{
         return 0;
      }
      default:
         printf("Wrong Choice!!");
   }
   fflush(stdin);
   goto A;

   return 0;
}

// insert new node
void insertNode(struct node **ps, char d)
{
   struct node *p, *temp;
   p=(struct node*)malloc(sizeof(struct node));
   p->next = NULL;
   p->enext = NULL;
   p->data = d;
   if(*ps == NULL)
   {
      *ps = p;
      return;
   }
   temp = *ps;
   while(temp->next != NULL)
      temp=temp->next;
   temp->next = p;
}

// add new adj node 'adj' to 'vert'
void insertEdge(struct node *s, char vert, char adj)
{
   struct edge *p, *temp;
   struct node *pv;

   // int isNode = isNode(s, adj);
   int isNode = 1;
   //pv is add of vert node
   pv = search(s, vert);
   if(pv == NULL || !isNode)
   {
      printf("Vertex Not Found!");
      return;
   }

   p=(struct edge*)malloc(sizeof(struct edge));
   p->next = NULL;
   p->data = adj;

   if(pv->enext == NULL)
   {
      pv->enext = p;
      return;
   }
   temp = pv->enext;
   while(temp->next != NULL)
      temp = temp->next;
   temp->next = p;
}

// Serach and return node vertex's addr
struct node* search(struct node *p, char x)
{
   while(p != NULL)
   {
      if(p->data == x)
         return p;
      p = p->next;
   }
   return NULL;
}

// Display full graph
void display(struct node *ps)
{
   struct edge *temp;
   if(ps == NULL)
   {
      printf("Empty Graph");
      return;
   }
   while(ps != NULL)
   {
      printf("\n %c  ", ps->data);
      temp = ps->enext;
      while(temp!=NULL)
      {
         printf("-> %c ", temp->data);
         temp=temp->next;
      }
      ps = ps->next;
   }
}

// Remove e edge node from v vertex node
void delEdge(struct node *s, char v, char e)
{
      struct edge *p,*prev;
      s = search(s,v);
      if(s == NULL || s->enext == NULL)
      {
         printf("\nNode not found");
         return;
      }
      p = s->enext;
      if(p->data==e)
      {
         s->enext=p->next;
         free(p);
         return;
      }

      while(p!=NULL)
      {
         if(p->data==e)
         {
            prev->next=p->next;
            free(p);
            return;
         }
         prev = p;
         p=p->next;
      }
      printf("\nEdge Not Found");
}

//Delete any node/vertex
void delNode(struct node **ps,char x)
{
   struct node *temp,*prev;
   if(*ps == NULL)
   {
      printf("\nEmpty Graph");
      return;
   }
   temp= *ps;
   if((*ps)->data == x)
   {
      *ps = (*ps)->next;
      free(temp);
      return;
   }
   while(temp!=NULL)
   {
      if(temp->data == x){
         prev->next = temp->next;
         free(temp);
         return;
      }
      prev = temp;
      temp = temp->next;
   }
   printf("\nNode not found");
}


